/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_ENDPOINT_IXX
#define _PLANTCALC_DEVICES_ENDPOINT_IXX 1

template <class PinType>
Endpoint<PinType>::Endpoint()
	: Device("E"),
	_pin(_device_id, "i/o")
{
}

template <class PinType>
Pin* Endpoint<PinType>::iter_pin_get(int index)
{
	if (index == 0)
		return &_pin;
	else
		return 0;
}

template <class PinType>
DeviceVariable* Endpoint<PinType>::iter_var_get(int index)
{
	return 0;
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
