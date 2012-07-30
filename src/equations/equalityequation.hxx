/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_EQUATIONS_EQUALITYEQUATION_HXX
#define PLANTCALC_EQUATIONS_EQUALITYEQUATION_HXX 1

#include "linearequation.hxx"

/**
 * An a=b equation.
 *
 * A simplified kind of LinearEquation which represents
 * the @f$ a = b @f$ kind of equation.
 */
class EqualityEquation : public LinearEquation
{
public:
	EqualityEquation(Variable& v1, Variable& v2);
};

#endif /*_PLANTCALC_EQUATIONS_EQUALITYEQUATION_HXX*/
