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
	MethodBasedIterable(Source& source, getter_method getter)
		: _source(source), _getter(getter)
	{
	}

	MethodBasedIterator<Source, ReturnType> begin()
	{
		return iterator(_source, _getter);
	}

	MethodBasedIterator<Source, ReturnType> end()
	{
		return iterator(_source, _getter, true);
	}
};

#endif /*_PLANTCALC_UTIL_METHODBASEDITERABLE_HXX*/
