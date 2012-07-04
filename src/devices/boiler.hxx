/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_BOILER_HXX
#define _PLANTCALC_DEVICES_BOILER_HXX 1

#include "mediumflowdevice.hxx"

class Boiler : public MediumFlowDevice
{
	double _efficiency;

public:
	Boiler(double efficiency = 1);
	Boiler(double efficiency, double pout, double Tout);

	double efficiency();
	void efficiency(double new_value);

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_DEVICES_BOILER_HXX*/
