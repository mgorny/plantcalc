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

LinearEquation::LinearEquation()
{
}

void LinearEquation::update(double coefficient, Variable& v)
{
	list_type::iterator it;

	for (it = _vars.begin(); it != _vars.end(); ++it)
	{
		list_elem_type& li = *it;

		if (li.variable1 == &v && !li.variable2)
		{
			li.coefficient = coefficient;
			return;
		}
	}

	list_elem_type li = {coefficient, &v, 0};
	_vars.push_back(li);
}

void LinearEquation::update(double coefficient, Variable& v1, Variable& v2)
{
	list_type::iterator it;

	for (it = _vars.begin(); it != _vars.end(); ++it)
	{
		list_elem_type& li = *it;

		if (li.variable1 == &v1 && li.variable2 == &v2)
		{
			li.coefficient = coefficient;
			return;
		}
	}

	list_elem_type li = {coefficient, &v1, &v2};
	_vars.push_back(li);
}

bool LinearEquation::solve()
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
		const double epsilon = 1E-6;

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
