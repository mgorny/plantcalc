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
	Variable _p, _T, _h;

public:
	MediumPin();
	MediumPin(double p, double T);

	virtual ~MediumPin();

	const Variable& p();
	const Variable& T();
	const Variable& h();
};

#endif /*_PLANTCALC_PINS_MEDIUMPIN_HXX*/
