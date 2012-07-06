/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "waterconnection.hxx"
#include "../../media/h2omedium.hxx"

static H2OMedium h2o_medium;

WaterConnection::WaterConnection(MediumPin& from, MediumPin& to)
	: MediumConnection(from, to),
	_state_eq(from.p(), from.T(), from.h(), from.s(), from.x())
{
	_state_eq.medium(&h2o_medium);
}

EquationSystem WaterConnection::equations()
{
	EquationSystem ret = MediumConnection::equations();

	ret.push_back(&_state_eq);

	return ret;
}
