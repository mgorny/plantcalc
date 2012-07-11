/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "pinvariableid.hxx"

PinVariableID::PinVariableID(PinID& pin, const char* name)
	: _pin(pin), _name(name)
{
}

const char* PinVariableID::name() const
{
	return _name;
}

std::ostream& operator <<(std::ostream& f, const PinVariableID& pvid)
{
	return f << pvid._pin << "." << pvid._name;
}
