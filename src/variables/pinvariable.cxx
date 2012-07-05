/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "pinvariable.hxx"

PinVariable::PinVariable(PinID& pin_id, const char* name)
	: Variable(name, -1),
	_var_id(pin_id, name)
{
}

PinVariable::PinVariable(PinID& pin_id, const char* name, double value)
	: Variable(name, -1, value),
	_var_id(pin_id, name)
{
}

std::ostream& PinVariable::print_to(std::ostream& f) const
{
	std::ostream& f1 = f << _var_id;

	if (is_set())
	{
		double val = *this;
		return f1 << '(' << val << ')';
	}

	return f1;
}
