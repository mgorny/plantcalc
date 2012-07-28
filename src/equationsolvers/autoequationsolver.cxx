/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "autoequationsolver.hxx"

AutoEquationSolver::AutoEquationSolver(EquationSystem& eqs, double epsilon)
	: _eqs(eqs),
	_linear_solver(eqs, epsilon),
	_single_solver(eqs, epsilon)
{
}

bool AutoEquationSolver::iterate()
{
	EquationSystem& eqs = _eqs;
	EquationSystem::size_type prev_size = eqs.size();

	if (_single_solver.iterate())
		return true;
	if (eqs.size() != prev_size)
		return true;
	prev_size = eqs.size();

	if (_linear_solver.iterate())
		return true;
	if (eqs.size() != prev_size)
		return true;

	return false;
}
