/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "mediumpin.hxx"

MediumPin::MediumPin(DeviceID& dev_id, const char* name)
	: Pin(dev_id, name),
	_p(_pin_id, "p"),
	_T(_pin_id, "T"),
	_h(_pin_id, "h"),
	_s(_pin_id, "s"),
	_x(_pin_id, "x"),
	_D(_pin_id, "D")
{
}

MediumPin::MediumPin(DeviceID& dev_id, const char* name, double p, double T)
	: Pin(dev_id, name),
	_p(_pin_id, "p", p),
	_T(_pin_id, "T", T),
	_h(_pin_id, "h"),
	_s(_pin_id, "s"),
	_x(_pin_id, "x"),
	_D(_pin_id, "D")
{
}

MediumPin::variable_list_type MediumPin::variables()
{
	variable_list_type ret;

	ret.push_back(&_p);
	ret.push_back(&_T);
	ret.push_back(&_h);
	ret.push_back(&_s);
	ret.push_back(&_x);
	ret.push_back(&_D);

	return ret;
}

Variable& MediumPin::p()
{
	return _p;
}

Variable& MediumPin::T()
{
	return _T;
}

Variable& MediumPin::h()
{
	return _h;
}

Variable& MediumPin::s()
{
	return _s;
}

Variable& MediumPin::x()
{
	return _x;
}

Variable& MediumPin::D()
{
	return _D;
}
