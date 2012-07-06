/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "system.hxx"

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
