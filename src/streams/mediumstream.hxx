/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_STREAMS_MEDIUMSTREAM_HXX
#define _PLANTCALC_STREAMS_MEDIUMSTREAM_HXX 1

#include "../util/posorunsetdouble.hxx"

#include "../stream.hxx"

class MediumStream : public Stream
{
	PosOrUnsetDouble _D, _p, _T, _h;

public:
	MediumStream();
	MediumStream(double p, double T);
	virtual ~MediumStream();

	virtual double D();
	virtual void D(double newval);
	virtual double p();
	virtual void p(double newval);
	virtual double T();
	virtual void T(double newval);
	virtual double h();
	virtual void h(double newval);
};

#endif /*_PLANTCALC_STREAMS_MEDIUMSTREAM_HXX*/
