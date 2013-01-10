/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_FEEDWATERHEATER2_HXX
#define PLANTCALC_DEVICES_FEEDWATERHEATER2_HXX 1

#include "common/condensingheatexchanger2.hxx"
#include "../equations/linearequation.hxx"
#include "../variables/ownedvariable.hxx"

/**
 * A feedwater heater with condensate mixing.
 *
 * The FeedwaterHeater2 class provides a simple model of feedwater heater
 * built on top of CondensingHeatExchanger2.
 *
 * The FeedwaterHeater2 class introduces a DeltaTL() variable which
 * specifies the temperature difference between the primary condensed
 * fluid and the secondary output liquid:
 *
 * @f[
 * \Delta T_L = T_{out}'' - T_{out}'
 * @f]
 */
class FeedwaterHeater2 : public CondensingHeatExchanger2
{
	OwnedVariable _DeltaTL;

	LinearEquation _DeltaTL_equation;

public:
	/**
	 * Instantiate a new FeedwaterHeater2.
	 *
	 * @param[in] name The device name.
	 */
	FeedwaterHeater2(const char* name);
	/**
	 * Instantiate a new FeedwaterHeater2 and set initial
	 * @f$ \Delta T_L @f$.
	 *
	 * @param[in] name The device name.
	 */
	FeedwaterHeater2(const char* name, double DeltaTL);

	/**
	 * The temperature difference between the primary and secondary
	 * output.
	 */
	Variable& DeltaTL();

	virtual EquationSystem equations();

	virtual variable_list_type variables();
};

#endif /*PLANTCALC_DEVICES_FEEDWATERHEATER2_HXX*/
