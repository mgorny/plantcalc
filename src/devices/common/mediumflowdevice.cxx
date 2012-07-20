/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "mediumflowdevice.hxx"

#include <cassert>

MediumFlowDevice::MediumFlowDevice(const char* name)
	: Device(name),
	_primary_mass_eq(_in.D(), _out.D()),
	_in(_device_id, "in"),
	_out(_device_id, "out")
{
}

bool MediumFlowDevice::pins_connected(const Pin& lhs, const Pin& rhs) const
{
	if (&lhs == &_in && &rhs == &_out)
		return true;
	if (&lhs == &_out && &rhs == &_in)
		return true;

	return false;
}

EquationSystem MediumFlowDevice::equations()
{
	EquationSystem ret;

	ret.push_back(&_primary_mass_eq);

	return ret;
}

MediumFlowDevice::pin_list_type MediumFlowDevice::pins()
{
	pin_list_type ret;

	ret.push_back(&_in);
	ret.push_back(&_out);

	return ret;
}

MediumPin& MediumFlowDevice::in()
{
	return _in;
}

MediumPin& MediumFlowDevice::out()
{
	return _out;
}
