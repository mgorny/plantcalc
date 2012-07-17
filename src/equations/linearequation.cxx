/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "linearequation.hxx"
#include "../exceptions/contradictionerror.hxx"

#include <cassert>
#include <cmath>

LinearEquation::LinearEquation(double c1, Variable& v1, double c2, Variable& v2)
{
	push_back(c1, v1);
	push_back(c2, v2);
}

LinearEquation::LinearEquation(double c1, Variable& v1,
		double c2, Variable& v2a, Variable& v2b)
{
	push_back(c1, v1);
	push_back(c2, v2a, v2b);
}

LinearEquation::LinearEquation(double c1, Variable& v1,
		double c2, Variable& v2,
		double c3, Variable& v3)
{
	push_back(c1, v1);
	push_back(c2, v2);
	push_back(c3, v3);
}

LinearEquation::LinearEquation(double c1, Variable& v1,
		double c2, Variable& v2a, Variable& v2b,
		double c3, Variable& v3a, Variable& v3b)
{
	push_back(c1, v1);
	push_back(c2, v2a, v2b);
	push_back(c3, v3a, v3b);
}

LinearEquation::LinearEquation(double c1, Variable& v1a, Variable& v1b,
		double c2, Variable& v2a, Variable& v2b,
		double c3, Variable& v3a, Variable& v3b)
{
	push_back(c1, v1a, v1b);
	push_back(c2, v2a, v2b);
	push_back(c3, v3a, v3b);
}

LinearEquation::LinearEquation(double c1, Variable& v1a, Variable& v1b,
		double c2, Variable& v2a, Variable& v2b,
		double c3, Variable& v3a, Variable& v3b,
		double c4, Variable& v4a, Variable& v4b)
{
	push_back(c1, v1a, v1b);
	push_back(c2, v2a, v2b);
	push_back(c3, v3a, v3b);
	push_back(c4, v4a, v4b);
}

void LinearEquation::push_back(double coefficient, Variable& v)
{
	list_elem_type li = {coefficient, &v, 0};
	_vars.push_back(li);
}

void LinearEquation::push_back(double coefficient, Variable& v1, Variable& v2)
{
	list_elem_type li = {coefficient, &v1, &v2};
	_vars.push_back(li);
}

bool LinearEquation::solve(double epsilon)
{
	list_type::iterator it;
	Variable* dest_var = 0;
	Variable* dest_coeff_var = 0;
	double dest_coeff;

	for (it = _vars.begin(); it != _vars.end(); ++it)
	{
		list_elem_type& el = *it;

		if (!el.variable1->is_set())
		{
			if (!dest_var) // single unset
			{
				dest_var = el.variable1;
				dest_coeff_var = el.variable2;
				dest_coeff = el.coefficient;
			}
			else // more unset
				return false;
		}
		else if (el.variable2 && !el.variable2->is_set())
		{
			if (!dest_var) // single unset
			{
				dest_var = el.variable2;
				dest_coeff_var = el.variable1;
				dest_coeff = el.coefficient;
			}
			else // more unset
				return false;
		}

		// the other variable must be set
		if (dest_coeff_var && !dest_coeff_var->is_set())
			return false;
	}

	double val = 0;

	for (it = _vars.begin(); it != _vars.end(); ++it)
	{
		list_elem_type& el = *it;

		if (!el.variable1->is_set())
			assert(el.variable1 == dest_var);
		else
		{
			if (el.variable2)
			{
				if (!el.variable2->is_set())
					assert(el.variable2 == dest_var);
				else
					val += el.coefficient * *el.variable1 * *el.variable2;
			}
			else
				val += el.coefficient * *el.variable1;
		}
	}

	if (!dest_var)
	{
		if (std::abs(val) >= epsilon)
			throw ContradictionError();

		return true;
	}

	if (dest_coeff_var)
		dest_coeff *= *dest_coeff_var;
	val /= -dest_coeff;
	dest_var->set_value(val);

	return true;
}

std::ostream& LinearEquation::print_to(std::ostream& f) const
{
	list_type::const_iterator it;
	std::ostream* fp = &f;

	for (it = _vars.begin(); it != _vars.end();)
	{
		const list_elem_type& li = *it;

		fp = &(*fp << li.coefficient << " " << *li.variable1);

		if (li.variable2)
			fp = &(*fp << " * " << *li.variable2);

		if (++it != _vars.end())
			fp = &(*fp << " + ");
	}

	return *fp << " = 0";
}
