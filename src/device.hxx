/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICE_HXX
#define _PLANTCALC_DEVICE_HXX 1

#include "equationsystem.hxx"
#include "ids/deviceid.hxx"

class Device
{
protected:
	DeviceID _device_id;
	Device(const char* name);

public:
	virtual ~Device();

	virtual EquationSystem equations() = 0;
};

#endif /*_PLANTCALC_DEVICE_HXX*/
