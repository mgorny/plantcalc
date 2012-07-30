/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_EXCEPTIONS_NONHOMOGENEOUSSUBSTANCEERROR_HXX
#define PLANTCALC_EXCEPTIONS_NONHOMOGENEOUSSUBSTANCEERROR_HXX 1

#include "../exception.hxx"

/**
 * Non-homogeneous substance in a set of interlinked connections.
 *
 * The NonHomogeneousSubstanceError exceptions is thrown whenever
 * System::set_substances() detects that two different substances
 * are set in a set of interlinked connections.
 */
class NonHomogeneousSubstanceError : public Exception
{
public:
	NonHomogeneousSubstanceError();

	virtual const char* what() const throw();
};

#endif /*_PLANTCALC_EXCEPTIONS_NONHOMOGENEOUSSUBSTANCEERROR_HXX*/
