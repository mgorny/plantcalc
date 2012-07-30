/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_TURBINE_HXX
#define PLANTCALC_DEVICES_TURBINE_HXX 1

#include "common/reversibleturbine.hxx"

/**
 * A simple turbine.
 *
 * The Turbine class provides a simple turbine model which can be used
 * to obtain mechanical power through decompressing the medium.
 */
class Turbine : public ReversibleTurbine
{
public:
	/**
	 * Instantiate a new Turbine.
	 *
	 * @param[in] isenthropic_efficiency Initial isenthropic efficiency
	 * value.
	 * @param[in] mechanical_efficiency Initial mechanical efficiency value.
	 */
	Turbine(double isenthropic_efficiency = 1,
			double mechanical_efficiency = 1);
	/**
	 * Instantiate a new Turbine and set the output pressure.
	 *
	 * @param[in] isenthropic_efficiency Initial isenthropic efficiency
	 * value.
	 * @param[in] mechanical_efficiency Initial mechanical efficiency value.
	 * @param[in] pout Initial output pressure [MPa].
	 */
	Turbine(double isenthropic_efficiency,
			double mechanical_efficiency, double pout);
};

#endif /*_PLANTCALC_DEVICES_TURBINE_HXX*/
