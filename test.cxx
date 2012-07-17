#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include "src/devices/boiler.hxx"
#include "src/devices/condenser.hxx"
#include "src/devices/turbine.hxx"
#include "src/devices/endpoints/fuelendpoint.hxx"
#include "src/devices/endpoints/mediumendpoint.hxx"
#include "src/devices/splittingjunctions/mediumsplittingjunction.hxx"
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
	Turbine t(.95, .99, 1);
	Turbine t2(.95, .99, 0.1);
	Condenser c(10);

	MediumEndpoint c1(0.1, 288.15);
	MediumEndpoint c2(0.1);
	FuelEndpoint fe;

	MediumSplittingJunction msj;

	MediumConnection bt(b.out(), t.in());
	MediumConnection tt1(t.out(), msj.in());
	MediumConnection tt2(msj.out1(), t2.in());
	MediumConnection tc(t2.out(), c.in());
	MediumConnection cb(c.out(), b.in());
	MediumConnection tloop(t.loop_out(), t.loop_in());
	MediumConnection tloop2(t2.loop_out(), t2.loop_in());

	MediumConnection cs1(c.sec_in(), c1);
	MediumConnection cs2(c.sec_out(), c2);

	FuelConnection ff(fe, b.fuel_in());

	H2OMedium water;

	bt.substance(&water);
	t.energy_out().P().set_value(900);
	t2.energy_out().P().set_value(100);
	b.fuel_in().Qw().set_value(22000);

	cs1.substance(&water);

	System plant;
	plant.push_back(b);
	plant.push_back(t);
	plant.push_back(t2);
	plant.push_back(c);
	plant.push_back(c1);
	plant.push_back(c2);
	plant.push_back(fe);
	plant.push_back(msj);

	plant.push_back(bt);
	plant.push_back(tc);
	plant.push_back(tt1);
	plant.push_back(tt2);
	plant.push_back(cb);
	plant.push_back(tloop);
	plant.push_back(tloop2);
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

	std::cout << plant.graph() << std::endl;

	std::cout << plant << std::endl;

	std::cout << plant.connections() << std::endl;

	return 0;
}
