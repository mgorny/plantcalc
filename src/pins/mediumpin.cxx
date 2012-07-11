/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "mediumpin.hxx"

MediumPin::~MediumPin()
{
}

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

Variable* MediumPin::iter_variable_get(int index)
{
	Variable* ret;

	switch (index)
	{
		case 0:
			ret = &_p;
			break;
		case 1:
			ret = &_T;
			break;
		case 2:
			ret = &_h;
			break;
		case 3:
			ret = &_s;
			break;
		case 4:
			ret = &_x;
			break;
		case 5:
			ret = &_D;
			break;
		default:
			ret = 0;
	}

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
