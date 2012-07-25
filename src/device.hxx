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
#include "variables/ownedvariable.hxx"

#include <vector>

class Device
{
public:
	typedef std::vector<OwnedVariable*> variable_list_type;
	typedef std::vector<Pin*> pin_list_type;

protected:
	DeviceID _device_id;
	Device(const char* name);

	friend std::ostream& operator<<(std::ostream& f, Device& dev);

public:
	virtual ~Device();

	virtual EquationSystem equations() = 0;

	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const = 0;

	DeviceID& device_id();

	virtual pin_list_type pins() = 0;
	virtual variable_list_type variables() = 0;
};

std::ostream& operator<<(std::ostream& f, Device& dev);

#endif /*_PLANTCALC_DEVICE_HXX*/
