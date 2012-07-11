/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICE_HXX
#define _PLANTCALC_DEVICE_HXX 1

#include "equationsystem.hxx"
#include "pin.hxx"
#include "ids/deviceid.hxx"
#include "util/methodbasediterable.hxx"

class Device
{
protected:
	DeviceID _device_id;
	Device(const char* name);

	virtual Pin* iter_pin_get(int index) = 0;

public:
	virtual ~Device();

	virtual EquationSystem equations() = 0;

	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const = 0;

	DeviceID& device_id();

	MethodBasedIterable<Device, Pin> pins();
};

#endif /*_PLANTCALC_DEVICE_HXX*/
