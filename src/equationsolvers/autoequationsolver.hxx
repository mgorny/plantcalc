/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATIONSOLVERS_AUTOEQUATIONSOLVER_HXX
#define _PLANTCALC_EQUATIONSOLVERS_AUTOEQUATIONSOLVER_HXX 1

#include "../equationsolver.hxx"
#include "linearequationsolver.hxx"
#include "singleequationsolver.hxx"

/**
 * An automated, coupled equation solver.
 *
 * The AutoEquationSolver provides a simple coupling
 * of SingleEquationSolver and LinearEquationSolver. This means that
 * AutoEquationSolver can solve both systems of linear equations,
 * and single equations of other types.
 *
 * The AutoEquationSolver class is semi-stateful. The successive
 * iterations will first repeatedly call SingleEquationSolver::iterate()
 * (until it returns @c false), and then LinearEquationSolver::iterate()
 * will be called once. Afterwards, the cycle will be repeated.
 */
class AutoEquationSolver : public EquationSolver
{
	LinearEquationSolver _linear_solver;
	SingleEquationSolver _single_solver;

	bool _single_done;

public:
	/**
	 * Instantiate a new AutoEquationSolver.
	 *
	 * @param[in,out] eqs The equation system to solve.
	 * @param[in] epsilon The maximum absolute difference between
	 * two values to be considered equal.
	 */
	AutoEquationSolver(EquationSystem& eqs, double epsilon = 1E-6);

	virtual bool iterate();
};

#endif /*_PLANTCALC_EQUATIONSOLVERS_AUTOEQUATIONSOLVER_HXX*/
