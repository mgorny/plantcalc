/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_UTIL_METHODBASEDITERABLE_IXX
#define _PLANTCALC_UTIL_METHODBASEDITERABLE_IXX 1

#include "methodbasediterable.hxx"
#include "methodbasediterator.ixx"

template <class Source, class ReturnType>
MethodBasedIterable<Source, ReturnType>::MethodBasedIterable(
		Source& source, getter_method getter)
	: _source(source), _getter(getter)
{
}

template <class Source, class ReturnType>
MethodBasedIterator<Source, ReturnType>
		MethodBasedIterable<Source, ReturnType>::begin()
{
	return iterator(_source, _getter);
}

template <class Source, class ReturnType>
MethodBasedIterator<Source, ReturnType>
		MethodBasedIterable<Source, ReturnType>::end()
{
	return iterator(_source, _getter, true);
}

#endif /*_PLANTCALC_UTIL_METHODBASEDITERABLE_IXX*/

// vim:ft=cpp
