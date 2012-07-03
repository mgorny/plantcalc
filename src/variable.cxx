/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "variable.hxx"

#include <cassert>

Variable::Variable(const char* name, int id)
	: _name(name),
	_id(id),
	_is_set(false)
{
}

Variable::Variable(const char* name, int id, double value)
	: _name(name),
	_id(id),
	_is_set(true),
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
