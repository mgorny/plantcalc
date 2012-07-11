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

MethodBasedIterable<Pin, PinVariable> Pin::variables()
{
	return MethodBasedIterable<Pin, PinVariable>
		(*this, &Pin::iter_variable_get);
}
