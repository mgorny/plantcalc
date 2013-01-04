/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "fuelsplittingjunction.hxx"
#include "../common/splittingjunction.ixx"

template class SplittingJunction<FuelPin>;

FuelSplittingJunction::FuelSplittingJunction()
	: _Qw1_eq(_in.Qw(), _out1.Qw()),
	_Qw2_eq(_in.Qw(), _out2.Qw()),
	_energy_eq(1.0, _in.Q(),
			1.0, _out1.Q(),
			1.0, _out2.Q())
{
}

EquationSystem FuelSplittingJunction::equations()
{
	EquationSystem ret;

	ret.push_back(&_Qw1_eq);
	ret.push_back(&_Qw2_eq);
	ret.push_back(&_energy_eq);

	return ret;
}
