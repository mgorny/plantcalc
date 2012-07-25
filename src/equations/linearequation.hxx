/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATIONS_LINEAREQUATION_HXX
#define _PLANTCALC_EQUATIONS_LINEAREQUATION_HXX 1

#include "../equation.hxx"
#include "../variable.hxx"
#include "../equationsolvers/linearequationsolver.hxx"

#include <vector>

/**
 * A linear equation with ability to solve products of two variables.
 *
 * The LinearEquation class can be used to represent linear equations
 * with either one or two variables in a term (in the latter case, one
 * of the variables is a 'coefficient variable').
 *
 * In other words, this class can represent equations like:
 *
 * @f[
 * a_1 x_1 y_1 + a_2 x_2 y_2 + ... + a_n x_n y_n
 * @f]
 *
 * where @f$ a_i @f$ is a @c double constant, @f$ x_i @f$ is a variable
 * and @f$ y_i @f$ is either a variable or 1.0 (it is optional).
 *
 * Note that when using two variables, at least one of them must be set
 * in order for the equation to be solved (it is inlined into
 * the coefficient).
 *
 * The constructors take a number of coefficient-variable pairs
 * or triples representing successive equation terms. If a constant
 * alone (without any variable) has to appear in the equation,
 * the Constant class has to be used (with a coefficient of @c 1.0
 * or @c -1.0).
 */
class LinearEquation : public Equation
{
	struct list_elem_type
	{
		double coefficient;
		Variable* variable1;
		Variable* variable2;
	};
	typedef std::vector<list_elem_type> list_type;

	list_type _vars;

	friend class LinearEquationSolver;

protected:
	virtual std::ostream& print_to(std::ostream& f) const;

	/**
	 * Add an @f$ a_i x_i @f$ term to the equation.
	 *
	 * Note that this method does not check for duplicates,
	 * and having duplicates (more than one term with the same variable)
	 * is not allowed.
	 */
	void push_back(double coefficient, Variable& v);
	/**
	 * Add an @f$ a_i x_i y_i @f$ term to the equation.
	 *
	 * Note that this method does not check for duplicates,
	 * and having duplicates (more than one term with the same
	 * variables) is not allowed.
	 */
	void push_back(double coefficient, Variable& v1, Variable& v2);

public:
	LinearEquation(double c1, Variable& v1, double c2, Variable& v2);
	LinearEquation(double c1, Variable& v1,
			double c2, Variable& v2a, Variable& v2b);
	LinearEquation(double c1, Variable& v1,
			double c2, Variable& v2,
			double c3, Variable& v3);
	LinearEquation(double c1, Variable& v1,
			double c2, Variable& v2a, Variable& v2b,
			double c3, Variable& v3a, Variable& v3b);
	LinearEquation(double c1, Variable& v1a, Variable& v1b,
			double c2, Variable& v2a, Variable& v2b,
			double c3, Variable& v3a, Variable& v3b);
	LinearEquation(double c1, Variable& v1a, Variable& v1b,
			double c2, Variable& v2a, Variable& v2b,
			double c3, Variable& v3a, Variable& v3b,
			double c4, Variable& v4a, Variable& v4b);

	virtual bool solve(double epsilon);
};

#endif /*_PLANTCALC_EQUATIONS_LINEAREQUATION_HXX*/
