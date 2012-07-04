#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include "src/devices/boiler.hxx"
#include "src/devices/condenser.hxx"
#include "src/devices/turbine.hxx"
#include "src/equationsystem.hxx"

#include "src/connections/medium/waterconnection.hxx"
#include "src/equationsolvers/determinateequationsolver.hxx"

#include "src/exceptions/contradictionerror.hxx"

#include <vector>
#include <iostream>

int main()
{
	Boiler b(.9, 10, 773.15);
	Turbine t(.95, .99, 0.1);
	Condenser c;

	WaterConnection bt(b.out(), t.in());
	WaterConnection tc(t.out(), c.in());
	WaterConnection cb(c.out(), b.in());
	WaterConnection tloop(t.loop_out(), t.loop_in());

	t.energy_out().P().set_value(1000);

	typedef std::vector<Device*> device_list;
	device_list devices;
	devices.push_back(&b);
	devices.push_back(&t);
	devices.push_back(&c);

	typedef std::vector<Connection*> connection_list;
	connection_list connections;
	connections.push_back(&bt);
	connections.push_back(&tc);
	connections.push_back(&cb);
	connections.push_back(&tloop);

	EquationSystem eqs;

	for (device_list::iterator it = devices.begin();
			it != devices.end(); ++it)
	{
		Device& d = **it;

		eqs += d.equations();
	}

	for (connection_list::iterator it = connections.begin();
			it != connections.end(); ++it)
	{
		Connection& c = **it;

		eqs += c.equations();
	}

	std::cout << eqs << std::endl;
	DeterminateEquationSolver solv(eqs);

	try
	{
		while (solv.iterate())
			std::cout << eqs << std::endl;
	}
	catch (ContradictionError& e)
	{
		std::cout << eqs << std::endl;
		throw;
	}

	return 0;
}
