/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATIONSOLVERS_AUTOEQUATIONSOLVER_HXX
#define _PLANTCALC_EQUATIONSOLVERS_AUTOEQUATIONSOLVER_HXX 1

#include "../equationsolver.hxx"
#include "linearequationsolver.hxx"
#include "singleequationsolver.hxx"

class AutoEquationSolver : public EquationSolver
{
	LinearEquationSolver _linear_solver;
	SingleEquationSolver _single_solver;

public:
	AutoEquationSolver(double epsilon = 1E-6);

	virtual bool iterate(EquationSystem& eqs);
};

#endif /*_PLANTCALC_EQUATIONSOLVERS_AUTOEQUATIONSOLVER_HXX*/
