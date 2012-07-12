#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include "src/devices/boiler.hxx"
#include "src/devices/condenser.hxx"
#include "src/devices/turbine.hxx"
#include "src/devices/endpoints/fuelendpoint.hxx"
#include "src/devices/endpoints/mediumendpoint.hxx"
#include "src/equationsystem.hxx"
#include "src/system.hxx"

#include "src/connections/fuelconnection.hxx"
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

	MediumEndpoint c1(0.1, 288.15);
	MediumEndpoint c2(0.1, 298.15);
	FuelEndpoint fe;

	MediumConnection bt(b.out(), t.in());
	MediumConnection tc(t.out(), c.in());
	MediumConnection cb(c.out(), b.in());
	MediumConnection tloop(t.loop_out(), t.loop_in());

	MediumConnection cs1(c.sec_in(), c1);
	MediumConnection cs2(c.sec_out(), c2);

	FuelConnection ff(fe, b.fuel_in());

	H2OMedium water;

	bt.substance(&water);
	t.energy_out().P().set_value(1000);
	b.fuel_in().Qw().set_value(22000);

	cs1.substance(&water);

	System plant;
	plant.push_back(b);
	plant.push_back(t);
	plant.push_back(c);
	plant.push_back(c1);
	plant.push_back(c2);
	plant.push_back(fe);

	plant.push_back(bt);
	plant.push_back(tc);
	plant.push_back(cb);
	plant.push_back(tloop);
	plant.push_back(cs1);
	plant.push_back(cs2);
	plant.push_back(ff);

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
