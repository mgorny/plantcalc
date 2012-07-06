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
public:
	DeterminateEquationSolver();

	virtual bool iterate(EquationSystem& eqs);
};

#endif /*_PLANTCALC_EQUATIONSOLVERS_DETERMINATEEQUATIONSOLVER_HXX*/
