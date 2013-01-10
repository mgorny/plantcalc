/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_CONDENSER2_HXX
#define PLANTCALC_DEVICES_CONDENSER2_HXX 1

#include "common/condensingheatexchanger2.hxx"
#include "../equations/linearequation.hxx"
#include "../variables/ownedvariable.hxx"

/**
 * A vapor condenser with condensate mixing.
 *
 * The Condenser2 class provides a simple model of vapor condenser built
 * on top of CondensingHeatExchanger2.
 *
 * The Condenser2 class introduces a DeltaT() variable which specifies
 * the temperature difference between secondary flow output and input:
 *
 * @f[
 * \Delta T = T_{out}'' - T_{in}''
 * @f]
 */
class Condenser2 : public CondensingHeatExchanger2
{
	OwnedVariable _DeltaT;

	LinearEquation _DeltaT_equation;

public:
	/**
	 * Instantiate a new Condenser2.
	 *
	 * @param[in] name The device name.
	 */
	Condenser2(const char* name);
	/**
	 * Instantiate a new Condenser2 and set initial @f$ \Delta T @f$.
	 *
	 * @param[in] name The device name.
	 */
	Condenser2(const char* name, double DeltaT);

	/**
	 * The temperature difference between secondary pins.
	 */
	Variable& DeltaT();

	virtual EquationSystem equations();

	virtual variable_list_type variables();
};

#endif /*PLANTCALC_DEVICES_CONDENSER2_HXX*/
