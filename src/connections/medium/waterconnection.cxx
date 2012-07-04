/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "waterconnection.hxx"

WaterConnection::WaterConnection(MediumPin& from, MediumPin& to)
	: MediumConnection(from, to),
	_state_eq(from.p(), from.T(), from.h())
{
}

EquationSystem WaterConnection::equations()
{
	EquationSystem ret = MediumConnection::equations();

	ret.push_back(&_state_eq);

	return ret;
}
