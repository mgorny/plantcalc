/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_CONDENSINGHEATEXCHANGER_HXX
#define _PLANTCALC_DEVICES_CONDENSINGHEATEXCHANGER_HXX 1

#include "mediumflowdevice.hxx"
#include "../../pins/mediumpin.hxx"
#include "../../equations/equalityequation.hxx"
#include "../../equations/linearequation.hxx"

class CondensingHeatExchanger : public MediumFlowDevice
{
	EqualityEquation _secondary_pressure_eq;
	EqualityEquation _secondary_mass_eq;
	EqualityEquation _primary_pressure_eq;
	EqualityEquation _primary_saturation_eq;

	LinearEquation _energy_balance_eq;

protected:
	MediumPin _sec_in, _sec_out;

	CondensingHeatExchanger(const char* name);

public:
	MediumPin& sec_in();
	MediumPin& sec_out();

	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const;
	virtual EquationSystem equations();

	virtual pin_list_type pins();
};

#endif /*_PLANTCALC_DEVICES_CONDENSINGHEATEXCHANGER_HXX*/
