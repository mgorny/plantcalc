/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_BOILER_HXX
#define _PLANTCALC_DEVICES_BOILER_HXX 1

#include "common/mediumflowdevice.hxx"
#include "../pins/fuelpin.hxx"
#include "../variables/ownedvariable.hxx"

/**
 * A boiler (medium heating device).
 *
 * The Boiler class provides a simple boiler model where heat obtained
 * through incinerating fuel is delivered to the medium.
 *
 * The following equation is used for the heat exchange:
 *
 * @f[
 * D ( h_{out} - h_{in} ) = Q_{ch} \eta
 * @f]
 *
 * where @f$ D @f$ is the medium flux, @f$ h_{out} - h_{in} @f$ is
 * the difference between specific enthalpy of outlet and inlet
 * medium, @f$ Q_{ch} @f$ is the chemical energy obtained from fuel
 * (through fuel_in()) and @f$ \eta @f$ is the efficiency.
 */
class Boiler : public MediumFlowDevice
{
	OwnedVariable _efficiency;

	FuelPin _fuel_in;
	LinearEquation _energy_balance_eq;

public:
	/**
	 * Instantiate a new Boiler.
	 *
	 * @param[in] efficiency The boiler efficiency (determines the heat
	 * loss).
	 */
	Boiler(double efficiency = 1);
	/**
	 * Instantiate a new Boiler and set output parameters.
	 *
	 * @param[in] efficiency The boiler efficiency (determines the heat
	 * loss).
	 * @param[in] pout Initial output pressure [MPa].
	 * @param[in] Tout Initial output temperature [K].
	 */
	Boiler(double efficiency, double pout, double Tout);

	/**
	 * The boiler effiency.
	 *
	 * The efficiency is used to calculate the amount of chemical
	 * energy required to heat the medium.
	 */
	Variable& efficiency();

	/**
	 * The fuel input pin.
	 */
	FuelPin& fuel_in();

	virtual EquationSystem equations();

	virtual pin_list_type pins();
	virtual variable_list_type variables();
};

#endif /*_PLANTCALC_DEVICES_BOILER_HXX*/
