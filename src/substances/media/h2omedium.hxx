/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_SUBSTANCES_MEDIA_H2OMEDIUM_HXX
#define _PLANTCALC_SUBSTANCES_MEDIA_H2OMEDIUM_HXX 1

#include "../mediumsubstance.hxx"

class H2OMedium : public MediumSubstance
{
public:
	virtual const char* name() const;

	virtual bool solve(Variable& p, Variable& T,
			Variable& h, Variable& s, Variable& x,
			double epsilon);
};

#endif /*_PLANTCALC_SUBSTANCES_MEDIA_H2OMEDIUM_HXX*/
