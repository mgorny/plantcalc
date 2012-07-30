/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_COMMON_ENDPOINT_HXX
#define PLANTCALC_DEVICES_COMMON_ENDPOINT_HXX 1

#include "../../device.hxx"
#include "../../pin.hxx"

/**
 * An endpoint (final source or consumer).
 *
 * The Endpoint class provides a free endpoint for any kind
 * of connection. It does not provide any equations, and thus can serve
 * as a source or consumer for any amount of energy.
 */
template <class PinType>
class Endpoint : public Device
{
protected:
	PinType _pin;

public:
	/**
	 * Instantiate the endpoint.
	 */
	Endpoint();

	virtual EquationSystem equations();

	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const;

	/**
	 * Obtain the underlying pin.
	 */
	operator PinType&();

	virtual pin_list_type pins();
	virtual variable_list_type variables();
};

#endif /*_PLANTCALC_DEVICES_COMMON_ENDPOINT_HXX*/
