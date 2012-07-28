/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATIONSOLVER_HXX
#define _PLANTCALC_EQUATIONSOLVER_HXX 1

#include "equationsystem.hxx"

class EquationSolver
{
public:
	virtual ~EquationSolver();

	virtual bool iterate() = 0;
};

#endif /*_PLANTCALC_EQUATIONSOLVER_HXX*/
