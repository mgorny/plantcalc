/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_CONDENSER_HXX
#define _PLANTCALC_DEVICES_CONDENSER_HXX 1

#include "common/condensingheatexchanger.hxx"
#include "../equations/linearequation.hxx"
#include "../variables/devicevariable.hxx"

class Condenser : public CondensingHeatExchanger
{
	DeviceVariable _DeltaT;

	LinearEquation _DeltaT_equation;

protected:
	virtual DeviceVariable* iter_var_get(int index);

public:
	Condenser();
	Condenser(double DeltaT);

	Variable& DeltaT();

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_DEVICES_CONDENSER_HXX*/
