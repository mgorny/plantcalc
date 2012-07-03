/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "equationsystem.hxx"

EquationSystem::EquationSystem()
{
}

std::ostream& operator <<(std::ostream& f, const EquationSystem& eqs)
{
	EquationSystem::const_iterator it;
	std::ostream* fp = &f;

	for (it = eqs.begin(); it != eqs.end(); ++it)
		fp = &(*fp << "{ " << **it << "\n");

	return *fp;
}

EquationSystem& EquationSystem::operator+=(const EquationSystem& rhs)
{
	EquationSystem::const_iterator it;

	reserve(size() + rhs.size());
	for (it = rhs.begin(); it != rhs.end(); ++it)
		push_back(*it);

	return *this;
}
