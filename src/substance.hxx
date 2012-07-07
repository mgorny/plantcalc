/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_SUBSTANCE_HXX
#define _PLANTCALC_SUBSTANCE_HXX 1

class Substance
{
public:
	virtual ~Substance();

	virtual const char* name() const = 0;
};

#endif /*_PLANTCALC_SUBSTANCE_HXX*/
