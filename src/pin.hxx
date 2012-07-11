/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_PIN_HXX
#define _PLANTCALC_PIN_HXX 1

#include "ids/deviceid.hxx"
#include "ids/pinid.hxx"
#include "util/methodbasediterable.hxx"
#include "variables/pinvariable.hxx"

#include <ostream>

class Pin
{
	friend std::ostream& operator<<(std::ostream& f, Pin& pin);

protected:
	PinID _pin_id;
	Pin(DeviceID& dev_id, const char* name);

	virtual PinVariable* iter_variable_get(int index) = 0;

public:
	virtual ~Pin();

	PinID& pin_id();

	typedef MethodBasedIterable<Pin, PinVariable> variable_iterable;
	variable_iterable variables();
};

std::ostream& operator<<(std::ostream& f, Pin& pin);

#endif /*_PLANTCALC_PIN_HXX*/
