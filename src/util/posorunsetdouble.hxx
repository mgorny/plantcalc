/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_UTIL_POSORUNSETDOUBLE_HXX
#define _PLANTCALC_UTIL_POSORUNSETDOUBLE_HXX 1

class PosOrUnsetDouble
{
	double _val;

public:
	PosOrUnsetDouble();
	PosOrUnsetDouble(double val);

	void operator=(double new_val);

	bool is_set();
	operator double();
};

#endif /*_PLANTCALC_UTIL_POSORUNSETDOUBLE_HXX*/
