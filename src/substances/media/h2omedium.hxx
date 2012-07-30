/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_SUBSTANCES_MEDIA_H2OMEDIUM_HXX
#define PLANTCALC_SUBSTANCES_MEDIA_H2OMEDIUM_HXX 1

#include "../mediumsubstance.hxx"

/**
 * Water/steam medium.
 *
 * A water/steam substance for a MediumConnection.
 */
class H2OMedium : public MediumSubstance
{
public:
	virtual const char* name() const;

	/**
	 * Try to solve the medium state equation using the available state
	 * variables and set the remaining ones.
	 *
	 * In order for the equation to be solvable, one of the following
	 * parameter pairs need to be available:
	 *
	 * - (p, T),
	 * - (p, h),
	 * - (p, s),
	 * - (p, x),
	 * - (T, x),
	 * - (h, s).
	 *
	 * If none of these pairs is available, the method returns @c false
	 * without modifying any of the variables. If more than a single
	 * listed pair is available, it is undefined which one will be used
	 * (and thus the actual calculation results may be undefined).
	 *
	 * Note that the (p, T) pair can only express liquid and dry vapor
	 * states. On the saturation line, it is undefined whether a
	 * particular point will be considered liquid or vapor.
	 *
	 * Also note that the (p, x) and (T, x) pairs can only express
	 * points on the saturation line (wet vapor).
	 *
	 * Considering the above, it is invalid to call solve() with p, T
	 * and x being set. It is undefined whether such a call will use
	 * the (p, T) pair (effectively ignoring x), (p, x) or (T, x)
	 * (effectively moving the point to the saturation line). The result
	 * of that may be either a correct value or a ContradictionError.
	 *
	 * @param[in,out] p, T, h, s, x The medium parameter variables.
	 * @param[in] epsilon Allowed absolute difference between
	 * two variable values considered equal.
	 *
	 * @returns @c true on success, @c false on insufficient data.
	 * @throws ContradictionError if the variable values
	 * are contradictory.
	 */
	virtual bool solve(Variable& p, Variable& T,
			Variable& h, Variable& s, Variable& x,
			double epsilon) const;
};

#endif /*_PLANTCALC_SUBSTANCES_MEDIA_H2OMEDIUM_HXX*/
