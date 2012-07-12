/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_UTIL_METHODBASEDITERATOR_IXX
#define _PLANTCALC_UTIL_METHODBASEDITERATOR_IXX 1

#include "methodbasediterator.hxx"

template <class Source, class ReturnType>
MethodBasedIterator<Source, ReturnType>
		::MethodBasedIterator(Source& source, getter_method getter, bool end)
	: _source(source), _getter(getter), _curr_index(0)
{
	if (end)
		_curr_val = 0;
	else
		++*this;
}

template <class Source, class ReturnType>
MethodBasedIterator<Source, ReturnType>&
MethodBasedIterator<Source, ReturnType>::operator++()
{
	_curr_val = (_source.*_getter)(_curr_index++);

	return *this;
}

template <class Source, class ReturnType>
MethodBasedIterator<Source, ReturnType>
MethodBasedIterator<Source, ReturnType>::operator++(int)
{
	MethodBasedIterator<Source, ReturnType> ret = *this;

	++*this;

	return ret;
}

template <class Source, class ReturnType>
ReturnType& MethodBasedIterator<Source, ReturnType>::operator*()
{
	assert(_curr_val);

	return *_curr_val;
}

template <class Source, class ReturnType>
ReturnType* MethodBasedIterator<Source, ReturnType>::operator->()
{
	assert(_curr_val);

	return _curr_val;
}

template <class Source, class ReturnType>
bool MethodBasedIterator<Source, ReturnType>::operator==(
		MethodBasedIterator<Source, ReturnType> rhs)
{
	return _curr_val == rhs._curr_val;
}

template <class Source, class ReturnType>
bool MethodBasedIterator<Source, ReturnType>::operator!=(
		MethodBasedIterator<Source, ReturnType> rhs)
{
	return _curr_val != rhs._curr_val;
}

#endif /*_PLANTCALC_UTIL_METHODBASEDITERATOR_IXX*/

// vim:ft=cpp
