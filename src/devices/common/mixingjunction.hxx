/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_COMMON_MIXINGJUNCTION_HXX
#define PLANTCALC_DEVICES_COMMON_MIXINGJUNCTION_HXX 1

#include "../../device.hxx"
#include "../../pin.hxx"

/**
 * A connection mixing junction.
 *
 * The MixingJunction template is used to join two connections into
 * a single one, mixing the substance.
 *
 * In each mixing junction, the output flux is the sum of input fluxes:
 *
 * @f[
 * \Phi_{out} = \Phi_{in}' + \Phi_{in}''
 * @f]
 *
 * The remaining output parameters can be either calculated or copied
 * from the first pin.
 *
 * The MixingJunction template defines the pins only. The actual
 * equations have to be specified by the derived (specialized) classes.
 */
template <class PinType>
class MixingJunction : public Device
{
protected:
	PinType _in1, _in2, _out;

	/**
	 * Instantiate a new MixingJunction.
	 *
	 * @param[in] name The device name.
	 */
	MixingJunction(const char* name);

public:
	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const;

	/**
	 * The first input pin.
	 */
	PinType& in1();
	/**
	 * The second input pin.
	 */
	PinType& in2();
	/**
	 * The output pin.
	 */
	PinType& out();

	virtual pin_list_type pins();
	virtual variable_list_type variables();
};

#endif /*_PLANTCALC_DEVICES_COMMON_MIXINGJUNCTION_HXX*/
