/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "device.hxx"
#include "util/methodbasediterable.ixx"

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

template class MethodBasedIterator<Device, Pin>;
template class MethodBasedIterable<Device, Pin>;
template class MethodBasedIterator<Device, DeviceVariable>;
template class MethodBasedIterable<Device, DeviceVariable>;

Device::pin_iterable Device::pins()
{
	return pin_iterable(*this, &Device::iter_pin_get);
}

Device::variable_iterable Device::variables()
{
	return variable_iterable(*this, &Device::iter_var_get);
}
