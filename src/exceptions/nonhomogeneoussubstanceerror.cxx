/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "nonhomogeneoussubstanceerror.hxx"

NonHomogeneousSubstanceError::NonHomogeneousSubstanceError()
{
}

const char* NonHomogeneousSubstanceError::what() const throw()
{
	return "Substance in a circulation must be homogeneous.";
}
