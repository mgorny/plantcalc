/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "pin.hxx"
#include "util/methodbasediterable.ixx"

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

template class MethodBasedIterator<Pin, PinVariable>;
template class MethodBasedIterable<Pin, PinVariable>;

Pin::variable_iterable Pin::variables()
{
	return variable_iterable(*this, &Pin::iter_variable_get);
}

std::ostream& operator<<(std::ostream& f, Pin& pin)
{
	f << pin._pin_id << ":";

	Pin::variable_iterable vars = pin.variables();

	for (Pin::variable_iterable::iterator it = vars.begin();
			it != vars.end(); ++it)
	{
		PinVariable& v = *it;

		f << "\n  " << v.variable_id().name() << ": ";
		v.print_value(f);
	}

	return f;
}
