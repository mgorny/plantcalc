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

class Boiler : public MediumFlowDevice
{
	OwnedVariable _efficiency;

	FuelPin _fuel_in;
	LinearEquation _energy_balance_eq;

public:
	Boiler(double efficiency = 1);
	Boiler(double efficiency, double pout, double Tout);

	Variable& efficiency();

	FuelPin& fuel_in();

	virtual EquationSystem equations();

	virtual pin_list_type pins();
	virtual variable_list_type variables();
};

#endif /*_PLANTCALC_DEVICES_BOILER_HXX*/
