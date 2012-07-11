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

std::ostream& operator <<(std::ostream& f, const DeviceVariableID& dvid)
{
	return f << dvid._device << "." << dvid._name;
}
