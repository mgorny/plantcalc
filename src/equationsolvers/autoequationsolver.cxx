/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "autoequationsolver.hxx"

AutoEquationSolver::AutoEquationSolver(double epsilon)
	: _linear_solver(epsilon),
	_single_solver(epsilon)
{
}

bool AutoEquationSolver::iterate(EquationSystem& eqs)
{
	if (_single_solver.iterate(eqs))
		return true;
	if (_linear_solver.iterate(eqs))
		return true;
	if (_single_solver.iterate(eqs))
		return true;

	return false;
}
