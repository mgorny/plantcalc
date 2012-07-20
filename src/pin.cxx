/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "pin.hxx"

Pin::Pin(DeviceID& dev_id, const char* name)
	: _pin_id(dev_id, name)
{
}

Pin::~Pin()
{
}

PinID& Pin::pin_id()
{
	return _pin_id;
}

std::ostream& operator<<(std::ostream& f, Pin& pin)
{
	f << pin._pin_id << ":";

	Pin::variable_list_type vars = pin.variables();

	for (Pin::variable_list_type::iterator it = vars.begin();
			it != vars.end(); ++it)
	{
		PinVariable& v = **it;

		f << "\n  " << v.variable_id().name() << ": ";
		v.print_value(f);
	}

	return f;
}
