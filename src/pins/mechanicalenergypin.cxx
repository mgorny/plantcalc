/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "mechanicalenergypin.hxx"

MechanicalEnergyPin::MechanicalEnergyPin(DeviceID& dev_id, const char* name)
	: Pin(dev_id, name),
	_P(_pin_id, "P")
{
}

Variable& MechanicalEnergyPin::P()
{
	return _P;
}
