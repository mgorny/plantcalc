/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_PINS_MEDIUMPIN_HXX
#define _PLANTCALC_PINS_MEDIUMPIN_HXX 1

#include "../pin.hxx"
#include "../variable.hxx"

class MediumPin : public Pin
{
	int _id;
	Variable _p, _T, _h, _s, _x, _D;

public:
	MediumPin(DeviceID& dev_id, const char* name);
	MediumPin(DeviceID& dev_id, const char* name, double p, double T);

	virtual ~MediumPin();

	Variable& p();
	Variable& T();
	Variable& h();
	Variable& s();
	Variable& x();
	Variable& D();
};

#endif /*_PLANTCALC_PINS_MEDIUMPIN_HXX*/
