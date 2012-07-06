/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_MEDIUM_HXX
#define _PLANTCALC_MEDIUM_HXX 1

#include "variable.hxx"

class Medium
{
public:
	virtual ~Medium();

	virtual const char* name() const = 0;

	virtual bool solve(Variable& p, Variable& T,
			Variable& h, Variable& s, Variable& x) = 0;
};

#endif /*_PLANTCALC_MEDIUM_HXX*/
