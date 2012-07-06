/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "waterstateequation.hxx"
#include "../media/h2omedium.hxx"

static H2OMedium h2o_medium;

WaterStateEquation::WaterStateEquation(Variable& p, Variable& T, Variable& h,
			Variable& s, Variable& x)
	: MediumStateEquation(p, T, h, s, x)
{
	medium(&h2o_medium);
}
