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
	_efficiency(_device_id, "eta", eff)
{
}

Boiler::Boiler(double eff, double pout, double Tout)
	: MediumFlowDevice("B"),
	_efficiency(_device_id, "eta", eff)
{
	MediumPin& mout = out();
	mout.p().set_value(pout);
	mout.T().set_value(Tout);
}

Variable& Boiler::efficiency()
{
	return _efficiency;
}

EquationSystem Boiler::equations()
{
	EquationSystem ret = MediumFlowDevice::equations();

	return ret;
}
