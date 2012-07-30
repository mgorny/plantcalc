/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_EQUATIONSOLVER_HXX
#define PLANTCALC_EQUATIONSOLVER_HXX 1

#include "equationsystem.hxx"

/**
 * An equation solver.
 *
 * The EquationSolver provides an abstract interface to any equation
 * solver.
 *
 * The equation solvers are bound to a specific system of equations when
 * constructed, and can perform a number of iterations trying to solve
 * that system. A single iteration is performed using the iterate()
 * method.
 *
 * The equation solvers are allowed to be stateful. If an equation
 * solver is stateful, the result of successive calls to the iterate()
 * method will depend on the previous calls. It is generally not a good
 * idea to modify the system of equations or variables used in it
 * between calls to the iterate() method.
 *
 * The equation solvers can support only a limited subset of equation
 * types. If a particular equation type is not supported by the solver,
 * it is omitted. It is necessary to use another solver to solve
 * the remaining equations then.
 */
class EquationSolver
{
public:
	virtual ~EquationSolver();

	/**
	 * Perform a single iteration trying to solve the system.
	 *
	 * If the solver succeeds in solving an equation, the variables
	 * referenced in that equation will be set and the equation will be
	 * removed from a system. If the solver is unable to solve
	 * a particular equation due to lack of data or unsupported equation
	 * type, the equation will be left unmodified.
	 *
	 * If the attempt at solving the equation results in contradictory
	 * values for a variable, a ContradictionError will be thrown.
	 * The incorrect values can be written to variables already. It is
	 * however guaranteed that the contradictory equations will be left
	 * in the system and thus the successive calls to the iterate()
	 * method will trigger a ContradictionError as well.
	 *
	 * Note that unsupported equation types (if any) are simply skipped
	 * by the equation solver, and they can trigger a delayed
	 * ContradictionError when reached by another solver (with variable
	 * values set by a previous iterate() call).
	 *
	 * @returns @c true if another iteration should be performed,
	 * @c false otherwise. Note that the solver can return @c true even
	 * after solving all equations; however, it must return @c false
	 * when called on an empty system of equations.
	 */
	virtual bool iterate() = 0;
};

#endif /*_PLANTCALC_EQUATIONSOLVER_HXX*/
