/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "h2omedium.hxx"
#include "../../exceptions/contradictionerror.hxx"

#include <stdexcept>

#include <h2o>

const char* H2OMedium::name() const
{
	return "water/steam";
}

bool H2OMedium::solve(Variable& p, Variable& T,
			Variable& h, Variable& s, Variable& x)
{
	int count = p.is_set() + T.is_set() + h.is_set()
		+ s.is_set() + x.is_set();

	if (count > 2) // XXX: handle epsilon comparisons
		throw ContradictionError();
	else if (count < 2)
		return false;

	h2o::H2O state;

	if (p.is_set() && T.is_set())
		state = h2o::H2O::pT(p, T);
	else if (p.is_set() && h.is_set())
		state = h2o::H2O::ph(p, h);
	else if (p.is_set() && s.is_set())
		state = h2o::H2O::ps(p, s);
	else if (p.is_set() && x.is_set())
		state = h2o::H2O::px(p, x);
	else if (T.is_set() && x.is_set())
		state = h2o::H2O::px(T, x);
	else
		throw std::runtime_error("Unsupported water state equation arguments.");

	if (!p.is_set())
		p.set_value(state.p());
	if (!T.is_set())
		T.set_value(state.T());
	if (!h.is_set())
		h.set_value(state.h());
	if (!s.is_set())
		s.set_value(state.s());
	if (!x.is_set()) // XXX: supercritical?
		x.set_value(state.x());

	return true;
}
