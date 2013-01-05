/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "approximatemediummixingjunction.hxx"
#include "../common/mixingjunction.ixx"

template class MixingJunction<MediumPin>;

ApproximateMediumMixingJunction::ApproximateMediumMixingJunction(const char* name)
	: MixingJunction<MediumPin>(name),
	_mass_eq(1.0, _in1.D(),
			1.0, _in2.D(),
			1.0, _out.D()),
	_p_eq(_in1.p(), _out.p()),
	_h_eq(_in1.h(), _out.h())
{
}

EquationSystem ApproximateMediumMixingJunction::equations()
{
	EquationSystem ret;

	ret.push_back(&_mass_eq);
	ret.push_back(&_p_eq);
	ret.push_back(&_h_eq);

	return ret;
}
