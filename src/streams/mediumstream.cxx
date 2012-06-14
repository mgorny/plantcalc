/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "mediumstream.hxx"

MediumStream::MediumStream()
{
}

MediumStream::MediumStream(double p, double T)
	: _p(p), _T(T)
{
}

MediumStream::~MediumStream()
{
}

double MediumStream::D()
{
	return _D;
}

void MediumStream::D(double newval)
{
	_D = newval;
}

double MediumStream::p()
{
	return _p;
}

void MediumStream::p(double newval)
{
	_p = newval;
}

double MediumStream::T()
{
	return _T;
}

void MediumStream::T(double newval)
{
	_T = newval;
}

double MediumStream::h()
{
	return _h;
}

void MediumStream::h(double newval)
{
	_h = newval;
}
