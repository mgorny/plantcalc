/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_SUBSTANCE_HXX
#define PLANTCALC_SUBSTANCE_HXX 1

/**
 * A definition of particular substance which can flow through
 * the system.
 *
 * The Substance class represents the model of a particular substance
 * which could be used in an appropriate Connection type (passed to
 * Connection::substance()).
 *
 * A substance is usually used to define additional equations which
 * correlate the properties of substance flowing through the connection.
 * Thus, the classes derived from Substance provide appropriate equation
 * solving functions.
 */
class Substance
{
public:
	virtual ~Substance();

	/**
	 * Obtain the textual name of the substance.
	 */
	virtual const char* name() const = 0;
};

#endif /*_PLANTCALC_SUBSTANCE_HXX*/
