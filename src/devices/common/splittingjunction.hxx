/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_COMMON_SPLITTINGJUNCTION_HXX
#define PLANTCALC_DEVICES_COMMON_SPLITTINGJUNCTION_HXX 1

#include "../../device.hxx"
#include "../../pin.hxx"

/**
 * A connection splitting junction.
 *
 * The SplittingJunction template is used to split a connection into two
 * parallel ones.
 *
 * In each splitting junction, the flux parameters are split between
 * the two outputs so that:
 *
 * @f[
 * \Phi_{in} = \Phi_{out}' + \Phi_{out}''
 * @f]
 *
 * The remaining parameters are set equal for all three pins.
 *
 * The SplittingJunction template defines the pins only. The actual
 * equations have to be specified by the derived (specialized) classes.
 */
template <class PinType>
class SplittingJunction : public Device
{
protected:
	PinType _in, _out1, _out2;

	/**
	 * Instantiate a new SplittingJunction.
	 */
	SplittingJunction();

public:
	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const;

	/**
	 * The input pin.
	 */
	PinType& in();
	/**
	 * The first output pin.
	 */
	PinType& out1();
	/**
	 * The second output pin.
	 */
	PinType& out2();

	virtual pin_list_type pins();
	virtual variable_list_type variables();
};

#endif /*_PLANTCALC_DEVICES_COMMON_SPLITTINGJUNCTION_HXX*/
