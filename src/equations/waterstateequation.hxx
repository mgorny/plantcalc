/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATIONS_WATERSTATEEQUATION_HXX
#define _PLANTCALC_EQUATIONS_WATERSTATEEQUATION_HXX 1

#include "../equation.hxx"
#include "../media/h2omedium.hxx"
#include "../variable.hxx"

#include <ostream>

class WaterStateEquation : public Equation
{
	Variable& _p;
	Variable& _T;
	Variable& _h;
	Variable& _s;
	Variable& _x;

	H2OMedium _medium;

public:
	WaterStateEquation(Variable& p, Variable& T, Variable& h,
			Variable& s, Variable& x);

	virtual bool solve();
	virtual std::ostream& print_to(std::ostream& f) const;
};

#endif /*_PLANTCALC_EQUATIONS_WATERSTATEEQUATION_HXX*/
