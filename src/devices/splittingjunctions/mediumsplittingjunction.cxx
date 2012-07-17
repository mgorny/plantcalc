/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "mediumsplittingjunction.hxx"
#include "../common/splittingjunction.ixx"

template class SplittingJunction<MediumPin>;

MediumSplittingJunction::MediumSplittingJunction()
	: _p1_eq(_in.p(), _out1.p()),
	_p2_eq(_in.p(), _out2.p()),
	_h1_eq(_in.h(), _out1.h()),
	_h2_eq(_in.h(), _out2.h()),
	_mass_eq(1.0, _in.D(),
			-1.0, _out1.D(),
			-1.0, _out2.D())
{
}

EquationSystem MediumSplittingJunction::equations()
{
	EquationSystem ret;

	ret.push_back(&_p1_eq);
	ret.push_back(&_p2_eq);
	ret.push_back(&_h1_eq);
	ret.push_back(&_h2_eq);
	ret.push_back(&_mass_eq);

	return ret;
}
