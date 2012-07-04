/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_VARIABLE_HXX
#define _PLANTCALC_VARIABLE_HXX 1

#include <ostream>

class Variable
{
	const char* _name;
	int _id;

	bool _is_set;
	double _val;

	friend std::ostream& operator <<(std::ostream& f, const Variable& v);

public:
	Variable(const char* name, int id);
	Variable(const char* name, int id, double value);

	bool is_set() const;

	operator double() const;
	void set_value(double user_val);
	void unset();
};

std::ostream& operator <<(std::ostream& f, const Variable& v);

#endif /*_PLANTCALC_VARIABLE_HXX*/
