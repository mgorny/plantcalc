/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_MEDIA_H2O_HXX
#define _PLANTCALC_MEDIA_H2O_HXX 1

#include "../medium.hxx"

class H2OMedium : public Medium
{
public:
	virtual const char* name() const;

	virtual bool solve(Variable& p, Variable& T,
			Variable& h, Variable& s, Variable& x);
};

#endif /*_PLANTCALC_MEDIA_H2O_HXX*/
