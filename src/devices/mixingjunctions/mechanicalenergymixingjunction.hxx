/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_MIXINGJUNCTIONS_MECHANICALENERGYMIXINGJUNCTION_HXX
#define PLANTCALC_DEVICES_MIXINGJUNCTIONS_MECHANICALENERGYMIXINGJUNCTION_HXX 1

#include "../common/mixingjunction.hxx"
#include "../../equations/linearequation.hxx"
#include "../../pins/mechanicalenergypin.hxx"

/**
 * A mechanical energy mixing junction.
 *
 * The MechanicalEnergyMixingJunction class provides a simple mixing
 * junction for mechanical energy connections.
 */
class MechanicalEnergyMixingJunction : public MixingJunction<MechanicalEnergyPin>
{
	LinearEquation _P_eq;

public:
	/**
	 * Instantiate a new MechanicalEnergyMixingJunction.
	 *
	 * @param[in] name The junction name.
	 */
	MechanicalEnergyMixingJunction(const char* name);

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_DEVICES_MIXINGJUNCTIONS_MECHANICALENERGYMIXINGJUNCTION_HXX*/
