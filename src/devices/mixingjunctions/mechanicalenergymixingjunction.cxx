/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "mechanicalenergymixingjunction.hxx"
#include "../common/mixingjunction.ixx"

template class MixingJunction<MechanicalEnergyPin>;

MechanicalEnergyMixingJunction::MechanicalEnergyMixingJunction()
	: _P_eq(1.0, _in1.P(),
			1.0, _in2.P(),
			-1.0, _out.P())
{
}

EquationSystem MechanicalEnergyMixingJunction::equations()
{
	EquationSystem ret;

	ret.push_back(&_P_eq);

	return ret;
}
