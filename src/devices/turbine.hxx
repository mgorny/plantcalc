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

class Turbine : public MediumFlowDevice
{
	double _isenthropic_efficiency;
	double _mechanical_efficiency;

	MediumPin _loop_out, _loop_in;
	MechanicalEnergyPin _energy_out;

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

	double isenthropic_efficiency();
	void isenthropic_efficiency(double new_value);
	double mechanical_efficiency();
	void mechanical_efficiency(double new_value);

	MediumPin& loop_out();
	MediumPin& loop_in();

	MechanicalEnergyPin& energy_out();

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_DEVICES_TURBINE_HXX*/
