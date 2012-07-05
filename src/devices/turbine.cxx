/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "turbine.hxx"

#include <cassert>

Turbine::Turbine(double isen_eff,
			double mech_eff)
	: MediumFlowDevice("T"),
	_loop_mass_balance_eq(_loop_in.D(), _loop_out.D()),
	_loop_pressure_eq(_loop_out.p(), out().p()),
	_ideal_expansion_eq(in().s(), _loop_in.s())
{
	_real_expansion_eq.update(-1, out().h());

	_energy_balance_eq.update(1, out().D(), out().h());
	_energy_balance_eq.update(-1, in().D(), in().h());

	isenthropic_efficiency(isen_eff);
	mechanical_efficiency(mech_eff);
}

Turbine::Turbine(double isen_eff,
			double mech_eff, double pout)
	: MediumFlowDevice("T"),
	_loop_mass_balance_eq(_loop_in.D(), _loop_out.D()),
	_loop_pressure_eq(_loop_out.p(), out().p()),
	_ideal_expansion_eq(in().s(), _loop_in.s())
{
	out().p().set_value(pout);

	_real_expansion_eq.update(-1, out().h());

	_energy_balance_eq.update(1, out().D(), out().h());
	_energy_balance_eq.update(-1, in().D(), in().h());

	isenthropic_efficiency(isen_eff);
	mechanical_efficiency(mech_eff);
}

double Turbine::isenthropic_efficiency()
{
	return _isenthropic_efficiency;
}

void Turbine::isenthropic_efficiency(double new_value)
{
	assert(new_value >= 0);
	assert(new_value <= 1);

	_isenthropic_efficiency = new_value;
	_real_expansion_eq.update(1 - _isenthropic_efficiency, in().h());
	_real_expansion_eq.update(_isenthropic_efficiency, _loop_out.h());
}

double Turbine::mechanical_efficiency()
{
	return _mechanical_efficiency;
}

void Turbine::mechanical_efficiency(double new_value)
{
	assert(new_value >= 0);
	assert(new_value <= 1);

	_mechanical_efficiency = new_value;
	_energy_balance_eq.update(1 / _mechanical_efficiency, _energy_out.P());
}

MediumPin& Turbine::loop_out()
{
	return _loop_out;
}

MediumPin& Turbine::loop_in()
{
	return _loop_in;
}

MechanicalEnergyPin& Turbine::energy_out()
{
	return _energy_out;
}

EquationSystem Turbine::equations()
{
	EquationSystem ret = MediumFlowDevice::equations();

	ret.push_back(&_loop_mass_balance_eq);
	ret.push_back(&_loop_pressure_eq);
	ret.push_back(&_ideal_expansion_eq);
	ret.push_back(&_real_expansion_eq);
	ret.push_back(&_energy_balance_eq);

	return ret;
}
