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

std::ostream& operator<<(std::ostream& f, Device& dev)
{
	std::ostream* f2 = &(f << dev._device_id << ":");

	Device::variable_iterable vars = dev.variables();
	Device::pin_iterable pins = dev.pins();

	for (Device::variable_iterable::iterator it = vars.begin();
			it != vars.end(); ++it)
	{
		DeviceVariable& v = *it;

		f2 = &(*f2 << "\n  " << v.variable_id().name() << ": ");
		f2 = &v.print_value(*f2);
	}

	for (Device::pin_iterable::iterator it = pins.begin();
			it != pins.end(); ++it)
	{
		Pin& pin = *it;

		f2 = &(*f2 << "\n  " << pin.pin_id().name() << ":");

		Pin::variable_iterable lvars = pin.variables();
		for (Pin::variable_iterable::iterator vt = lvars.begin();
				vt != lvars.end(); ++vt)
		{
			PinVariable& v = *vt;

			f2 = &(*f2 << "\n    " << v.variable_id().name() << ": ");
			f2 = &v.print_value(*f2);
		}
	}

	return *f2;
}
