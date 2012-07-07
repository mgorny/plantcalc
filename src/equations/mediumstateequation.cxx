/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "mediumstateequation.hxx"

#include <stdexcept>

MediumStateEquation::MediumStateEquation(MediumSubstance*& subst_var,
		Variable& p, Variable& T, Variable& h,
		Variable& s, Variable& x)
	: _p(p), _T(T), _h(h), _s(s), _x(x), _medium(subst_var)
{
}

bool MediumStateEquation::solve()
{
	if (!_medium)
		return true;

	return _medium->solve(_p, _T, _h, _s, _x);
}

std::ostream& MediumStateEquation::print_to(std::ostream& f) const
{
	const char* m_name = "unknown medium";

	if (_medium)
		m_name = _medium->name();

	return f << "<" << m_name << " state: "
		<< _p << ", " << _T << ", " << _h << ", "
		<< _s << ", " << _x << ">";
}
