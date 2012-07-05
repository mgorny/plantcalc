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
	bool _is_set, _read_only;
	double _val;

	friend std::ostream& operator <<(std::ostream& f, const Variable& v);

protected:
	virtual std::ostream& print_to(std::ostream& f) const = 0;

	Variable();
	Variable(double value, bool read_only = false);

public:
	virtual ~Variable();

	bool is_set() const;

	operator double() const;
	void set_value(double user_val);
	void unset();
};

std::ostream& operator <<(std::ostream& f, const Variable& v);

#endif /*_PLANTCALC_VARIABLE_HXX*/
