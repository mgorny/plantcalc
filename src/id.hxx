/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_ID_HXX
#define PLANTCALC_ID_HXX 1

#include <ostream>

/**
 * A generic identifier.
 *
 * The ID class provides a base class to class identifiers.
 *
 * ID-derived classes are used within various classes to store their
 * respective identifiers. Those identifiers are then passed on to
 * member constructors.
 *
 * The main purpose of the identifiers is pretty-printing the names
 * of elements, including their ownership hierarchy. This is done
 * through use of the @c << operator on the identifier.
 */
class ID
{
	friend std::ostream& operator<<(std::ostream& f, const ID& id);

protected:
	/**
	 * Print the identifer to the stream.
	 *
	 * This method is to be overriden in derived classes.
	 */
	virtual std::ostream& print_to(std::ostream& f) const = 0;
};

/**
 * Print the identifier.
 */
std::ostream& operator<<(std::ostream& f, const ID& id);

#endif /*_PLANTCALC_ID_HXX*/
