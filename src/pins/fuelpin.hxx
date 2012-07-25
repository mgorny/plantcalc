/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_PINS_FUELPIN_HXX
#define _PLANTCALC_PINS_FUELPIN_HXX 1

#include "../pin.hxx"
#include "../variables/ownedvariable.hxx"

class FuelPin : public Pin
{
	OwnedVariable _Q, _B, _Qw;

public:
	FuelPin(DeviceID& dev_id, const char* name);

	virtual ~FuelPin();

	Variable& Q();
	Variable& B();
	Variable& Qw();

	virtual variable_list_type variables();
};

#endif /*_PLANTCALC_PINS_FUELPIN_HXX*/
