/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "fuelpin.hxx"

FuelPin::~FuelPin()
{
}

FuelPin::FuelPin(DeviceID& dev_id, const char* name)
	: Pin(dev_id, name),
	_Q(_pin_id, "Q"),
	_B(_pin_id, "B"),
	_Qw(_pin_id, "Qw")
{
}

Variable& FuelPin::Q()
{
	return _Q;
}

Variable& FuelPin::B()
{
	return _B;
}

Variable& FuelPin::Qw()
{
	return _Qw;
}
