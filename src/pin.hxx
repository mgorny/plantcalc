/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_PIN_HXX
#define _PLANTCALC_PIN_HXX 1

#include "ids/deviceid.hxx"
#include "ids/pinid.hxx"

class Pin
{
protected:
	PinID _pin_id;
	Pin(DeviceID& dev_id, const char* name);

public:
	virtual ~Pin();
};

#endif /*_PLANTCALC_PIN_HXX*/
