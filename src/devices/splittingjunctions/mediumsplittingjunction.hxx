/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_SPLITTINGJUNCTIONS_MEDIUMSPLITTINGJUNCTION_HXX
#define _PLANTCALC_DEVICES_SPLITTINGJUNCTIONS_MEDIUMSPLITTINGJUNCTION_HXX 1

#include "../common/splittingjunction.hxx"
#include "../../equations/equalityequation.hxx"
#include "../../equations/linearequation.hxx"
#include "../../pins/mediumpin.hxx"

class MediumSplittingJunction : public SplittingJunction<MediumPin>
{
	EqualityEquation _p1_eq, _p2_eq, _h1_eq, _h2_eq;
	LinearEquation _mass_eq;

public:
	MediumSplittingJunction();

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_DEVICES_SPLITTINGJUNCTIONS_MEDIUMSPLITTINGJUNCTION_HXX*/
