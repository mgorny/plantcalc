/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "constant.hxx"

Constant::Constant(double value)
	: Variable(value, true)
{
}

std::ostream& Constant::print_to(std::ostream& f) const
{
	double val = *this;

	return f << val;
}
