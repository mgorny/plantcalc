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

std::ostream& operator<<(std::ostream& f, Device& dev)
{
	f << dev._device_id << ":";

	Device::variable_list_type vars = dev.variables();
	Device::pin_list_type pins = dev.pins();

	for (Device::variable_list_type::iterator it = vars.begin();
			it != vars.end(); ++it)
	{
		OwnedVariable& v = **it;

		f << "\n  " << v.variable_id().name() << ": " << v.value();
	}

	for (Device::pin_list_type::iterator it = pins.begin();
			it != pins.end(); ++it)
	{
		Pin& pin = **it;

		f << "\n  " << pin.pin_id().name() << ":";

		Pin::variable_list_type lvars = pin.variables();
		for (Pin::variable_list_type::iterator vt = lvars.begin();
				vt != lvars.end(); ++vt)
		{
			OwnedVariable& v = **vt;

			f << "\n    " << v.variable_id().name() << ": " << v.value();
		}
	}

	return f;
}

Device::connection_list_type Device::internal_connections()
{
	return connection_list_type();
}
