/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_CONDENSER_HXX
#define _PLANTCALC_DEVICES_CONDENSER_HXX 1

#include "common/condensingheatexchanger.hxx"
#include "../equations/linearequation.hxx"
#include "../variables/ownedvariable.hxx"

/**
 * A vapor condenser.
 *
 * The Condenser class provides a simple model of vapor condenser built
 * on top of CondensingHeatExchanger.
 *
 * The Condenser class introduces a DeltaT() variable which specifies
 * the temperature difference between secondary flow output and input:
 *
 * @f[
 * \Delta T = T_{out}'' - T_{in}''
 * @f]
 */
class Condenser : public CondensingHeatExchanger
{
	OwnedVariable _DeltaT;

	LinearEquation _DeltaT_equation;

public:
	/**
	 * Instantiate a new Condenser.
	 */
	Condenser();
	/**
	 * Instantiate a new Condenser and set initial @f$ \Delta T @f$.
	 */
	Condenser(double DeltaT);

	/**
	 * The temperature difference between secondary pins.
	 */
	Variable& DeltaT();

	virtual EquationSystem equations();

	virtual variable_list_type variables();
};

#endif /*_PLANTCALC_DEVICES_CONDENSER_HXX*/
