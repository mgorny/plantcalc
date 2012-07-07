/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EXCEPTIONS_NONHOMOGENEOUSSUBSTANCEERROR_HXX
#define _PLANTCALC_EXCEPTIONS_NONHOMOGENEOUSSUBSTANCEERROR_HXX 1

#include <exception>

class NonHomogeneousSubstanceError : public std::exception
{
public:
	NonHomogeneousSubstanceError();

	virtual const char* what() const throw();
};

#endif /*_PLANTCALC_EXCEPTIONS_NONHOMOGENEOUSSUBSTANCEERROR_HXX*/
