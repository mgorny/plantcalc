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
			bool end = false)
		: _source(source), _getter(getter), _curr_index(0)
	{
		if (end)
			_curr_val = 0;
		else
			++*this;
	}

	void operator++()
	{
		_curr_val = (_source.*_getter)(_curr_index++);
	}

	ReturnType& operator*()
	{
		assert(_curr_val);

		return *_curr_val;
	}

	bool operator==(MethodBasedIterator<Source, ReturnType> rhs)
	{
		return &_source == &rhs._source
			&& _getter == rhs._getter
			&& _curr_val == rhs._curr_val;
	}

	bool operator!=(MethodBasedIterator<Source, ReturnType> rhs)
	{
		return &_source != &rhs._source
			|| _getter != rhs._getter
			|| _curr_val != rhs._curr_val;
	}
};

#endif /*_PLANTCALC_UTIL_METHODBASEDITERATOR_HXX*/
