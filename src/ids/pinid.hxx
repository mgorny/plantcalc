/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_IDS_PINID_HXX
#define _PLANTCALC_IDS_PINID_HXX 1

#include "../id.hxx"
#include "deviceid.hxx"

class PinID : public ID
{
private:
	DeviceID& _device;
	const char* _name;

protected:
	virtual std::ostream& print_to(std::ostream& f) const;

public:
	PinID(DeviceID& device, const char* name);

	DeviceID& device_id();

	const char* name() const;
};

#endif /*_PLANTCALC_IDS_PINID_HXX*/
