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

const PosOrUnsetDouble& MediumPin::p()
{
	return _p;
}

void MediumPin::p(const PosOrUnsetDouble& newval)
{
	_p = newval;
}

const PosOrUnsetDouble& MediumPin::T()
{
	return _T;
}

void MediumPin::T(const PosOrUnsetDouble& newval)
{
	_T = newval;
}

const PosOrUnsetDouble& MediumPin::h()
{
	return _h;
}

void MediumPin::h(const PosOrUnsetDouble& newval)
{
	_h = newval;
}
