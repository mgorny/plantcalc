/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "reversibleturbine.hxx"
#include "../../variables/constant.hxx"

#include <cassert>

static Constant one(1);

ReversibleTurbine::ReversibleTurbine(const char* name,
		double isen_eff, double mech_eff)
	: MediumFlowDevice(name),
	_isenthropic_efficiency(_device_id, "etai", isen_eff),
	_one_minus_isenthropic_efficiency(_device_id, "1-etai"),
	_mechanical_efficiency(_device_id, "etam", mech_eff),
	_mechanical_efficiency_reciprocal(_device_id, "1/etam"),
	_loop_in(_device_id, "loop-in"),
	_loop_out(_device_id, "loop-out"),
	_energy_pin(_device_id, "energy-pin"),
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
			1.0, _in.D(), _in.h(),
			1.0, _mechanical_efficiency_reciprocal, _energy_pin.P()),
	_loop_conn(_loop_out, _loop_in)
{
	// XXX: add boundaries to efficiences
}

ReversibleTurbine::ReversibleTurbine(const char* name,
		double isen_eff, double mech_eff, double pout)
	: MediumFlowDevice(name),
	_isenthropic_efficiency(_device_id, "etai", isen_eff),
	_one_minus_isenthropic_efficiency(_device_id, "(1-etai)"),
	_mechanical_efficiency(_device_id, "etam", mech_eff),
	_mechanical_efficiency_reciprocal(_device_id, "(1/etam)"),
	_loop_in(_device_id, "loop-in"),
	_loop_out(_device_id, "loop-out"),
	_energy_pin(_device_id, "energy-pin"),
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
			1.0, _in.D(), _in.h(),
			1.0, _mechanical_efficiency_reciprocal, _energy_pin.P()),
	_loop_conn(_loop_out, _loop_in)
{
	_out.p().set_value(pout);
}

ReversibleTurbine::pin_list_type ReversibleTurbine::pins()
{
	pin_list_type ret = MediumFlowDevice::pins();

	ret.push_back(&_energy_pin);

	return ret;
}

ReversibleTurbine::variable_list_type ReversibleTurbine::variables()
{
	variable_list_type ret;

	ret.push_back(&_isenthropic_efficiency);
	ret.push_back(&_mechanical_efficiency);

	return ret;
}

Variable& ReversibleTurbine::isenthropic_efficiency()
{
	return _isenthropic_efficiency;
}

Variable& ReversibleTurbine::mechanical_efficiency()
{
	return _mechanical_efficiency;
}

MechanicalEnergyPin& ReversibleTurbine::energy_pin()
{
	return _energy_pin;
}

bool ReversibleTurbine::pins_connected(const Pin& lhs, const Pin& rhs) const
{
	if (&lhs != &_energy_pin && &rhs != &_energy_pin)
		return true;

	return false;
}

EquationSystem ReversibleTurbine::equations()
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

Device::connection_list_type ReversibleTurbine::internal_connections()
{
	connection_list_type ret;

	ret.push_back(&_loop_conn);

	return ret;
}
