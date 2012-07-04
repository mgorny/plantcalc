/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "determinateequationsolver.hxx"

DeterminateEquationSolver::DeterminateEquationSolver(EquationSystem& eqs)
	: _eqs(eqs)
{
}

bool DeterminateEquationSolver::iterate()
{
	EquationSystem::iterator it;
	bool any_solved = false;

	for (it = _eqs.begin(); it != _eqs.end();)
	{
		Equation& e = **it;

		if (e.solve())
		{
			any_solved = true;
			it = _eqs.erase(it);
		}
		else
			++it;
	}

	return any_solved;
}
