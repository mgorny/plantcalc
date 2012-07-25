/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_ID_HXX
#define _PLANTCALC_ID_HXX 1

#include <ostream>

class ID
{
	friend std::ostream& operator<<(std::ostream& f, const ID& id);

protected:
	virtual std::ostream& print_to(std::ostream& f) const = 0;
};

std::ostream& operator<<(std::ostream& f, const ID& id);

#endif /*_PLANTCALC_ID_HXX*/
