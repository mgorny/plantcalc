/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATIONSOLVERS_LINEAREQUATIONSOLVER_HXX
#define _PLANTCALC_EQUATIONSOLVERS_LINEAREQUATIONSOLVER_HXX 1

#include "../equationsolver.hxx"

class LinearEquationSolver : public EquationSolver
{
	EquationSystem& _eqs;

public:
	LinearEquationSolver(EquationSystem& eqs);

	virtual bool iterate();
};

#endif /*_PLANTCALC_EQUATIONSOLVERS_LINEAREQUATIONSOLVER_HXX*/
