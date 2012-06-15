/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_CONNECTION_HXX
#define _PLANTCALC_CONNECTION_HXX 1

#include "pin.hxx"

class Connection
{
public:
	virtual ~Connection();

	virtual Pin& from() = 0;
	virtual Pin& to() = 0;
};

#endif /*_PLANTCALC_CONNECTION_HXX*/
