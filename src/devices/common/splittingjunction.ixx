/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_SPLITTINGJUNCTION_IXX
#define _PLANTCALC_DEVICES_SPLITTINGJUNCTION_IXX 1

#include "splittingjunction.hxx"

#include <cassert>

template <class PinType>
SplittingJunction<PinType>::SplittingJunction()
	: Device("SJ"),
	_in(_device_id, "in"),
	_out1(_device_id, "out1"),
	_out2(_device_id, "out2")
{
}

template <class PinType>
Device::pin_list_type SplittingJunction<PinType>::pins()
{
	pin_list_type ret;

	ret.push_back(&_in);
	ret.push_back(&_out1);
	ret.push_back(&_out2);

	return ret;
}

template <class PinType>
Device::variable_list_type SplittingJunction<PinType>::variables()
{
	return variable_list_type();
}

template <class PinType>
bool SplittingJunction<PinType>::pins_connected(const Pin& lhs, const Pin& rhs) const
{
	// in -> out1
	// in -> out2
	// out1 !> out2 for clearer logic

	if (&rhs == &_in)
		return pins_connected(rhs, lhs);

	if (&lhs == &_in)
		return true;

	return false;
}

template <class PinType>
PinType& SplittingJunction<PinType>::in()
{
	return _in;
}

template <class PinType>
PinType& SplittingJunction<PinType>::out1()
{
	return _out1;
}

template <class PinType>
PinType& SplittingJunction<PinType>::out2()
{
	return _out2;
}

#endif /*_PLANTCALC_DEVICES_SPLITTINGJUNCTION_IXX*/

// vim:ft=cpp
