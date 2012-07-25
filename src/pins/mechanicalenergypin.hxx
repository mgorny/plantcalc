/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_PINS_MECHANICALENERGYPIN_HXX
#define _PLANTCALC_PINS_MECHANICALENERGYPIN_HXX 1

#include "../pin.hxx"
#include "../variables/ownedvariable.hxx"

class MechanicalEnergyPin : public Pin
{
	OwnedVariable _P;

public:
	MechanicalEnergyPin(DeviceID& dev_id, const char* name);

	Variable& P();

	virtual variable_list_type variables();
};

#endif /*_PLANTCALC_PINS_MECHANICALENERGYPIN_HXX*/
