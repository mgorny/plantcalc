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

/**
 * An equation for medium state parameter correlation.
 *
 * A MediumStateEquation is a general equation used to correlate
 * the medium state parameters at a given point of the system.
 *
 * The medium state equation is instantiated with a reference
 * to a pointer variable holding current substance in the owner class,
 * and references to the medium state variables.
 *
 * The current substance is queried when the solve() method is called.
 * Thus, it is allowed to change the substance after instantiating
 * MediumStateEquation. However, the substance should be consistent
 * throughout the equation system solving process.
 *
 * If a substance is set (the substance pointer is non-@c NULL),
 * the solve() method calls MediumSubstance::solve() method of the used
 * substance. For more details, see the documentation of that method.
 *
 * If no substance is set (the substance pointer is @c NULL),
 * the solve() method simply returns @c true in order to remove
 * the equation from the system. In that case, it does not modify
 * any variables.
 */
class MediumStateEquation : public Equation
{
	Variable& _p;
	Variable& _T;
	Variable& _h;
	Variable& _s;
	Variable& _x;

	MediumSubstance*& _medium;

public:
	/**
	 * Instantiate a new MediumStateEquation.
	 *
	 * @param[in] subst_var A reference to the pointer variable holding
	 * the current substance.
	 * @param[in] p, T, h, s, x References to medium state variables.
	 */
	MediumStateEquation(MediumSubstance*& subst_var,
			Variable& p, Variable& T, Variable& h,
			Variable& s, Variable& x);

	virtual bool solve(double epsilon);
	virtual std::ostream& print_to(std::ostream& f) const;
};

#endif /*_PLANTCALC_EQUATIONS_MEDIUMSTATEEQUATION_HXX*/
