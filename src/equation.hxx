/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATION_HXX
#define _PLANTCALC_EQUATION_HXX 1

#include <ostream>

class Equation
{
	friend std::ostream& operator <<(std::ostream& f, const Equation& eq);

protected:
	virtual std::ostream& print_to(std::ostream& f) const = 0;

public:
	virtual ~Equation();

	virtual bool solve() = 0;
};

std::ostream& operator <<(std::ostream& f, const Equation& eq);

#endif /*_PLANTCALC_EQUATION_HXX*/
