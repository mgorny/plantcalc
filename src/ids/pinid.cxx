/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "pinid.hxx"

PinID::PinID(DeviceID& device, const char* name)
	: _device(device), _name(name)
{
}

std::ostream& operator<<(std::ostream& f, const PinID& pid)
{
	return f << pid._device << "." << pid._name;
}

DeviceID& PinID::device_id()
{
	return _device;
}
