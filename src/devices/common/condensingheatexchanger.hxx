/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_CONDENSINGHEATEXCHANGER_HXX
#define _PLANTCALC_DEVICES_CONDENSINGHEATEXCHANGER_HXX 1

#include "mediumflowdevice.hxx"
#include "../../pins/mediumpin.hxx"
#include "../../equations/additiveinverseequation.hxx"
#include "../../equations/equalityequation.hxx"
#include "../../equations/linearequation.hxx"

/**
 * A fluid-condensing heat exchanger.
 *
 * The CondensingHeatExchanger provides a base class for heat exchangers
 * where the medium (vapor) entering the exchanger through the primary
 * pin is saturated, and delivers the heat to the medium flowing through
 * the secondary flow.
 *
 * The CondensingHeatExchanger assumes the pressure is equal on both
 * ends of each flow.
 *
 * The following equation describes the heat exchange:
 *
 * @f[
 * D' ( h_{out}' - h_{in}' ) = D'' ( h_{out}'' - h_{in}'' )
 * @f]
 *
 * where @f$ D @f$ is the medium flux, @f$ h_{out} - h_{in} @f$ is
 * the difference between specific enthalpy of outlet and inlet
 * medium.
 */
class CondensingHeatExchanger : public MediumFlowDevice
{
	EqualityEquation _secondary_pressure_eq;
	AdditiveInverseEquation _secondary_mass_eq;
	EqualityEquation _primary_pressure_eq;
	EqualityEquation _primary_saturation_eq;

	LinearEquation _energy_balance_eq;

protected:
	MediumPin _sec_in, _sec_out;

	/**
	 * Instantiate a new CondensingHeatExchanger.
	 *
	 * @param[in] name A short name for the device.
	 */
	CondensingHeatExchanger(const char* name);

public:
	/**
	 * The secondary medium input pin.
	 */
	MediumPin& sec_in();
	/**
	 * The secondary medium input pin.
	 */
	MediumPin& sec_out();

	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const;
	virtual EquationSystem equations();

	virtual pin_list_type pins();
};

#endif /*_PLANTCALC_DEVICES_CONDENSINGHEATEXCHANGER_HXX*/
