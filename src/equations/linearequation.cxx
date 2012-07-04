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

		if (li.variable == &v)
		{
			li.coefficient = coefficient;
			return;
		}
	}

	list_elem_type li = {coefficient, &v};
	_vars.push_back(li);
}

bool LinearEquation::solve()
{
	list_type::iterator it;
	Variable* dest_var = 0;
	double dest_coeff;

	for (it = _vars.begin(); it != _vars.end(); ++it)
	{
		list_elem_type& el = *it;

		if (!el.variable->is_set())
		{
			if (!dest_var) // single unset
			{
				dest_var = el.variable;
				dest_coeff = el.coefficient;
			}
			else // more unset
				return false;
		}
	}

	double val = 0;

	for (it = _vars.begin(); it != _vars.end(); ++it)
	{
		list_elem_type& el = *it;

		if (el.variable->is_set())
			val += el.coefficient * *el.variable;
		else
			assert(el.variable == dest_var);
	}

	if (!dest_var)
	{
		const double epsilon = 1E-6;

		if (std::abs(val) >= epsilon)
			throw ContradictionError();

		return true;
	}

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

		fp = &(*fp << li.coefficient << " " << *li.variable);

		if (++it != _vars.end())
			fp = &(*fp << " + ");
	}

	return *fp << " = 0";
}
