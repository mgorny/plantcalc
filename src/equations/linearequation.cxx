/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "linearequation.hxx"

LinearEquation::LinearEquation()
{
}

void LinearEquation::add(double coefficient, Variable& v)
{
	list_type::iterator it;

	for (it = _vars.begin(); it != _vars.end(); ++it)
	{
		list_elem_type& li = *it;

		if (li.variable == &v)
		{
			li.coefficient += coefficient;
			return;
		}
	}

	list_elem_type li = {coefficient, &v};
	_vars.push_back(li);
}

bool LinearEquation::solve()
{
	return false; // XXX
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
