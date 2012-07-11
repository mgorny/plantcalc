/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_UTIL_METHODBASEDITERABLE_HXX
#define _PLANTCALC_UTIL_METHODBASEDITERABLE_HXX 1

#include "methodbasediterator.hxx"

template <class Source, class ReturnType>
class MethodBasedIterable
{
public:
	typedef MethodBasedIterator<Source, ReturnType> iterator;
	typedef typename iterator::getter_method getter_method;

private:
	Source& _source;
	getter_method _getter;

public:
	MethodBasedIterable(Source& source, getter_method getter);

	MethodBasedIterator<Source, ReturnType> begin();
	MethodBasedIterator<Source, ReturnType> end();
};

#endif /*_PLANTCALC_UTIL_METHODBASEDITERABLE_HXX*/
