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

	void push_back(double coefficient, Variable& v);
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
