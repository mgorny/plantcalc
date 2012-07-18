/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_MIXINGJUNCTION_HXX
#define _PLANTCALC_DEVICES_MIXINGJUNCTION_HXX 1

#include "../../device.hxx"
#include "../../pin.hxx"

template <class PinType>
class MixingJunction : public Device
{
protected:
	PinType _in1, _in2, _out;

	MixingJunction();

public:
	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const;

	PinType& in1();
	PinType& in2();
	PinType& out();

	virtual pin_list_type pins();
	virtual variable_list_type variables();
};

#endif /*_PLANTCALC_DEVICES_MIXINGJUNCTION_HXX*/
