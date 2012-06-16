/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_PINS_MEDIUMPIN_HXX
#define _PLANTCALC_PINS_MEDIUMPIN_HXX 1

#include "../pin.hxx"
#include "../util/posorunsetdouble.hxx"

class MediumPin : public Pin
{
	PosOrUnsetDouble _p, _T, _h;

public:
	MediumPin();
	MediumPin(double p, double T);

	virtual ~MediumPin();

	const PosOrUnsetDouble& p();
	void p(const PosOrUnsetDouble& newval);
	const PosOrUnsetDouble& T();
	void T(const PosOrUnsetDouble& newval);
	const PosOrUnsetDouble& h();
	void h(const PosOrUnsetDouble& newval);
};

#endif /*_PLANTCALC_PINS_MEDIUMPIN_HXX*/
