/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_EQUATION_HXX
#define _PLANTCALC_EQUATION_HXX 1

class Equation
{
public:
	virtual ~Equation();

	virtual bool solve() = 0;
};

#endif /*_PLANTCALC_EQUATION_HXX*/
