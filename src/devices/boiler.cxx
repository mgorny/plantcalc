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
	: _efficiency(eff),
	_out(pout, Tout)
{
}

double Boiler::efficiency()
{
	return _efficiency;
}

void Boiler::efficiency(double new_value)
{
	assert(0 <= new_value <= 1);

	_efficiency = new_value;
}

MediumPin& Boiler::in()
{
	return _in;
}

MediumPin& Boiler::out()
{
	return _out;
}
