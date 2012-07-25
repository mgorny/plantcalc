/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "devicevariableid.hxx"

DeviceVariableID::DeviceVariableID(DeviceID& device, const char* name)
	: _device(device), _name(name)
{
}

const char* DeviceVariableID::name() const
{
	return _name;
}

std::ostream& DeviceVariableID::print_to(std::ostream& f) const
{
	return f << _device << "." << _name;
}
