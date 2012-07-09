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
	double _epsilon;

public:
	LinearEquationSolver(double epsilon = 1E-6);

	virtual bool iterate(EquationSystem& eqs);
};

#endif /*_PLANTCALC_EQUATIONSOLVERS_LINEAREQUATIONSOLVER_HXX*/
