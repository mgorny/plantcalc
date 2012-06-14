/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_PINS_MEDIUMPIN_HXX
#define _PLANTCALC_PINS_MEDIUMPIN_HXX 1

#include "../pin.hxx"
#include "../streams/mediumstream.hxx"

class MediumPin : public Pin, public MediumStream
{
public:
	MediumPin();
	MediumPin(double p, double T);

	virtual ~MediumPin();
};

#endif /*_PLANTCALC_PINS_MEDIUMPIN_HXX*/
