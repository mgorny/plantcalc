/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "substance.hxx"
#include "system.hxx"
#include "exceptions/nonhomogeneoussubstanceerror.hxx"

#include <map>
#include <typeinfo>
#include <vector>

System::System()
{
}

bool System::flattened_connections_set() const
{
	return !_flattened_connections.empty() || _connections.empty();
}

void System::push_back(Device& dev)
{
	_devices.push_back(&dev);

	if (flattened_connections_set()) // XXX
		_flattened_connections.clear();
}

void System::push_back(Connection& conn)
{
	// This check must be performed *before* appending.
	if (flattened_connections_set())
		_flattened_connections.push_back(&conn);

	_connections.push_back(&conn);
}

void System::flatten()
{
	_flattened_connections = _connections;

	const device_list& devs = _devices;

	for (device_list::const_iterator it = devs.begin();
			it != devs.end(); ++it)
	{
		Device& d = **it;
		const Device::connection_list_type& ic = d.internal_connections();

		// XXX: implement +=
		_flattened_connections.insert(_flattened_connections.end(),
				ic.begin(), ic.end());
	}
}

void System::set_device_ids()
{
	std::map<const char*, int> device_numbering_table;

	for (device_list::iterator it = _devices.begin();
			it != _devices.end(); ++it)
	{
		Device& d = **it;
		DeviceID& id = d.device_id();

		int new_num = ++device_numbering_table[id.name()];

		id.num(new_num);
	}
}

void System::set_substances()
{
	connection_group_list groups = grouped_connections();

	for (connection_group_list::iterator it = groups.begin();
			it != groups.end(); ++it)
	{
		connection_list& group = *it;
		const Substance* group_substance = 0;

		for (connection_list::iterator gt = group.begin();
				gt != group.end(); ++gt)
		{
			Connection& c = **gt;
			const Substance* subst = c.substance();

			if (subst)
			{
				if (!group_substance)
				{
					group_substance = subst;

					// set earlier ones
					for (connection_list::iterator jt = group.begin();
							jt != gt; ++jt)
					{
						Connection& c2 = **jt;

						if (!c2.substance())
							c2.substance(group_substance);
					}
				}
				else if (subst != group_substance)
					throw NonHomogeneousSubstanceError();
			}
			else if (group_substance)
				c.substance(group_substance);
		}
	}
}

EquationSystem System::equations() const
{
	EquationSystem eqs;

	for (device_list::const_iterator it = _devices.begin();
			it != _devices.end(); ++it)
	{
		Device& d = **it;

		eqs += d.equations();
	}

	const connection_list& conns = flattened_connections();
	for (connection_list::const_iterator it = conns.begin();
			it != conns.end(); ++it)
	{
		Connection& c = **it;

		eqs += c.equations();
	}

	return eqs;
}

const System::device_list& System::devices() const
{
	return _devices;
}

const System::connection_list& System::connections() const
{
	return _connections;
}

const System::connection_list& System::flattened_connections() const
{
	if (!flattened_connections_set())
		return _connections;

	return _flattened_connections;
}

System::connection_group_list System::grouped_connections() const
{
	std::map<const DeviceID*, Device*> device_map;

	for (device_list::const_iterator it = _devices.begin();
			it != _devices.end(); ++it)
	{
		Device& d = **it;
		DeviceID& id = d.device_id();

		device_map[&id] = &d;
	}

	connection_list ungrouped_connections(flattened_connections());

	connection_group_list ret;

	while (ungrouped_connections.size() > 0)
	{
		ret.push_back(connection_list());
		connection_list& group = ret.back();

		group.push_back(ungrouped_connections.back());
		ungrouped_connections.pop_back();

		// can't use an iterator here because we're appending
		for (connection_list::size_type i = 0; i < group.size(); ++i)
		{
			Connection* c = group[i];

			const DeviceID* ldev_id = &c->from().pin_id().device_id();
			Device& ldev = *device_map[ldev_id];

			const DeviceID* rdev_id = &c->to().pin_id().device_id();
			Device& rdev = *device_map[rdev_id];

			for (connection_list::iterator it = ungrouped_connections.begin();
					it != ungrouped_connections.end();)
			{
				Connection* c2 = *it;
				Pin* lpin = 0;
				Pin* rpin = 0;

				if (&c2->from().pin_id().device_id() == ldev_id)
					lpin = &c2->from();
				else if (&c2->to().pin_id().device_id() == ldev_id)
					lpin = &c2->to();

				if (lpin && ldev.pins_connected(*lpin, c->from()))
				{
					group.push_back(c2);
					it = ungrouped_connections.erase(it);
					continue;
				}

				if (&c2->from().pin_id().device_id() == rdev_id)
					rpin = &c2->from();
				else if (&c2->to().pin_id().device_id() == rdev_id)
					rpin = &c2->to();

				if (rpin && rdev.pins_connected(*rpin, c->to()))
				{
					group.push_back(c2);
					it = ungrouped_connections.erase(it);
					continue;
				}

				++it;
			}
		}
	}

	return ret;
}

std::ostream& operator<<(std::ostream& f, const System& s)
{
	std::map<Pin*, Pin*> conn_map;

	for (System::connection_list::const_iterator it = s._connections.begin();
			it != s._connections.end(); ++it)
	{
		Connection& c = **it;

		conn_map[&c.from()] = &c.to();
		conn_map[&c.to()] = &c.from();
	}

	f << "---";

	for (System::device_list::const_iterator dt = s._devices.begin();
			dt != s._devices.end(); ++dt)
	{
		Device& dev = **dt;

		f << "\n\n" << dev.device_id() << ":";

		Device::variable_list_type vars = dev.variables();
		Device::pin_list_type pins = dev.pins();

		for (Device::variable_list_type::iterator it = vars.begin();
				it != vars.end(); ++it)
		{
			OwnedVariable& v = **it;

			f << "\n  " << v.variable_id().name() << ": " << v.value();
		}

		for (Device::pin_list_type::iterator it = pins.begin();
				it != pins.end(); ++it)
		{
			Pin& pin = **it;
			Pin* pair = conn_map[&pin];

			f << "\n  " << pin.pin_id().name() << ":";
			if (pair)
				f << " # -> " << pair->pin_id();

			Pin::variable_list_type lvars = pin.variables();
			for (Pin::variable_list_type::iterator vt = lvars.begin();
					vt != lvars.end(); ++vt)
			{
				OwnedVariable& v = **vt;

				f << "\n    " << v.variable_id().name() << ": " << v.value();
			}
		}
	}

	return f;
}

std::ostream& operator<<(std::ostream& f, const System::connection_list& cl)
{
	typedef std::map<const char*, System::connection_list> connection_group_map;
	connection_group_map cgmap;

	for (System::connection_list::const_iterator it = cl.begin();
			it != cl.end(); ++it)
	{
		Connection& c = **it;

		cgmap[typeid(c).name()].push_back(&c);
	}

	for (connection_group_map::iterator it = cgmap.begin();
			it != cgmap.end(); ++it)
	{
		const char* type_name = it->first;
		System::connection_list gl = it->second;

		bool first = true;

		for (System::connection_list::iterator jt = gl.begin();
				jt != gl.end(); ++jt)
		{
			Connection& c = **jt;
			Pin::variable_list_type vi = c.from().variables();

			if (first)
			{
				f << "\n\n" << type_name;

				for (Pin::variable_list_type::iterator vt = vi.begin();
						vt != vi.end(); ++vt)
				{
					OwnedVariable& v = **vt;

					f << "\t" << v.variable_id().name();
				}

				first = false;
			}

			f << "\n" << c.from().pin_id() << " -> " << c.to().pin_id();

			for (Pin::variable_list_type::iterator vt = vi.begin();
					vt != vi.end(); ++vt)
			{
				Variable& v = **vt;

				f << "\t" << v.value();
			}
		}
	}

	return f;
}

const System::graph_generator System::graph() const
{
	return graph_generator(*this);
}

System::graph_generator::graph_generator(const System& s)
	: _s(s)
{
}

std::ostream& operator<<(std::ostream& f, const System::graph_generator g)
{
	const System& s = g._s;
	System::connection_group_list groups = s.grouped_connections();

	f << "digraph system\n"
		"{\n"
		"\tedge\n"
		"\t[\n"
		"\t\tcolorscheme = \"dark28\"\n"
		"\t];\n"
		"\n";

	int color = 1;

	for (System::connection_group_list::iterator gt = groups.begin();
			gt != groups.end(); ++gt)
	{
		System::connection_list& conns = *gt;

		for (System::connection_list::iterator it = conns.begin();
				it != conns.end(); ++it)
		{
			Connection& c = **it;

			f << "\t" << c.from().pin_id().device_id()
				<< " -> " << c.to().pin_id().device_id() << "\n"
				"\t[\n"
				"\t\tcolor = \"" << color << "\",\n"
				"\t\tlabel = \"\\E";

			Pin::variable_list_type vi = c.from().variables();

			for (Pin::variable_list_type::iterator vt = vi.begin();
					vt != vi.end(); ++vt)
			{
				OwnedVariable& v = **vt;

				f << "\\n" << v.variable_id().name() << " = " << v.value();
			}

			f << "\"\n"
				"\t];\n";
		}

		++color;
	}

	f << "}";

	return f;
}
