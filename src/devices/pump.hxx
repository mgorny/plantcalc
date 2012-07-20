/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_PUMP_HXX
#define _PLANTCALC_DEVICES_PUMP_HXX 1

#include "common/reversibleturbine.hxx"

class Pump : public ReversibleTurbine
{
public:
	Pump(double isenthropic_efficiency = 1,
			double mechanical_efficiency = 1);
	Pump(double isenthropic_efficiency,
			double mechanical_efficiency, double pout);
};

#endif /*_PLANTCALC_DEVICES_PUMP_HXX*/
