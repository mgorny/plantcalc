/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_MIXINGJUNCTIONS_MECHANICALENERGYMIXINGJUNCTION_HXX
#define _PLANTCALC_DEVICES_MIXINGJUNCTIONS_MECHANICALENERGYMIXINGJUNCTION_HXX 1

#include "../common/mixingjunction.hxx"
#include "../../equations/linearequation.hxx"
#include "../../pins/mechanicalenergypin.hxx"

class MechanicalEnergyMixingJunction : public MixingJunction<MechanicalEnergyPin>
{
	LinearEquation _P_eq;

public:
	MechanicalEnergyMixingJunction();

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_DEVICES_MIXINGJUNCTIONS_MECHANICALENERGYMIXINGJUNCTION_HXX*/
