/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_VARIABLES_CONSTANT_HXX
#define PLANTCALC_VARIABLES_CONSTANT_HXX 1

#include "../variable.hxx"

/**
 * An unnamed numerical constant.
 *
 * A Variable subclass which has no public identifier, stores a constant
 * value and is read-only.
 *
 * The value of a constant is set on instantiation. Afterwards, it is
 * forbidden to change the value (i.e. use set_value(), unset()). When
 * such an attempt is performed, the @c std::logic_error exception
 * is thrown.
 */
class Constant : public Variable
{
protected:
	virtual std::ostream& print_to(std::ostream& f) const;

public:
	/**
	 * Instantiate a new constant, setting its value to @a value.
	 */
	Constant(double value);
};

#endif /*_PLANTCALC_VARIABLES_CONSTANT_HXX*/
