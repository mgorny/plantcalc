/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATIONSOLVERS_SINGLEEQUATIONSOLVER_HXX
#define _PLANTCALC_EQUATIONSOLVERS_SINGLEEQUATIONSOLVER_HXX 1

#include "../equationsolver.hxx"

/**
 * A one-at-a-time equation solver.
 *
 * This is the simplest equation solver available. It just iterates over
 * all the equations in the system, and calls their Equation::solve()
 * method.
 *
 * The advantage of that method is that it works for all equation types.
 * The disadvantage: it can only solve equations which have only one
 * unknown at iteration time.
 *
 * Each call to iterate() performs a complete iteration over all
 * the equations. It is usually beneficial to perform more than a single
 * iteration (as long as iterate() method does not return @c false).
 */
class SingleEquationSolver : public EquationSolver
{
	EquationSystem& _eqs;
	double _epsilon;

public:
	/**
	 * Instantiate a new SingleEquationSolver.
	 *
	 * @param eqs The equation system to solve.
	 * @param epsilon The maximum absolute difference between two values
	 * to be considered equal.
	 */
	SingleEquationSolver(EquationSystem& eqs, double epsilon = 1E-6);

	virtual bool iterate();
};

#endif /*_PLANTCALC_EQUATIONSOLVERS_SINGLEEQUATIONSOLVER_HXX*/
