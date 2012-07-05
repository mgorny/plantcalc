/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_IDS_PINVARIABLEID_HXX
#define _PLANTCALC_IDS_PINVARIABLEID_HXX 1

#include "pinid.hxx"

#include <ostream>

class PinVariableID
{
private:
	PinID& _pin;
	const char* _name;

	friend std::ostream&
		operator<<(std::ostream& f, const PinVariableID& pvid);

public:
	PinVariableID(PinID& pin, const char* name);
};

std::ostream& operator<<(std::ostream& f, const PinVariableID& pvid);

#endif /*_PLANTCALC_IDS_PINVARIABLEID_HXX*/
