/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include <cassert>

#include "boiler.hxx"

Boiler::Boiler(double eff)
	: MediumFlowDevice("B"),
	_efficiency(_device_id, "eta", eff),
	_fuel_in(_device_id, "fuel-in")
{
	_energy_balance_eq.update(1, in().D(), in().h());
	_energy_balance_eq.update(1, _efficiency, _fuel_in.Q());
	_energy_balance_eq.update(-1, out().D(), out().h());

	_fuel_energy_eq.update(1, _fuel_in.Q());
	_fuel_energy_eq.update(-1, _fuel_in.B(), _fuel_in.Qw());
}

Boiler::Boiler(double eff, double pout, double Tout)
	: MediumFlowDevice("B"),
	_efficiency(_device_id, "eta", eff),
	_fuel_in(_device_id, "fuel-in")
{
	MediumPin& mout = out();
	mout.p().set_value(pout);
	mout.T().set_value(Tout);

	_energy_balance_eq.update(1, in().D(), in().h());
	_energy_balance_eq.update(1, _efficiency, _fuel_in.Q());
	_energy_balance_eq.update(-1, out().D(), out().h());

	_fuel_energy_eq.update(1, _fuel_in.Q());
	_fuel_energy_eq.update(-1, _fuel_in.B(), _fuel_in.Qw());
}

Variable& Boiler::efficiency()
{
	return _efficiency;
}

EquationSystem Boiler::equations()
{
	EquationSystem ret = MediumFlowDevice::equations();

	ret.push_back(&_energy_balance_eq);
	ret.push_back(&_fuel_energy_eq);

	return ret;
}
