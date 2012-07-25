/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_IDS_DEVICEVARIABLEID_HXX
#define _PLANTCALC_IDS_DEVICEVARIABLEID_HXX 1

#include "../id.hxx"
#include "deviceid.hxx"

class DeviceVariableID : public ID
{
private:
	DeviceID& _device;
	const char* _name;

protected:
	virtual std::ostream& print_to(std::ostream& f) const;

public:
	DeviceVariableID(DeviceID& device, const char* name);

	const char* name() const;
};

#endif /*_PLANTCALC_IDS_DEVICEVARIABLEID_HXX*/
