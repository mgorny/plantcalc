/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_IDS_PINVARIABLEID_HXX
#define _PLANTCALC_IDS_PINVARIABLEID_HXX 1

#include "../id.hxx"
#include "pinid.hxx"

class PinVariableID : public ID
{
private:
	PinID& _pin;
	const char* _name;

protected:
	virtual std::ostream& print_to(std::ostream& f) const;

public:
	PinVariableID(PinID& pin, const char* name);

	const char* name() const;
};

#endif /*_PLANTCALC_IDS_PINVARIABLEID_HXX*/
