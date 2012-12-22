/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_PUMP_HXX
#define PLANTCALC_DEVICES_PUMP_HXX 1

#include "common/reversibleturbine.hxx"

/**
 * A simple pump.
 *
 * The Pump class provides a simple pump model which can be used
 * to increase the pressure of a liquid.
 *
 * The real output enthalpy is calculated using the following equation:
 *
 * @f[
 * h_{out} \eta_h = h_{ideal} - ( 1 - \eta_h ) h_{in}
 * @f]
 *
 * with @f$ \eta_h @f$ being the isenthropic efficiency,
 * and @f$ h_{ideal} @f$ being the 'ideal' specific enthalpy obtained
 * in the loop.
 */
class Pump : public ReversibleTurbine
{
	LinearEquation _real_expansion_eq;

public:
	/**
	 * Instantiate a new Pump.
	 *
	 * @param[in] isenthropic_efficiency Initial isenthropic efficiency
	 * value.
	 * @param[in] mechanical_efficiency Initial mechanical efficiency value.
	 */
	Pump(double isenthropic_efficiency = 1,
			double mechanical_efficiency = 1);
	/**
	 * Instantiate a new Pump and set the output pressure.
	 *
	 * @param[in] isenthropic_efficiency Initial isenthropic efficiency
	 * value.
	 * @param[in] mechanical_efficiency Initial mechanical efficiency value.
	 * @param[in] pout Initial output pressure [MPa].
	 */
	Pump(double isenthropic_efficiency,
			double mechanical_efficiency, double pout);

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_DEVICES_PUMP_HXX*/
