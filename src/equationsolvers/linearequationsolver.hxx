/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATIONSOLVERS_LINEAREQUATIONSOLVER_HXX
#define _PLANTCALC_EQUATIONSOLVERS_LINEAREQUATIONSOLVER_HXX 1

#include "../equationsolver.hxx"

/**
 * A linear equation solver.
 *
 * The LinearEquationSolver is a matrix-based solver for linear
 * equations. It collects all linear equations in the system, creates
 * a matrix of their coefficients and uses Eigen to get the solution.
 *
 * It is never necessary to perform more than a single successive
 * iteration with this solver. However, it may be desirable to do that
 * after successfully using another solver.
 *
 * This solver supports LinearEquation and derived classes only.
 * It usually needs to be coupled with a more universal equation solver.
 *
 * Note that if two variable product is used in a term of linear
 * equation, one of the variables must be set. Otherwise, the solver
 * will skip that equation.
 */
class LinearEquationSolver : public EquationSolver
{
	EquationSystem& _eqs;
	double _epsilon;

public:
	/**
	 * Instantiate a new LinearEquationSolver.
	 *
	 * @param[in,out] eqs The equation system to solve.
	 * @param[in] epsilon The maximum absolute difference between
	 * two values to be considered equal.
	 */
	LinearEquationSolver(EquationSystem& eqs, double epsilon = 1E-6);

	virtual bool iterate();
};

#endif /*_PLANTCALC_EQUATIONSOLVERS_LINEAREQUATIONSOLVER_HXX*/
