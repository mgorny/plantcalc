/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATIONS_LINEAREQUATION_HXX
#define _PLANTCALC_EQUATIONS_LINEAREQUATION_HXX 1

#include "../equation.hxx"
#include "../variable.hxx"

#include <vector>

class LinearEquation : public Equation
{
	struct list_elem_type
	{
		double coefficient;
		Variable* variable;
	};
	typedef std::vector<list_elem_type> list_type;

	list_type _vars;

protected:
	virtual std::ostream& print_to(std::ostream& f) const;

public:
	LinearEquation();

	void update(double coefficient, Variable& v);
	virtual bool solve();
};

#endif /*_PLANTCALC_EQUATIONS_LINEAREQUATION_HXX*/
