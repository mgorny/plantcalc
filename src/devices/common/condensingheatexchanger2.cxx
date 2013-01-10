/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "condensingheatexchanger2.hxx"
#include "../../variables/constant.hxx"

static Constant xsat(0.0);

CondensingHeatExchanger2::CondensingHeatExchanger2(const char* name)
	: Device(name),
	_primary_pressure_eq(in().p(), out().p()),
	_primary_saturation_eq(out().x(), xsat),
	_secondary_pressure_eq(_sec_in.p(), _sec_out.p()),
	_primary_mass_eq(1, _in.D(), 1, _cond_in.D(), 1, _out.D()),
	_secondary_mass_eq(_sec_in.D(), _sec_out.D()),
	_energy_balance_eq(1, in().D(), in().h(),
			1, _sec_in.D(), _sec_in.h(),
			1, out().D(), out().h(),
			1, _sec_out.D(), _sec_out.h(),
			1, _cond_in.D(), _cond_in.h()),
	_in(_device_id, "in"),
	_out(_device_id, "out"),
	_cond_in(_device_id, "cond-in"),
	_sec_in(_device_id, "sec-in"),
	_sec_out(_device_id, "sec-out")
{
}

CondensingHeatExchanger2::pin_list_type CondensingHeatExchanger2::pins()
{
	pin_list_type ret;

	ret.push_back(&_in);
	ret.push_back(&_out);
	ret.push_back(&_cond_in);
	ret.push_back(&_sec_in);
	ret.push_back(&_sec_out);

	return ret;
}

MediumPin& CondensingHeatExchanger2::in()
{
	return _in;
}

MediumPin& CondensingHeatExchanger2::out()
{
	return _out;
}

MediumPin& CondensingHeatExchanger2::cond_in()
{
	return _cond_in;
}

MediumPin& CondensingHeatExchanger2::sec_in()
{
	return _sec_in;
}

MediumPin& CondensingHeatExchanger2::sec_out()
{
	return _sec_out;
}

bool CondensingHeatExchanger2::pins_connected(const Pin& lhs, const Pin& rhs) const
{
	if (&lhs == &_in && (&rhs == &_out || &rhs == &_cond_in))
		return true;
	if (&lhs == &_out && (&rhs == &_in || &rhs == &_cond_in))
		return true;
	if (&lhs == &_cond_in && (&rhs == &_in || &rhs == &_out))
		return true;
	if (&lhs == &_sec_in && &rhs == &_sec_out)
		return true;
	if (&lhs == &_sec_out && &rhs == &_sec_in)
		return true;

	return false;
}

EquationSystem CondensingHeatExchanger2::equations()
{
	EquationSystem ret;

	ret.push_back(&_primary_pressure_eq);
	ret.push_back(&_primary_saturation_eq);
	ret.push_back(&_secondary_pressure_eq);
	ret.push_back(&_primary_mass_eq);
	ret.push_back(&_secondary_mass_eq);
	ret.push_back(&_energy_balance_eq);

	return ret;
}
