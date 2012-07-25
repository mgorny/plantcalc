/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_VARIABLES_OWNEDVARIABLE_HXX
#define _PLANTCALC_VARIABLES_OWNEDVARIABLE_HXX 1

#include "../variable.hxx"
#include "../id.hxx"
#include "../ids/variableid.hxx"

class OwnedVariable : public Variable
{
	VariableID _var_id;

protected:
	virtual std::ostream& print_to(std::ostream& f) const;

public:
	OwnedVariable(ID& owner_id, const char* name);
	OwnedVariable(ID& owner_id, const char* name, double value);

	VariableID& variable_id();
};

#endif /*_PLANTCALC_VARIABLES_OWNEDVARIABLE_HXX*/
