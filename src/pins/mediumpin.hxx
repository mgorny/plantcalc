/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_PINS_MEDIUMPIN_HXX
#define _PLANTCALC_PINS_MEDIUMPIN_HXX 1

#include "../pin.hxx"
#include "../variables/ownedvariable.hxx"

/**
 * A pin used to transfer energy through medium flow.
 *
 * The MediumPin represents a pin which is used to transfer energy
 * contained in medium (enthalpy).
 *
 * The flux of the medium is expressed through the D() variable.
 * The specific energy is expressed via specific enthalpy h().
 *
 * If the medium is flowing out of the particular pin, the value
 * of the flux is positive. Otherwise, it is negative.
 */
class MediumPin : public Pin
{
	OwnedVariable _p, _T, _h, _s, _x, _D;

public:
	/**
	 * Instantiate a new MediumPin.
	 *
	 * @param[in] dev_id The pin owner (device) identifier.
	 * @param[in] name The pin name.
	 */
	MediumPin(DeviceID& dev_id, const char* name);
	/**
	 * Instantiate a new MediumPin and preset the pressure
	 * and temperature.
	 *
	 * @param[in] dev_id The pin owner (device) identifier.
	 * @param[in] name The pin name.
	 * @param[in] p The initial pressure [MPa].
	 * @param[in] T The initial temperature [K].
	 */
	MediumPin(DeviceID& dev_id, const char* name, double p, double T);

	/**
	 * The pressure [MPa].
	 */
	Variable& p();
	/**
	 * The temperature [K].
	 */
	Variable& T();
	/**
	 * The specific enthalpy [kJ/kg].
	 */
	Variable& h();
	/**
	 * The specific enthropy [kJ/kgK].
	 */
	Variable& s();
	/**
	 * The dryness.
	 *
	 * The dryness is 0 for liquid, and 1 for vapor. For supercritical
	 * fluids, the dryness is undefined (and thus should be unset).
	 */
	Variable& x();
	/**
	 * The medium flux [kg/s].
	 */
	Variable& D();

	virtual variable_list_type variables();
};

#endif /*_PLANTCALC_PINS_MEDIUMPIN_HXX*/
