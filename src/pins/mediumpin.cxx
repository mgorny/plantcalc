/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "mediumpin.hxx"
#include "../util/sequentialnumbersource.hxx"

MediumPin::~MediumPin()
{
}

MediumPin::MediumPin()
	: _id(seqnum.next()),
	_p("p", _id),
	_T("T", _id),
	_h("h", _id)
{
}

MediumPin::MediumPin(double p, double T)
	: _id(seqnum.next()),
	_p("p", _id, p),
	_T("T", _id, T),
	_h("h", _id)
{
}

Variable& MediumPin::p()
{
	return _p;
}

Variable& MediumPin::T()
{
	return _T;
}

Variable& MediumPin::h()
{
	return _h;
}
