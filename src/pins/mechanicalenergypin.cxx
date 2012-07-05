/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "mechanicalenergypin.hxx"
#include "../util/sequentialnumbersource.hxx"

MechanicalEnergyPin::MechanicalEnergyPin(DeviceID& dev_id, const char* name)
	: Pin(dev_id, name),
	_id(seqnum.next()),
	_P("P", _id)
{
}

Variable& MechanicalEnergyPin::P()
{
	return _P;
}
