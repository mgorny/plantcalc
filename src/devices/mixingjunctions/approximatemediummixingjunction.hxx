/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_MIXINGJUNCTIONS_APPROXIMATEMEDIUMMIXINGJUNCTION_HXX
#define PLANTCALC_DEVICES_MIXINGJUNCTIONS_APPROXIMATEMEDIUMMIXINGJUNCTION_HXX 1

#include "../common/mixingjunction.hxx"
#include "../../equations/equalityequation.hxx"
#include "../../equations/linearequation.hxx"
#include "../../pins/mediumpin.hxx"

/**
 * An approximate (simplified) medium mixing junction.
 *
 * The ApproximateMediumMixingJunction class provides a simple mixing
 * junction for medium connections. It uses an approximation allowing
 * to solve the system of equations with linear solver.
 *
 * This junction assumes that @f$ h_{out} = h_{in}' @f$. It can be
 * considered valid only if @f$ h_{in}'' \approx h_{in}' @f$
 * or @f$ D_{in}'' \ll D_{in}' @f$.
 */
class ApproximateMediumMixingJunction : public MixingJunction<MediumPin>
{
	LinearEquation _mass_eq;
	EqualityEquation _p_eq, _h_eq;

public:
	/**
	 * Instantiate a new ApproximateMediumMixingJunction.
	 *
	 * @param[in] name The junction name.
	 */
	ApproximateMediumMixingJunction(const char* name);

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_DEVICES_MIXINGJUNCTIONS_APPROXIMATEMEDIUMMIXINGJUNCTION_HXX*/
