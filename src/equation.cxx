/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "equation.hxx"

Equation::~Equation()
{
}

std::ostream& operator <<(std::ostream& f, const Equation& eq)
{
	return eq.print_to(f);
}
