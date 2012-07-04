/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "condenser.hxx"

Condenser::Condenser()
	: _secondary_mass_eq(_sec_in.D(), _sec_out.D())
{
}

MediumPin& Condenser::sec_in()
{
	return _sec_in;
}

MediumPin& Condenser::sec_out()
{
	return _sec_out;
}

EquationSystem Condenser::equations()
{
	EquationSystem ret = MediumFlowDevice::equations();

	ret.push_back(&_secondary_mass_eq);

	return ret;
}
