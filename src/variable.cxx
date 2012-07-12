/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "variable.hxx"

#include <cassert>
#include <stdexcept>

Variable::Variable()
	: _is_set(false),
	_read_only(false)
{
}

Variable::Variable(double value, bool read_only)
	: _is_set(true),
	_read_only(read_only),
	_val(value)
{
}

Variable::~Variable()
{
}

bool Variable::is_set() const
{
	return _is_set;
}

Variable::operator double() const
{
	assert(_is_set);

	return _val;
}

void Variable::set_value(double val)
{
	if (_read_only)
		throw std::logic_error("set_value() unallowed on read-only Variable.");

	_is_set = true;
	_val = val;
}

void Variable::unset()
{
	if (_read_only)
		throw std::logic_error("unset() unallowed on read-only Variable.");

	_is_set = false;
}

std::ostream& Variable::print_value(std::ostream& f) const
{
	if (is_set())
		return f << static_cast<double>(*this);
	else
		return f << '~';
}

std::ostream& operator <<(std::ostream& f, const Variable& v)
{
	return v.print_to(f);
}
