/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_MIXINGJUNCTIONS_APPROXIMATEMEDIUMMIXINGJUNCTION_HXX
#define _PLANTCALC_DEVICES_MIXINGJUNCTIONS_APPROXIMATEMEDIUMMIXINGJUNCTION_HXX 1

#include "../common/mixingjunction.hxx"
#include "../../equations/equalityequation.hxx"
#include "../../equations/linearequation.hxx"
#include "../../pins/mediumpin.hxx"

class ApproximateMediumMixingJunction : public MixingJunction<MediumPin>
{
	LinearEquation _mass_eq;
	EqualityEquation _p_eq, _h_eq;

public:
	ApproximateMediumMixingJunction();

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_DEVICES_MIXINGJUNCTIONS_APPROXIMATEMEDIUMMIXINGJUNCTION_HXX*/
