/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "waterstateequation.hxx"

WaterStateEquation::WaterStateEquation(Variable& p, Variable& T, Variable& h,
			Variable& s, Variable& x)
	: _p(p), _T(T), _h(h), _s(s), _x(x)
{
}

bool WaterStateEquation::solve()
{
	return _medium.solve(_p, _T, _h, _s, _x);
}

std::ostream& WaterStateEquation::print_to(std::ostream& f) const
{
	return f << "<water state: "
		<< _p << ", " << _T << ", " << _h << ", "
		<< _s << ", " << _x << ">";

}
