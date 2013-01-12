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

Turbine::Turbine(const char* name, double isen_eff, double mech_eff)
	: ReversibleTurbine(name, isen_eff, mech_eff),
	_mechanical_efficiency_reciprocal(_device_id, "1/etam"),
	_real_expansion_eq(1.0, _out.h(),
			-1.0, _one_minus_isenthropic_efficiency, _in.h(),
			-1.0, _isenthropic_efficiency, _loop_out.h()),
	_mech_eff_reciprocal_eq(1.0, one,
			-1.0, _mechanical_efficiency, _mechanical_efficiency_reciprocal),
	_energy_balance_eq(1.0, _out.D(), _out.h(),
			1.0, _in.D(), _in.h(),
			1.0, _mechanical_efficiency_reciprocal, _energy_pin.P())
{
}

Turbine::Turbine(const char* name, double isen_eff, double mech_eff, double pout)
	: ReversibleTurbine(name, isen_eff, mech_eff, pout),
	_mechanical_efficiency_reciprocal(_device_id, "1/etam"),
	_real_expansion_eq(1.0, _out.h(),
			-1.0, _one_minus_isenthropic_efficiency, _in.h(),
			-1.0, _isenthropic_efficiency, _loop_out.h()),
	_mech_eff_reciprocal_eq(1.0, one,
			-1.0, _mechanical_efficiency, _mechanical_efficiency_reciprocal),
	_energy_balance_eq(1.0, _out.D(), _out.h(),
			1.0, _in.D(), _in.h(),
			1.0, _mechanical_efficiency_reciprocal, _energy_pin.P())
{
}

EquationSystem Turbine::equations()
{
	EquationSystem ret = ReversibleTurbine::equations();

	ret.push_back(&_real_expansion_eq);
	ret.push_back(&_mech_eff_reciprocal_eq);
	ret.push_back(&_energy_balance_eq);

	return ret;
}
