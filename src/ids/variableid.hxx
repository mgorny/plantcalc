/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_IDS_VARIABLEID_HXX
#define _PLANTCALC_IDS_VARIABLEID_HXX 1

#include "../id.hxx"

/**
 * A variable identifier.
 *
 * An identifier of an OwnedVariable. Holds the variable name and a reference
 * to its owner identifier.
 *
 * Both the variable name and the owner are set through the constructor. They
 * can be obtained using name() and owner_id() methods, respectively.
 *
 * When output, the owner identifier is prepended to the variable
 * identifier, and a dot symbol (@c .) is used as a separator.
 */
class VariableID : public ID
{
private:
	const ID& _owner;
	const char* _name;

protected:
	virtual std::ostream& print_to(std::ostream& f) const;

public:
	/**
	 * Instantiate the variable identifier.
	 *
	 * @param[in] owner The owner identifier.
	 * @param[in] name The variable name. It must be non-@c NULL, and has to be
	 * persistent.
	 */
	VariableID(const ID& owner, const char* name);

	/**
	 * Obtain the (local) variable name.
	 */
	const char* name() const;
};

#endif /*_PLANTCALC_IDS_VARIABLEID_HXX*/
