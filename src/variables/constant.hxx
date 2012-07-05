/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_VARIABLES_CONSTANT_HXX
#define _PLANTCALC_VARIABLES_CONSTANT_HXX 1

#include "../variable.hxx"

class Constant : public Variable
{
protected:
	virtual std::ostream& print_to(std::ostream& f) const;

public:
	Constant(double value);
};

#endif /*_PLANTCALC_VARIABLES_CONSTANT_HXX*/
