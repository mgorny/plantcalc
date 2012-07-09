/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_SUBSTANCES_MEDIUMSUBSTANCE_HXX
#define _PLANTCALC_SUBSTANCES_MEDIUMSUBSTANCE_HXX 1

#include "../substance.hxx"
#include "../variable.hxx"

class MediumSubstance : public Substance
{
public:
	virtual bool solve(Variable& p, Variable& T,
			Variable& h, Variable& s, Variable& x,
			double epsilon) = 0;
};

#endif /*_PLANTCALC_SUBSTANCES_MEDIUMSUBSTANCE_HXX*/
