/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_ENDPOINT_HXX
#define _PLANTCALC_DEVICES_ENDPOINT_HXX 1

#include "../../device.hxx"
#include "../../pin.hxx"

template <class PinType>
class Endpoint : public Device
{
protected:
	PinType _pin;

	virtual Pin* iter_pin_get(int index);
	virtual DeviceVariable* iter_var_get(int index);

public:
	Endpoint();

	virtual EquationSystem equations();

	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const;

	operator PinType&();
};

#endif /*_PLANTCALC_DEVICES_ENDPOINT_HXX*/
