/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATIONS_ADDITIVEINVERSEEQUATION_HXX
#define _PLANTCALC_EQUATIONS_ADDITIVEINVERSEEQUATION_HXX 1

#include "linearequation.hxx"

/**
 * An a=-b equation.
 *
 * A simplified kind of LinearEquation which represents
 * the @f$ a = -b @f$ kind of equation.
 */
class AdditiveInverseEquation : public LinearEquation
{
public:
	AdditiveInverseEquation(Variable& v1, Variable& v2);
};

#endif /*_PLANTCALC_EQUATIONS_ADDITIVEINVERSEEQUATION_HXX*/
