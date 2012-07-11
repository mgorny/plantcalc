/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_VARIABLES_PINVARIABLE_HXX
#define _PLANTCALC_VARIABLES_PINVARIABLE_HXX 1

#include "../variable.hxx"
#include "../ids/pinid.hxx"
#include "../ids/pinvariableid.hxx"

class PinVariable : public Variable
{
	PinVariableID _var_id;

protected:
	virtual std::ostream& print_to(std::ostream& f) const;

public:
	PinVariable(PinID& pin_id, const char* name);
	PinVariable(PinID& pin_id, const char* name, double value);

	PinVariableID& variable_id();
};

#endif /*_PLANTCALC_VARIABLES_PINVARIABLE_HXX*/
