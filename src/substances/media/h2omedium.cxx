/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "h2omedium.hxx"
#include "../../exceptions/contradictionerror.hxx"

#include <cmath>
#include <stdexcept>

#include <h2o>

const char* H2OMedium::name() const
{
	return "water/steam";
}

bool H2OMedium::solve(Variable& p, Variable& T,
			Variable& h, Variable& s, Variable& x,
			double epsilon)
{
	h2o::H2O state;
	bool used_p = false, used_T = false, used_h = false,
		used_s = false, used_x = false;

	if (p.is_set())
	{
		used_p = true;

		if (T.is_set())
		{
			used_T = true;
			state = h2o::H2O::pT(p, T);
		}
		else if (h.is_set())
		{
			used_h = true;
			state = h2o::H2O::ph(p, h);
		}
		else if (s.is_set())
		{
			used_s = true;
			state = h2o::H2O::ps(p, s);
		}
		else if (x.is_set())
		{
			used_x = true;
			state = h2o::H2O::px(p, x);
		}
		else
			return false;
	}
	else if (T.is_set() && x.is_set())
	{
		used_T = true;
		used_x = true;
		state = h2o::H2O::Tx(T, x);
	}
	else
		return false;

	if (!p.is_set())
		p.set_value(state.p());
	else if (!used_p && std::abs(state.p() - p) >= epsilon)
		throw ContradictionError();
	if (!T.is_set())
		T.set_value(state.T());
	else if (!used_T && std::abs(state.T() - T) >= epsilon)
		throw ContradictionError();
	if (!h.is_set())
		h.set_value(state.h());
	else if (!used_h && std::abs(state.h() - h) >= epsilon)
		throw ContradictionError();
	if (!s.is_set())
		s.set_value(state.s());
	else if (!used_s && std::abs(state.s() - s) >= epsilon)
		throw ContradictionError();
	if (!x.is_set()) // XXX: supercritical?
		x.set_value(state.x());
	else if (!used_x && std::abs(state.x() - x) >= epsilon)
		throw ContradictionError();

	return true;
}
