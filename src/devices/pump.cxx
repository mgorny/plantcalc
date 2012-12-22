/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "pump.hxx"
#include "../variables/constant.hxx"

static Constant one(1);

Pump::Pump(double isen_eff, double mech_eff)
	: ReversibleTurbine("P", isen_eff, mech_eff),
	_real_expansion_eq(-1.0, _loop_out.h(),
			1.0, _one_minus_isenthropic_efficiency, _in.h(),
			1.0, _isenthropic_efficiency, _out.h())
{
}

Pump::Pump(double isen_eff, double mech_eff, double pout)
	: ReversibleTurbine("P", isen_eff, mech_eff, pout),
	_real_expansion_eq(-1.0, _loop_out.h(),
			1.0, _one_minus_isenthropic_efficiency, _in.h(),
			1.0, _isenthropic_efficiency, _out.h())
{
}

EquationSystem Pump::equations()
{
	EquationSystem ret = ReversibleTurbine::equations();

	ret.push_back(&_real_expansion_eq);

	return ret;
}
