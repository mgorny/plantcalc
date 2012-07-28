/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_SUBSTANCES_MEDIUMSUBSTANCE_HXX
#define _PLANTCALC_SUBSTANCES_MEDIUMSUBSTANCE_HXX 1

#include "../substance.hxx"
#include "../variable.hxx"

/**
 * A substance for thermodynamic medium.
 *
 * A substance for a MediumConnection. A MediumStance provides routines
 * to correlate various medium properties through the solve() method
 * (which is used by MediumStateEquation).
 */
class MediumSubstance : public Substance
{
public:
	/**
	 * Try to solve the medium state equation using the available state
	 * variables and set the remaining ones.
	 *
	 * The exact details of the equation and the method of solving it
	 * depend on the particular substance.
	 *
	 * @param p, T, h, s, x The medium parameter variables.
	 * @param epsilon Allowed absolute difference between two
	 * variable values considered equal.
	 *
	 * @returns @c true on success, @c false on insufficient data.
	 * @throws ContradictionError if the variable values
	 * are contradictory.
	 */
	virtual bool solve(Variable& p, Variable& T,
			Variable& h, Variable& s, Variable& x,
			double epsilon) const = 0;
};

#endif /*_PLANTCALC_SUBSTANCES_MEDIUMSUBSTANCE_HXX*/
