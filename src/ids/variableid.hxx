/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_IDS_VARIABLEID_HXX
#define _PLANTCALC_IDS_VARIABLEID_HXX 1

#include "../id.hxx"

class VariableID : public ID
{
private:
	ID& _owner;
	const char* _name;

protected:
	virtual std::ostream& print_to(std::ostream& f) const;

public:
	VariableID(ID& owner, const char* name);

	const char* name() const;
};

#endif /*_PLANTCALC_IDS_VARIABLEID_HXX*/
