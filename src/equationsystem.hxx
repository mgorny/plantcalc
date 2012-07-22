/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATIONSYSTEM_HXX
#define _PLANTCALC_EQUATIONSYSTEM_HXX 1

#include "equation.hxx"

#include <vector>
#include <ostream>

/**
 * A system of equations.
 *
 * The EquationSystem class stores a list of Equation pointers which
 * form a system of equations. Such a system can be subject to solving
 * through EquationSolver derived classes.
 *
 * The Equation pointers will not be owned or freed
 * by the EquationSystem. The caller needs to ensure their persistence
 * throughout EquationSystem lifetime.
 */
class EquationSystem : public std::vector<Equation*>
{
public:
	/**
	 * Instantiate a new, empty system of equations.
	 */
	EquationSystem();

	/**
	 * Append the equations in system @a rhs to the system.
	 */
	EquationSystem& operator+=(const EquationSystem& rhs);
};

/**
 * Print the system of equations into stream @a f.
 */
std::ostream& operator <<(std::ostream& f, const EquationSystem& eqs);

#endif /*_PLANTCALC_EQUATIONSYSTEM_HXX*/
