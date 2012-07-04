/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_CONDENSER_HXX
#define _PLANTCALC_DEVICES_CONDENSER_HXX 1

#include "../device.hxx"
#include "../pins/mediumpin.hxx"
#include "../equations/equalityequation.hxx"

class Condenser : public Device
{
	MediumPin _in, _out;
	MediumPin _sec_in, _sec_out;

	EqualityEquation _prim_mass_eq, _sec_mass_eq;

public:
	Condenser();

	MediumPin& in();
	MediumPin& out();

	MediumPin& sec_in();
	MediumPin& sec_out();

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_DEVICES_CONDENSER_HXX*/
