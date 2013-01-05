/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "deviceid.hxx"

DeviceID::DeviceID(const char* name)
	: _name(name)
{
}

std::ostream& DeviceID::print_to(std::ostream& f) const
{
	return f << _name;
}

const char* DeviceID::name() const
{
	return _name;
}
