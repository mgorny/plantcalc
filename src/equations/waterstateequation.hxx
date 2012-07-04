/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATIONS_WATERSTATEEQUATION_HXX
#define _PLANTCALC_EQUATIONS_WATERSTATEEQUATION_HXX 1

#include "../equation.hxx"
#include "../variable.hxx"

#include <ostream>

class WaterStateEquation : public Equation
{
	Variable& _p, _T, _h;

public:
	WaterStateEquation(Variable& p, Variable& T, Variable& h);

	virtual bool solve();
	virtual std::ostream& print_to(std::ostream& f) const;
};

#endif /*_PLANTCALC_EQUATIONS_WATERSTATEEQUATION_HXX*/
