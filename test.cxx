#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include "src/devices/boiler.hxx"
#include "src/devices/condenser.hxx"
#include "src/devices/feedwaterheater.hxx"
#include "src/devices/pump.hxx"
#include "src/devices/turbine.hxx"
#include "src/devices/endpoints/fuelendpoint.hxx"
#include "src/devices/endpoints/mediumendpoint.hxx"
#include "src/devices/splittingjunctions/mediumsplittingjunction.hxx"
#include "src/devices/mixingjunctions/mechanicalenergymixingjunction.hxx"
#include "src/devices/mixingjunctions/approximatemediummixingjunction.hxx"
#include "src/equationsystem.hxx"
#include "src/system.hxx"

#include "src/connections/fuelconnection.hxx"
#include "src/connections/mechanicalenergyconnection.hxx"
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

	Pump pump(0.97, .99, 10);

	FeedwaterHeater fw1(10);

	MediumEndpoint c1(0.1, 288.15);
	MediumEndpoint c2(0.1);
	FuelEndpoint fe;

	MediumSplittingJunction msj;
	MechanicalEnergyMixingJunction memj, pumptj;
	ApproximateMediumMixingJunction fw1mj;

	MediumConnection bt(b.out(), t.in());
	MediumConnection tt1(t.out(), msj.in());
	MediumConnection tt2(msj.out1(), t2.in());
	MediumConnection tc(t2.out(), c.in());
	MediumConnection c1m(c.out(), fw1mj.in1());
	MediumConnection tloop(t.loop_out(), t.loop_in());
	MediumConnection tloop2(t2.loop_out(), t2.loop_in());
	MediumConnection pumpc(fw1mj.out(), pump.in());
	MediumConnection pumpl(pump.loop_out(), pump.loop_in());

	MediumConnection fw1i(msj.out2(), fw1.in());
	MediumConnection fw1m(fw1.out(), fw1mj.in2());
	MediumConnection fw1s(pump.out(), fw1.sec_in());
	MediumConnection fw1o(fw1.sec_out(), b.in());

	MediumConnection cs1(c.sec_in(), c1);
	MediumConnection cs2(c.sec_out(), c2);

	FuelConnection ff(fe, b.fuel_in());
	MechanicalEnergyConnection tout1(t.energy_pin(), memj.in1());
	MechanicalEnergyConnection tout2(t2.energy_pin(), memj.in2());
	MechanicalEnergyConnection pumptm(memj.out(), pumptj.in1());
	MechanicalEnergyConnection pumpm(pump.energy_pin(), pumptj.in2());

	H2OMedium water;

	bt.substance(&water);
	pumptj.out().P().set_value(1000);
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
	plant.push_back(memj);
	plant.push_back(fw1mj);
	plant.push_back(fw1);
	plant.push_back(pump);
	plant.push_back(pumptj);

	plant.push_back(bt);
	plant.push_back(tc);
	plant.push_back(tt1);
	plant.push_back(tt2);
	plant.push_back(tout1);
	plant.push_back(tout2);
	plant.push_back(c1m);
	plant.push_back(tloop);
	plant.push_back(tloop2);
	plant.push_back(cs1);
	plant.push_back(cs2);
	plant.push_back(ff);
	plant.push_back(fw1i);
	plant.push_back(fw1m);
	plant.push_back(fw1s);
	plant.push_back(fw1o);
	plant.push_back(pumpc);
	plant.push_back(pumpl);
	plant.push_back(pumpm);
	plant.push_back(pumptm);

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
