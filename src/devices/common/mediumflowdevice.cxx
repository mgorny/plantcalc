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
	_out(_device_id, "out"),
	_iter_first_free_index(2)
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

Pin* MediumFlowDevice::iter_pin_get(int index)
{
	Pin* ret;

	assert(_iter_first_free_index == 2);
	assert(index < _iter_first_free_index);

	switch (index)
	{
		case 0:
			ret = &_in;
			break;
		case 1:
			ret = &_out;
			break;
		default:
			ret = 0;
	}

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
