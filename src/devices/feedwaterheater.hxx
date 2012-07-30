/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_FEEDWATERHEATER_HXX
#define PLANTCALC_DEVICES_FEEDWATERHEATER_HXX 1

#include "common/condensingheatexchanger.hxx"
#include "../equations/linearequation.hxx"
#include "../variables/ownedvariable.hxx"

/**
 * A feedwater heater.
 *
 * The FeedwaterHeater class provides a simple model of feedwater heater
 * built on top of CondensingHeatExchanger.
 *
 * The FeedwaterHeater class introduces a DeltaTL() variable which
 * specifies the temperature difference between the primary condensed
 * fluid and the secondary output liquid:
 *
 * @f[
 * \Delta T_L = T_{out}'' - T_{out}'
 * @f]
 */
class FeedwaterHeater : public CondensingHeatExchanger
{
	OwnedVariable _DeltaTL;

	LinearEquation _DeltaTL_equation;

public:
	/**
	 * Instantiate a new FeedwaterHeater.
	 */
	FeedwaterHeater();
	/**
	 * Instantiate a new FeedwaterHeater and set initial
	 * @f$ \Delta T_L @f$.
	 */
	FeedwaterHeater(double DeltaTL);

	/**
	 * The temperature difference between the primary and secondary
	 * output.
	 */
	Variable& DeltaTL();

	virtual EquationSystem equations();

	virtual variable_list_type variables();
};

#endif /*_PLANTCALC_DEVICES_FEEDWATERHEATER_HXX*/
