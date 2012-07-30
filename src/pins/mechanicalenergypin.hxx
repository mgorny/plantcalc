/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_PINS_MECHANICALENERGYPIN_HXX
#define PLANTCALC_PINS_MECHANICALENERGYPIN_HXX 1

#include "../pin.hxx"
#include "../variables/ownedvariable.hxx"

/**
 * A pin used to transfer mechanical energy.
 *
 * The MechanicalEnergyPin represents a pin which is used to transfer
 * mechanical energy. It defines a single variable P() for transferred
 * power.
 *
 * If the value of P() is positive, then the pin is producing mechanical
 * energy; if it is negative, it is consuming it.
 */
class MechanicalEnergyPin : public Pin
{
	OwnedVariable _P;

public:
	/**
	 * Instantiate a new MechanicalEnergyPin.
	 *
	 * @param[in] dev_id The pin owner (device) identifier.
	 * @param[in] name The pin name.
	 */
	MechanicalEnergyPin(const DeviceID& dev_id, const char* name);

	/**
	 * The power delivered by the pin [kW].
	 */
	Variable& P();

	virtual variable_list_type variables();
};

#endif /*_PLANTCALC_PINS_MECHANICALENERGYPIN_HXX*/
