/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "mediumflowdevice.hxx"

MediumFlowDevice::MediumFlowDevice()
	: _primary_mass_eq(_in.D(), _out.D())
{
}

EquationSystem MediumFlowDevice::equations()
{
	EquationSystem ret;

	ret.push_back(&_primary_mass_eq);

	return ret;
}

MediumPin& MediumFlowDevice::in()
{
	return _in;
}

MediumPin& MediumFlowDevice::out()
{
	return _out;
}
