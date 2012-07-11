/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_PIN_HXX
#define _PLANTCALC_PIN_HXX 1

#include "variable.hxx"
#include "ids/deviceid.hxx"
#include "ids/pinid.hxx"
#include "util/methodbasediterable.hxx"

class Pin
{
protected:
	PinID _pin_id;
	Pin(DeviceID& dev_id, const char* name);

	virtual Variable* iter_variable_get(int index) = 0;

public:
	virtual ~Pin();

	PinID& pin_id();

	MethodBasedIterable<Pin, Variable> variables();
};

#endif /*_PLANTCALC_PIN_HXX*/
