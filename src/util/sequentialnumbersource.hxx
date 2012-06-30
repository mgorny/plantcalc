/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_UTIL_SEQUENTIALNUMBERSOURCE_HXX
#define _PLANTCALC_UTIL_SEQUENTIALNUMBERSOURCE_HXX 1

class SequentialNumberSource
{
	int _current_seq;

public:
	SequentialNumberSource();

	int next();
};

#endif /*_PLANTCALC_UTIL_SEQUENTIALNUMBERSOURCE_HXX*/
