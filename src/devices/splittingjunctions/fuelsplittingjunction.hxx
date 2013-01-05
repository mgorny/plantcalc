/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_SPLITTINGJUNCTIONS_FUELSPLITTINGJUNCTION_HXX
#define PLANTCALC_DEVICES_SPLITTINGJUNCTIONS_FUELSPLITTINGJUNCTION_HXX 1

#include "../common/splittingjunction.hxx"
#include "../../equations/equalityequation.hxx"
#include "../../equations/linearequation.hxx"
#include "../../pins/fuelpin.hxx"

/**
 * A fuel splitting junction.
 *
 * The FuelSplittingJunction class provides a simple splitting
 * junction for fuel.
 */
class FuelSplittingJunction : public SplittingJunction<FuelPin>
{
	EqualityEquation _Qw1_eq, _Qw2_eq;
	LinearEquation _energy_eq;

public:
	/**
	 * Instantiate a new FuelSplittingJunction.
	 *
	 * @param[in] name The junction name.
	 */
	FuelSplittingJunction(const char* name);

	virtual EquationSystem equations();
};

#endif /*PLANTCALC_DEVICES_SPLITTINGJUNCTIONS_FUELSPLITTINGJUNCTION_HXX*/
