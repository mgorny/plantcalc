/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_COMMON_CONDENSINGHEATEXCHANGER2_HXX
#define PLANTCALC_DEVICES_COMMON_CONDENSINGHEATEXCHANGER2_HXX 1

#include "../../device.hxx"
#include "../../pins/mediumpin.hxx"
#include "../../equations/additiveinverseequation.hxx"
#include "../../equations/equalityequation.hxx"
#include "../../equations/linearequation.hxx"

/**
 * A fluid-condensing heat exchanger with condensate mixing.
 *
 * The CondensingHeatExchanger2 provides a base class for heat
 * exchangers where the medium (vapor) entering the exchanger through
 * the primary pin is saturated and then mixed with condensate (tertiary
 * input).  The heat is delivered to the medium flowing through
 * the secondary flow.
 *
 * The CondensingHeatExchanger2 assumes the pressure is equal on both
 * ends of each flow.
 *
 * The following equation describes the heat exchange:
 *
 * @f[
 * D' ( h_{out}' - h_{in}' ) + D'''( h_{out}' - h_{in}''' )
 * 	= D'' ( h_{out}'' - h_{in}'' )
 * @f]
 *
 * where @f$ D @f$ is the medium flux, @f$ h_{out} - h_{in} @f$ is
 * the difference between specific enthalpy of outlet and inlet
 * medium.
 */
class CondensingHeatExchanger2 : public Device
{
	EqualityEquation _primary_pressure_eq;
	EqualityEquation _primary_saturation_eq;
	EqualityEquation _secondary_pressure_eq;

	LinearEquation _primary_mass_eq;
	AdditiveInverseEquation _secondary_mass_eq;

	LinearEquation _energy_balance_eq;

protected:
	MediumPin _in, _out, _cond_in;
	MediumPin _sec_in, _sec_out;

	/**
	 * Instantiate a new CondensingHeatExchanger2.
	 *
	 * @param[in] name A short name for the device.
	 */
	CondensingHeatExchanger2(const char* name);

public:
	/**
	 * The primary vapor input pin.
	 */
	MediumPin& in();
	/**
	 * The primary condensate output pin.
	 */
	MediumPin& out();
	/**
	 * The primary condensate input pin.
	 */
	MediumPin& cond_in();

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

#endif /*PLANTCALC_DEVICES_COMMON_CONDENSINGHEATEXCHANGER2_HXX*/
