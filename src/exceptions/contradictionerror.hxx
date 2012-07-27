/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EXCEPTIONS_CONTRADICTIONERROR_HXX
#define _PLANTCALC_EXCEPTIONS_CONTRADICTIONERROR_HXX 1

#include <exception>

/**
 * Contradictory values in an equation.
 *
 * The ContradictionError exceptions is thrown whenever equation solving
 * results in contradictory values for a single variable.
 */
class ContradictionError : public std::exception
{
public:
	ContradictionError();

	virtual const char* what() const throw();
};

#endif /*_PLANTCALC_EXCEPTIONS_CONTRADICTIONERROR_HXX*/
