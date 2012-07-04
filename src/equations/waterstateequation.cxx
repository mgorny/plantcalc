/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "waterstateequation.hxx"
#include "../exceptions/contradictionerror.hxx"

#include <stdexcept>

#include <h2o>

WaterStateEquation::WaterStateEquation(Variable& p, Variable& T, Variable& h)
	: _p(p), _T(T), _h(h)
{
}

bool WaterStateEquation::solve()
{
	int count = _p.is_set() + _T.is_set() + _h.is_set();

	if (count > 2) // XXX: handle epsilon comparisons
		throw ContradictionError();
	else if (count < 2)
		return false;

	h2o::H2O state;

	if (_p.is_set() && _T.is_set())
		state = h2o::H2O::pT(_p, _T);
	else if (_p.is_set() && _h.is_set())
		state = h2o::H2O::ph(_p, _h);
	else
		throw std::runtime_error("Unsupported water state equation arguments.");

	if (!_T.is_set())
		_T.set_value(state.T());
	if (!_h.is_set())
		_h.set_value(state.h());

	return true;
}

std::ostream& WaterStateEquation::print_to(std::ostream& f) const
{
	return f << "<water state: "
		<< _p << ", " << _T << ", " << _h
		<< ">";

}
