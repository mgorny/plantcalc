/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATIONSYSTEM_HXX
#define _PLANTCALC_EQUATIONSYSTEM_HXX 1

#include "equation.hxx"

#include <vector>

class EquationSystem : public std::vector<Equation*>
{
public:
	EquationSystem();
};

#endif /*_PLANTCALC_EQUATIONSYSTEM_HXX*/
