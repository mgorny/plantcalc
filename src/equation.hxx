/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATION_HXX
#define _PLANTCALC_EQUATION_HXX 1

#include <ostream>
#include <exception>

/**
 * A single equation.
 *
 * The Equation class represents a single equation which can be
 * referenced in an EquationSystem.
 *
 * Each equation provides a solve() method which performs an attempt to
 * solve the equation. EquationSolver derived classes can provide
 * additional equation solving methods.
 */
class Equation
{
	friend std::ostream& operator <<(std::ostream& f, const Equation& eq);

protected:
	/**
	 * Print the textual representation of the equation to stream @a f.
	 *
	 * This method is to be overriden in derived classes.
	 */
	virtual std::ostream& print_to(std::ostream& f) const = 0;

public:
	virtual ~Equation();

	/**
	 * Attempt to solve the equation using the current variable values.
	 *
	 * If successful, remaining variables are set and @c true is
	 * returned. If the equation can not be solved because of
	 * insufficient data (too many unknowns), @c false is returned
	 * and variables are not modified.
	 *
	 * If an attempt to solve the equation results in a contradictory
	 * values for a variable, a ContradictionError is thrown. Unset
	 * variables referenced in the equation may be set to incorrect
	 * values or left unset.
	 *
	 * @returns @c true on success, @c false on insufficient data.
	 * @throws ContradictionError if the variable values
	 * are contradictory.
	 */
	virtual bool solve(double epsilon) = 0;
};

/**
 * Print the textual representation of the equation.
 *
 * The output will include printed variables with their values.
 */
std::ostream& operator <<(std::ostream& f, const Equation& eq);

#endif /*_PLANTCALC_EQUATION_HXX*/
