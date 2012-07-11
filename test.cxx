#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include "src/devices/boiler.hxx"
#include "src/devices/condenser.hxx"
#include "src/devices/turbine.hxx"
#include "src/equationsystem.hxx"
#include "src/system.hxx"

#include "src/connections/mediumconnection.hxx"
#include "src/equationsolvers/autoequationsolver.hxx"
#include "src/substances/media/h2omedium.hxx"

#include "src/exceptions/contradictionerror.hxx"

#include <vector>
#include <iostream>

int main()
{
	Boiler b(.9, 10, 773.15);
	Turbine t(.95, .99, 0.1);
	Condenser c;

	MediumConnection bt(b.out(), t.in());
	MediumConnection tc(t.out(), c.in());
	MediumConnection cb(c.out(), b.in());
	MediumConnection tloop(t.loop_out(), t.loop_in());

	H2OMedium water;

	bt.substance(&water);
	t.energy_out().P().set_value(1000);

	System plant;
	plant.push_back(b);
	plant.push_back(t);
	plant.push_back(c);
	plant.push_back(bt);
	plant.push_back(tc);
	plant.push_back(cb);
	plant.push_back(tloop);

	plant.set_device_ids();
	plant.set_substances();

	EquationSystem eqs = plant.equations();
	std::cout << eqs << std::endl;

	AutoEquationSolver solv;

	try
	{
		while (solv.iterate(eqs))
			std::cout << eqs << std::endl;
	}
	catch (ContradictionError& e)
	{
		std::cout << eqs << std::endl;
		throw;
	}

	std::cout << eqs << std::endl;

	std::cout << plant << std::endl;

	return 0;
}
