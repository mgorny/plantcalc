/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_TURBINE_HXX
#define _PLANTCALC_DEVICES_TURBINE_HXX 1

#include "mediumflowdevice.hxx"
#include "../pins/mechanicalenergypin.hxx"
#include "../pins/mediumpin.hxx"
#include "../equations/equalityequation.hxx"
#include "../equations/linearequation.hxx"
#include "../variables/devicevariable.hxx"

class Turbine : public MediumFlowDevice
{
	DeviceVariable _isenthropic_efficiency;
	DeviceVariable _one_minus_isenthropic_efficiency;

	DeviceVariable _mechanical_efficiency;
	DeviceVariable _mechanical_efficiency_reciprocal;

	MediumPin _loop_in, _loop_out;
	MechanicalEnergyPin _energy_out;

	LinearEquation _one_minus_isen_eff_eq;
	LinearEquation _mech_eff_reciprocal_eq;

	EqualityEquation _loop_mass_balance_eq;
	EqualityEquation _loop_pressure_eq;
	EqualityEquation _ideal_expansion_eq;
	LinearEquation _real_expansion_eq;
	LinearEquation _energy_balance_eq;

public:
	Turbine(double isenthropic_efficiency = 1,
			double mechanical_efficiency = 1);
	Turbine(double isenthropic_efficiency,
			double mechanical_efficiency, double pout);

	Variable& isenthropic_efficiency();
	Variable& mechanical_efficiency();

	MediumPin& loop_out();
	MediumPin& loop_in();

	MechanicalEnergyPin& energy_out();

	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const;
	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_DEVICES_TURBINE_HXX*/
