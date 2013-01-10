/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "deaerator2.hxx"
#include "../variables/constant.hxx"

static Constant xsat(0.0);

Deaerator2::Deaerator2(const char* name)
	: MediumFlowDevice(name),
	_sec_in(_device_id, "sec-in"),
	_cond_in(_device_id, "cond-in"),
	_primary_pressure_eq(in().p(), out().p()),
	_secondary_pressure_eq(_sec_in.p(), in().p()),
	_saturation_eq(out().x(), xsat),
	_mass_balance_eq(1, in().D(),
			1, _sec_in.D(),
			1, _cond_in.D(),
			1, out().D()),
	_energy_balance_eq(1, in().D(), in().h(),
			1, _sec_in.D(), _sec_in.h(),
			1, _cond_in.D(), _cond_in.h(),
			1, out().D(), out().h())
{
}

Deaerator2::pin_list_type Deaerator2::pins()
{
	pin_list_type ret = MediumFlowDevice::pins();

	ret.push_back(&_sec_in);
	ret.push_back(&_cond_in);

	return ret;
}

MediumPin& Deaerator2::sec_in()
{
	return _sec_in;
}

MediumPin& Deaerator2::cond_in()
{
	return _cond_in;
}

bool Deaerator2::pins_connected(const Pin& lhs, const Pin& rhs) const
{
	if (MediumFlowDevice::pins_connected(lhs, rhs))
		return true;

	if (&lhs == &_sec_in || &lhs == &_cond_in)
		return true;

	return false;
}

EquationSystem Deaerator2::equations()
{
	EquationSystem ret;

	ret.push_back(&_primary_pressure_eq);
	ret.push_back(&_secondary_pressure_eq);
	ret.push_back(&_saturation_eq);
	ret.push_back(&_mass_balance_eq);
	ret.push_back(&_energy_balance_eq);

	return ret;
}

Deaerator2::variable_list_type Deaerator2::variables()
{
	variable_list_type ret;

	return ret;
}
