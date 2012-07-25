/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "devicevariable.hxx"

DeviceVariable::DeviceVariable(DeviceID& dev_id, const char* name)
	: _var_id(dev_id, name)
{
}

DeviceVariable::DeviceVariable(DeviceID& dev_id, const char* name, double value)
	: Variable(value),
	_var_id(dev_id, name)
{
}

std::ostream& DeviceVariable::print_to(std::ostream& f) const
{
	f << _var_id;

	if (is_set())
	{
		double val = *this;
		f << '(' << val << ')';
	}

	return f;
}

VariableID& DeviceVariable::variable_id()
{
	return _var_id;
}
