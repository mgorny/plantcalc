/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "autoequationsolver.hxx"

AutoEquationSolver::AutoEquationSolver(EquationSystem& eqs, double epsilon)
	: _linear_solver(eqs, epsilon),
	_single_solver(eqs, epsilon),
	_single_done(false)
{
}

bool AutoEquationSolver::iterate()
{
	if (!_single_done)
	{
		if (!_single_solver.iterate())
			_single_done = true;
		return true;
	}
	else
	{
		_single_done = false;
		return _linear_solver.iterate();
	}
}
