/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "mediumpin.hxx"

MediumPin::~MediumPin()
{
}

MediumPin::MediumPin()
{
}

MediumPin::MediumPin(double p, double T)
	: _p(p), _T(T)
{
}

PosOrUnsetDouble MediumPin::p()
{
	return _p;
}

void MediumPin::p(PosOrUnsetDouble newval)
{
	_p = newval;
}

PosOrUnsetDouble MediumPin::T()
{
	return _T;
}

void MediumPin::T(PosOrUnsetDouble newval)
{
	_T = newval;
}

PosOrUnsetDouble MediumPin::h()
{
	return _h;
}

void MediumPin::h(PosOrUnsetDouble newval)
{
	_h = newval;
}
