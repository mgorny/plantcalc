/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATIONS_WATERSTATEEQUATION_HXX
#define _PLANTCALC_EQUATIONS_WATERSTATEEQUATION_HXX 1

#include "mediumstateequation.hxx"

class WaterStateEquation : public MediumStateEquation
{
public:
	WaterStateEquation(Variable& p, Variable& T, Variable& h,
			Variable& s, Variable& x);
};

#endif /*_PLANTCALC_EQUATIONS_WATERSTATEEQUATION_HXX*/
