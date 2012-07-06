#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include "src/devices/boiler.hxx"
#include "src/devices/condenser.hxx"
#include "src/devices/turbine.hxx"
#include "src/equationsystem.hxx"
#include "src/system.hxx"

#include "src/connections/medium/waterconnection.hxx"
#include "src/equationsolvers/determinateequationsolver.hxx"
#include "src/equationsolvers/linearequationsolver.hxx"

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

	System plant;
	plant.push_back(b);
	plant.push_back(t);
	plant.push_back(c);
	plant.push_back(bt);
	plant.push_back(tc);
	plant.push_back(cb);
	plant.push_back(tloop);

	EquationSystem eqs = plant.equations();
	std::cout << eqs << std::endl;

	// first clean up the system using simple solver
	DeterminateEquationSolver solv;

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

	// solve remaining equations using linear solver
	EquationSystem eqs2 = eqs;
	LinearEquationSolver lsolv;

	try
	{
		while (lsolv.iterate(eqs2))
			std::cout << eqs2 << std::endl;
	}
	catch (ContradictionError& e)
	{
		std::cout << eqs2 << std::endl;
		throw;
	}

	// do an additional run to ensure everything went fine
	std::cout << eqs << std::endl;
	solv.iterate(eqs);

	return 0;
}
