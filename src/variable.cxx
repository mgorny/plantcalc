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

Variable::Variable(const char* name, int id)
	: _name(name),
	_id(id),
	_is_set(false),
	_read_only(false)
{
}

Variable::Variable(const char* name, int id, double value, bool read_only)
	: _name(name),
	_id(id),
	_is_set(true),
	_read_only(read_only),
	_val(value)
{
}

std::ostream& operator <<(std::ostream& f, const Variable& v)
{
	std::ostream& f1 = f << v._name << v._id;

	if (v._is_set)
		return f1 << '(' << v._val << ')';
	return f1;
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
