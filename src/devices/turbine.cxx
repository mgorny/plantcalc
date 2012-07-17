/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "turbine.hxx"
#include "../variables/constant.hxx"

static Constant one(1);

#include <cassert>

Turbine::Turbine(double isen_eff,
			double mech_eff)
	: MediumFlowDevice("T"),
	_isenthropic_efficiency(_device_id, "etai", isen_eff),
	_one_minus_isenthropic_efficiency(_device_id, "1-etai"),
	_mechanical_efficiency(_device_id, "etam", mech_eff),
	_mechanical_efficiency_reciprocal(_device_id, "1/etam"),
	_loop_in(_device_id, "loop-in"),
	_loop_out(_device_id, "loop-out"),
	_energy_out(_device_id, "energy-out"),
	_one_minus_isen_eff_eq(1.0, one,
			-1.0, _isenthropic_efficiency,
			-1.0, _one_minus_isenthropic_efficiency),
	_mech_eff_reciprocal_eq(1.0, one,
			-1.0, _mechanical_efficiency, _mechanical_efficiency_reciprocal),
	_loop_mass_eq(_in.D(), _loop_in.D()),
	_loop_mass_balance_eq(_loop_in.D(), _loop_out.D()),
	_loop_pressure_eq(_loop_out.p(), _out.p()),
	_ideal_expansion_eq(_in.s(), _loop_in.s()),
	_real_expansion_eq(1.0, _out.h(),
			-1.0, _one_minus_isenthropic_efficiency, _in.h(),
			-1.0, _isenthropic_efficiency, _loop_out.h()),
	_energy_balance_eq(1.0, _out.D(), _out.h(),
			-1.0, _in.D(), _in.h(),
			1.0, _mechanical_efficiency_reciprocal, _energy_out.P())
{
	// XXX: add boundaries to efficiences
}

Turbine::Turbine(double isen_eff,
			double mech_eff, double pout)
	: MediumFlowDevice("T"),
	_isenthropic_efficiency(_device_id, "etai", isen_eff),
	_one_minus_isenthropic_efficiency(_device_id, "(1-etai)"),
	_mechanical_efficiency(_device_id, "etam", mech_eff),
	_mechanical_efficiency_reciprocal(_device_id, "(1/etam)"),
	_loop_in(_device_id, "loop-in"),
	_loop_out(_device_id, "loop-out"),
	_energy_out(_device_id, "energy-out"),
	_one_minus_isen_eff_eq(1.0, one,
			-1.0, _isenthropic_efficiency,
			-1.0, _one_minus_isenthropic_efficiency),
	_mech_eff_reciprocal_eq(1.0, one,
			-1.0, _mechanical_efficiency, _mechanical_efficiency_reciprocal),
	_loop_mass_eq(_in.D(), _loop_in.D()),
	_loop_mass_balance_eq(_loop_in.D(), _loop_out.D()),
	_loop_pressure_eq(_loop_out.p(), _out.p()),
	_ideal_expansion_eq(_in.s(), _loop_in.s()),
	_real_expansion_eq(1.0, _out.h(),
			-1.0, _one_minus_isenthropic_efficiency, _in.h(),
			-1.0, _isenthropic_efficiency, _loop_out.h()),
	_energy_balance_eq(1.0, _out.D(), _out.h(),
			-1.0, _in.D(), _in.h(),
			1.0, _mechanical_efficiency_reciprocal, _energy_out.P())
{
	_out.p().set_value(pout);
}

Variable& Turbine::isenthropic_efficiency()
{
	return _isenthropic_efficiency;
}

Pin* Turbine::iter_pin_get(int index)
{
	Pin* ret;

	if (index < _iter_first_free_index)
		return MediumFlowDevice::iter_pin_get(index);
	else
		index -= _iter_first_free_index;

	switch (index)
	{
		case 0:
			ret = &_energy_out;
			break;
		default:
			ret = 0;
	}

	return ret;
}

DeviceVariable* Turbine::iter_var_get(int index)
{
	DeviceVariable* ret;

	switch (index)
	{
		case 0:
			ret = &_isenthropic_efficiency;
			break;
		case 1:
			ret = &_mechanical_efficiency;
			break;
		default:
			ret = 0;
	}

	return ret;
}

Variable& Turbine::mechanical_efficiency()
{
	return _mechanical_efficiency;
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

bool Turbine::pins_connected(const Pin& lhs, const Pin& rhs) const
{
	if (&lhs != &_energy_out && &rhs != &_energy_out)
		return true;

	return false;
}

EquationSystem Turbine::equations()
{
	EquationSystem ret = MediumFlowDevice::equations();

	ret.push_back(&_one_minus_isen_eff_eq);
	ret.push_back(&_mech_eff_reciprocal_eq);
	ret.push_back(&_loop_mass_eq);
	ret.push_back(&_loop_mass_balance_eq);
	ret.push_back(&_loop_pressure_eq);
	ret.push_back(&_ideal_expansion_eq);
	ret.push_back(&_real_expansion_eq);
	ret.push_back(&_energy_balance_eq);

	return ret;
}
