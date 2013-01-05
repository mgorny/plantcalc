/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_ENDPOINT_IXX
#define _PLANTCALC_DEVICES_ENDPOINT_IXX 1

template <class PinType>
Endpoint<PinType>::Endpoint(const char* name)
	: Device(name),
	_pin(_device_id, "i/o")
{
}

template <class PinType>
Device::pin_list_type Endpoint<PinType>::pins()
{
	pin_list_type ret;

	ret.push_back(&_pin);

	return ret;
}

template <class PinType>
Device::variable_list_type Endpoint<PinType>::variables()
{
	return variable_list_type();
}

template <class PinType>
EquationSystem Endpoint<PinType>::equations()
{
	return EquationSystem();
}

template <class PinType>
bool Endpoint<PinType>::pins_connected(const Pin& lhs, const Pin& rhs) const
{
	return false;
}

template <class PinType>
Endpoint<PinType>::operator PinType&()
{
	return _pin;
}

#endif /*_PLANTCALC_DEVICES_ENDPOINT_IXX*/

// vim:ft=cpp
