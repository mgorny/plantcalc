/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_UTIL_METHODBASEDITERATOR_HXX
#define _PLANTCALC_UTIL_METHODBASEDITERATOR_HXX 1

#include <cassert>
#include <iterator>

template <class Source, class ReturnType>
class MethodBasedIterator
		: public std::iterator<std::input_iterator_tag, ReturnType>
{
public:
	typedef ReturnType* (Source::*getter_method)(int index);

private:
	Source& _source;
	getter_method _getter;

	int _curr_index;
	ReturnType* _curr_val;

public:
	MethodBasedIterator(Source& source, getter_method getter,
			bool end = false);

	MethodBasedIterator& operator++();
	MethodBasedIterator operator++(int);

	ReturnType& operator*();
	ReturnType* operator->();

	bool operator==(MethodBasedIterator<Source, ReturnType> rhs);
	bool operator!=(MethodBasedIterator<Source, ReturnType> rhs);
};

#endif /*_PLANTCALC_UTIL_METHODBASEDITERATOR_HXX*/
