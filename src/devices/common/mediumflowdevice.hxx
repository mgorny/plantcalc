/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_COMMON_MEDIUMFLOWDEVICE_HXX
#define PLANTCALC_DEVICES_COMMON_MEDIUMFLOWDEVICE_HXX 1

#include "../../device.hxx"
#include "../../equationsystem.hxx"
#include "../../pins/mediumpin.hxx"
#include "../../equations/additiveinverseequation.hxx"

/**
 * A device with at least a single medium flowthrough.
 *
 * The MediumFlowDevice is a helper class for defining devices through
 * which the medium flows. It defines a pair of pins (inlet and outlet),
 * and a mass equation for them.
 *
 * The derived classes should call all the virtual methods in order to
 * obtain data specific to the primary medium flow.
 */
class MediumFlowDevice : public Device
{
	/**
	 * The mass equation for the primary pins.
	 */
	AdditiveInverseEquation _primary_mass_eq;

protected:
	MediumPin _in, _out;

	/**
	 * Instantiate a MediumFlowDevice.
	 *
	 * @param[in] name A short name for the device.
	 */
	MediumFlowDevice(const char* name);

	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const;

	virtual EquationSystem equations();

public:
	/**
	 * The primary medium input pin.
	 */
	MediumPin& in();
	/**
	 * The primary medium output pin.
	 */
	MediumPin& out();

	virtual pin_list_type pins();
};

#endif /*_PLANTCALC_DEVICES_COMMON_MEDIUMFLOWDEVICE_HXX*/
