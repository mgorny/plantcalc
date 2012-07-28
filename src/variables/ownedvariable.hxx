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

/**
 * A variable belonging to an arbitrary class (with an ID).
 *
 * An OwnedVariable is the most common variable class. It is basically
 * a Variable holding owner ID (for pretty-printing).
 */
class OwnedVariable : public Variable
{
	VariableID _var_id;

protected:
	virtual std::ostream& print_to(std::ostream& f) const;

public:
	/**
	 * Instantiate an unset variable.
	 *
	 * @param owner_id Identifier of the owner class.
	 * @param name Local short name for the variable. Must be
	 * non-@c NULL, and has to be persistent.
	 */
	OwnedVariable(const ID& owner_id, const char* name);
	/**
	 * Instantiate a variable and set its value.
	 *
	 * @param owner_id Identifier of the owner class.
	 * @param name Local short name for the variable. Must be
	 * non-@c NULL, and has to be persistent.
	 * @param value Initial value for the variable.
	 */
	OwnedVariable(const ID& owner_id, const char* name, double value);

	/**
	 * Obtain the variable identifier.
	 */
	VariableID& variable_id();
};

#endif /*_PLANTCALC_VARIABLES_OWNEDVARIABLE_HXX*/
