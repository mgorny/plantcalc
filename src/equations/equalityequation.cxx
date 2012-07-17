/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "equalityequation.hxx"

EqualityEquation::EqualityEquation(Variable& v1, Variable& v2)
	: LinearEquation(1.0, v1, -1.0, v2)
{
}
