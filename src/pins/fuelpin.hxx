/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_PINS_FUELPIN_HXX
#define _PLANTCALC_PINS_FUELPIN_HXX 1

#include "../pin.hxx"
#include "../variables/ownedvariable.hxx"

/**
 * A pin used to transfer fuel.
 *
 * The FuelPin represents a pin which is used to transfer chemical
 * energy contained in fuel.
 *
 * The flux of chemical energy is expressed through the Q() variable. It
 * is a product of fuel flux (B()) and the LHV (Qw()).
 *
 * If the particular pin is delivering fuel (energy), the values of both
 * Q() and B() are positive. If it is consuming it, they are negative.
 */
class FuelPin : public Pin
{
	OwnedVariable _Q, _B, _Qw;

public:
	/**
	 * Instantiate a new FuelPin.
	 *
	 * @param[in] dev_id The pin owner (device) identifier.
	 * @param[in] name The pin name.
	 */
	FuelPin(const DeviceID& dev_id, const char* name);

	/**
	 * The energy flux delivered by the pin [kJ/s].
	 */
	Variable& Q();
	/**
	 * The fuel flux delivered by the pin [kg/s or m3/s].
	 */
	Variable& B();
	/**
	 * The LHV of the fuel [kJ/kg or kJ/m3].
	 */
	Variable& Qw();

	virtual variable_list_type variables();
};

#endif /*_PLANTCALC_PINS_FUELPIN_HXX*/
