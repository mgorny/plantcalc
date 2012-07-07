/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_IDS_PINID_HXX
#define _PLANTCALC_IDS_PINID_HXX 1

#include "deviceid.hxx"

#include <ostream>

class PinID
{
private:
	DeviceID& _device;
	const char* _name;

	friend std::ostream& operator<<(std::ostream& f, const PinID& pid);

public:
	PinID(DeviceID& device, const char* name);

	DeviceID& device_id();
};

std::ostream& operator<<(std::ostream& f, const PinID& pid);

#endif /*_PLANTCALC_IDS_PINID_HXX*/
