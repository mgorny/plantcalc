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

std::ostream& PinID::print_to(std::ostream& f) const
{
	return f << _device << "." << _name;
}

DeviceID& PinID::device_id()
{
	return _device;
}

const char* PinID::name() const
{
	return _name;
}
