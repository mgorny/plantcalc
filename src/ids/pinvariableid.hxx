/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_IDS_PINVARIABLEID_HXX
#define _PLANTCALC_IDS_PINVARIABLEID_HXX 1

#include "pinid.hxx"

class PinVariableID
{
private:
	PinID& _pin;
	const char* _name;

public:
	PinVariableID(PinID& pin, const char* name);
};

#endif /*_PLANTCALC_IDS_PINVARIABLEID_HXX*/
