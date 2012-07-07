/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "system.hxx"

#include <map>

System::System()
{
}

void System::push_back(Device& dev)
{
	_devices.push_back(&dev);
}

void System::push_back(Connection& conn)
{
	_connections.push_back(&conn);
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

EquationSystem System::equations()
{
	EquationSystem eqs;

	for (device_list::iterator it = _devices.begin();
			it != _devices.end(); ++it)
	{
		Device& d = **it;

		eqs += d.equations();
	}

	for (connection_list::iterator it = _connections.begin();
			it != _connections.end(); ++it)
	{
		Connection& c = **it;

		eqs += c.equations();
	}

	return eqs;
}
