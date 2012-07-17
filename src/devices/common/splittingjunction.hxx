/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_SPLITTINGJUNCTION_HXX
#define _PLANTCALC_DEVICES_SPLITTINGJUNCTION_HXX 1

#include "../../device.hxx"
#include "../../pin.hxx"

template <class PinType>
class SplittingJunction : public Device
{
protected:
	PinType _in, _out1, _out2;

	SplittingJunction();

public:
	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const;

	PinType& in();
	PinType& out1();
	PinType& out2();

	virtual pin_list_type pins();
	virtual variable_list_type variables();
};

#endif /*_PLANTCALC_DEVICES_SPLITTINGJUNCTION_HXX*/
