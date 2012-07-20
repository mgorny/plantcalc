/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_PIN_HXX
#define _PLANTCALC_PIN_HXX 1

#include "ids/deviceid.hxx"
#include "ids/pinid.hxx"
#include "variables/pinvariable.hxx"

#include <ostream>
#include <vector>

class Pin
{
	friend std::ostream& operator<<(std::ostream& f, Pin& pin);

public:
	typedef std::vector<PinVariable*> variable_list_type;

protected:
	PinID _pin_id;
	Pin(DeviceID& dev_id, const char* name);

public:
	virtual ~Pin();

	PinID& pin_id();

	virtual variable_list_type variables() = 0;
};

std::ostream& operator<<(std::ostream& f, Pin& pin);

#endif /*_PLANTCALC_PIN_HXX*/
