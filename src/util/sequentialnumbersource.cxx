/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "sequentialnumbersource.hxx"

SequentialNumberSource seqnum;

SequentialNumberSource::SequentialNumberSource()
	: _current_seq(0)
{
}

int SequentialNumberSource::next()
{
	return ++_current_seq;
}
