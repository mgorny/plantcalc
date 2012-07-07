/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_CONDENSER_HXX
#define _PLANTCALC_DEVICES_CONDENSER_HXX 1

#include "mediumflowdevice.hxx"
#include "../pins/mediumpin.hxx"
#include "../equations/equalityequation.hxx"

class Condenser : public MediumFlowDevice
{
	MediumPin _sec_in, _sec_out;

	EqualityEquation _secondary_mass_eq;
	EqualityEquation _primary_pressure_eq;
	EqualityEquation _primary_saturation_eq;

public:
	Condenser();

	MediumPin& sec_in();
	MediumPin& sec_out();

	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const;
	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_DEVICES_CONDENSER_HXX*/
