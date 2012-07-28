/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "variableid.hxx"

VariableID::VariableID(const ID& owner, const char* name)
	: _owner(owner), _name(name)
{
}

const char* VariableID::name() const
{
	return _name;
}

std::ostream& VariableID::print_to(std::ostream& f) const
{
	return f << _owner << "." << _name;
}
