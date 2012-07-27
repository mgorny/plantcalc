/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EXCEPTION_HXX
#define _PLANTCALC_EXCEPTION_HXX 1

#include <exception>

/**
 * An arbitrary exception.
 *
 * This is simply a wrapper on the STL @c std::exception class.
 */
class Exception : public std::exception
{
public:
	/**
	 * Obtain the generic exception description string.
	 *
	 * @returns A non-@c NULL, null-terminated string. The string is
	 * either owned by the class or a constant.
	 */
	virtual const char* what() const throw() = 0;
};

#endif /*_PLANTCALC_EXCEPTION_HXX*/
