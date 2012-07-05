/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "condenser.hxx"

static Variable xsat("xsat", 0, 0.0, true);

Condenser::Condenser()
	: MediumFlowDevice("C"),
	_sec_in(_device_id, "sec-in"),
	_sec_out(_device_id, "sec-out"),
	_secondary_mass_eq(_sec_in.D(), _sec_out.D()),
	_primary_pressure_eq(in().p(), out().p()),
	_primary_saturation_eq(out().x(), xsat)
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
	ret.push_back(&_primary_pressure_eq);
	ret.push_back(&_primary_saturation_eq);

	return ret;
}
