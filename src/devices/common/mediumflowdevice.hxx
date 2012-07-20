/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_MEDIUMFLOWDEVICE_HXX
#define _PLANTCALC_DEVICES_MEDIUMFLOWDEVICE_HXX 1

#include "../../device.hxx"
#include "../../equationsystem.hxx"
#include "../../pins/mediumpin.hxx"
#include "../../equations/equalityequation.hxx"

class MediumFlowDevice : public Device
{
	EqualityEquation _primary_mass_eq;

protected:
	MediumPin _in, _out;

	MediumFlowDevice(const char* name);

	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const;

	virtual EquationSystem equations();

public:
	MediumPin& in();
	MediumPin& out();

	virtual pin_list_type pins();
};

#endif /*_PLANTCALC_DEVICES_MEDIUMFLOWDEVICE_HXX*/
