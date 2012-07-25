/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_FEEDWATERHEATER_HXX
#define _PLANTCALC_DEVICES_FEEDWATERHEATER_HXX 1

#include "common/condensingheatexchanger.hxx"
#include "../equations/linearequation.hxx"
#include "../variables/ownedvariable.hxx"

class FeedwaterHeater : public CondensingHeatExchanger
{
	OwnedVariable _DeltaTL;

	LinearEquation _DeltaTL_equation;

public:
	FeedwaterHeater();
	FeedwaterHeater(double DeltaTL);

	Variable& DeltaTL();

	virtual EquationSystem equations();

	virtual variable_list_type variables();
};

#endif /*_PLANTCALC_DEVICES_FEEDWATERHEATER_HXX*/
