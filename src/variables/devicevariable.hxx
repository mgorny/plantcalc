/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_VARIABLES_DEVICEVARIABLE_HXX
#define _PLANTCALC_VARIABLES_DEVICEVARIABLE_HXX 1

#include "../variable.hxx"
#include "../ids/deviceid.hxx"
#include "../ids/devicevariableid.hxx"

class DeviceVariable : public Variable
{
	DeviceVariableID _var_id;

protected:
	virtual std::ostream& print_to(std::ostream& f) const;

public:
	DeviceVariable(DeviceID& dev_id, const char* name);
	DeviceVariable(DeviceID& dev_id, const char* name, double value);
};

#endif /*_PLANTCALC_VARIABLES_DEVICEVARIABLE_HXX*/
