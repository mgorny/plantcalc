/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_DEAERATOR_HXX
#define PLANTCALC_DEVICES_DEAERATOR_HXX 1

#include "common/mediumflowdevice.hxx"
#include "../pins/mediumpin.hxx"
#include "../equations/additiveinverseequation.hxx"
#include "../equations/equalityequation.hxx"
#include "../equations/linearequation.hxx"

/**
 * A deaerator.
 *
 * The Deaerator class provides a heat exchanger where the medium
 * (vapor) entering the exchanger through the primary pin is saturated
 * and mixed with the medium (condensate) entering the secondary input.
 *
 * The following equation describes the heat exchange:
 *
 * @f[
 * D' ( h_{out} - h_{in}' ) = D'' ( h_{out} - h_{in}'' )
 * @f]
 *
 * where @f$ D @f$ is the medium flux, @f$ h_{out} - h_{in} @f$ is
 * the difference between specific enthalpy of outlet and inlet
 * medium.
 */
class Deaerator : public MediumFlowDevice
{
	MediumPin _sec_in;

	EqualityEquation _primary_pressure_eq;
	EqualityEquation _secondary_pressure_eq;
	EqualityEquation _saturation_eq;

	LinearEquation _mass_balance_eq, _energy_balance_eq;

public:
	/**
	 * Instantiate a new Deaerator.
	 */
	Deaerator();

	/**
	 * The secondary medium input pin.
	 */
	MediumPin& sec_in();

	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const;
	virtual EquationSystem equations();
	virtual variable_list_type variables();

	virtual pin_list_type pins();
};

#endif /*PLANTCALC_DEVICES_DEAERATOR_HXX*/
