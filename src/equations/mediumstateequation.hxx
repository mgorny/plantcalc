/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATIONS_MEDIUMSTATEEQUATION_HXX
#define _PLANTCALC_EQUATIONS_MEDIUMSTATEEQUATION_HXX 1

#include "../equation.hxx"
#include "../substances/mediumsubstance.hxx"
#include "../variable.hxx"

#include <ostream>

class MediumStateEquation : public Equation
{
	Variable& _p;
	Variable& _T;
	Variable& _h;
	Variable& _s;
	Variable& _x;

	MediumSubstance* _medium;

public:
	MediumStateEquation(Variable& p, Variable& T, Variable& h,
			Variable& s, Variable& x);

	virtual bool solve();
	virtual std::ostream& print_to(std::ostream& f) const;

	MediumSubstance* medium();
	void medium(MediumSubstance* m);
};

#endif /*_PLANTCALC_EQUATIONS_MEDIUMSTATEEQUATION_HXX*/
