/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include <cassert>

#include "posorunsetdouble.hxx"

PosOrUnsetDouble::PosOrUnsetDouble()
	: _val(-1000)
{
}

PosOrUnsetDouble::PosOrUnsetDouble(double val)
	: _val(val)
{
}

void PosOrUnsetDouble::operator=(double new_val)
{
	_val = new_val;
}

PosOrUnsetDouble::operator bool()
{
	if (_val < -100)
		return false;
	else
		return true;
}

PosOrUnsetDouble::operator double()
{
	assert(*this);

	// XXX: what about unset value?
	return _val;
}
