/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "device.hxx"

Device::Device(const char* name)
	: _device_id(name)
{
}

Device::~Device()
{
}

DeviceID& Device::device_id()
{
	return _device_id;
}
