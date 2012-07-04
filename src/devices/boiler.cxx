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
	: _efficiency(eff)
{
}

Boiler::Boiler(double eff, double pout, double Tout)
	: _efficiency(eff)
{
	MediumPin& mout = out();
	mout.p().set_value(pout);
	mout.T().set_value(Tout);
}

double Boiler::efficiency()
{
	return _efficiency;
}

void Boiler::efficiency(double new_value)
{
	assert(new_value >= 0);
	assert(new_value <= 1);

	_efficiency = new_value;
}

EquationSystem Boiler::equations()
{
	EquationSystem ret = MediumFlowDevice::equations();

	return ret;
}
