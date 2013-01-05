/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_MIXINGJUNCTION_IXX
#define _PLANTCALC_DEVICES_MIXINGJUNCTION_IXX 1

#include "mixingjunction.hxx"
#include <cassert>

template <class PinType>
MixingJunction<PinType>::MixingJunction(const char* name)
	: Device(name),
	_in1(_device_id, "in1"),
	_in2(_device_id, "in2"),
	_out(_device_id, "out")
{
}

template <class PinType>
Device::pin_list_type MixingJunction<PinType>::pins()
{
	pin_list_type ret;

	ret.push_back(&_in1);
	ret.push_back(&_in2);
	ret.push_back(&_out);

	return ret;
}

template <class PinType>
Device::variable_list_type MixingJunction<PinType>::variables()
{
	return variable_list_type();
}

template <class PinType>
bool MixingJunction<PinType>::pins_connected(const Pin& lhs, const Pin& rhs) const
{
	// in1 -> out
	// in2 -> out
	// in1 !> in2 for clearer logic

	if (&lhs == &_out)
		return pins_connected(rhs, lhs);

	if (&rhs == &_out)
		return true;

	return false;
}

template <class PinType>
PinType& MixingJunction<PinType>::in1()
{
	return _in1;
}

template <class PinType>
PinType& MixingJunction<PinType>::in2()
{
	return _in2;
}

template <class PinType>
PinType& MixingJunction<PinType>::out()
{
	return _out;
}

#endif /*_PLANTCALC_DEVICES_MIXINGJUNCTION_IXX*/

// vim:ft=cpp
