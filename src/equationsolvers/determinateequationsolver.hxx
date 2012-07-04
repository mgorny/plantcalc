/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATIONSOLVERS_DETERMINATEEQUATIONSOLVER_HXX
#define _PLANTCALC_EQUATIONSOLVERS_DETERMINATEEQUATIONSOLVER_HXX 1

#include "../equationsolver.hxx"

class DeterminateEquationSolver : public EquationSolver
{
	EquationSystem& _eqs;

public:
	DeterminateEquationSolver(EquationSystem& eqs);

	virtual bool iterate();
};

#endif /*_PLANTCALC_EQUATIONSOLVERS_DETERMINATEEQUATIONSOLVER_HXX*/
