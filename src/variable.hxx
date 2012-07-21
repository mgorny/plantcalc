/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_VARIABLE_HXX
#define _PLANTCALC_VARIABLE_HXX 1

#include <ostream>

/**
 * A numerical variable which can be used in equations.
 *
 * Each Variable can be either set or unset. If set, the variable holds
 * a single numerical value of double precision. Otherwise, the variable
 * is unset and can be set through equation solving procedure.
 *
 * The is_set() method can be used to check whether a particular
 * variable is set. If a particular variable is set, its value can be
 * obtained using the double conversion operator. Otherwise,
 * performing the conversion is not allowed.
 *
 * The value of a variable can be set using the set_value() method.
 * Additionally, a particular variable can be unset using the unset()
 * method.
 *
 * When printed through the stream operator @c <<, the variable name is
 * printed along with the value if set. The value() method can be used
 * to obtain an object which will print the value alone (or @c ~ if
 * unset).
 */
class Variable
{
public:
	class value_printer
	{
		const Variable& _v;

		friend std::ostream& operator <<(std::ostream& f,
				const Variable::value_printer& v);

	public:
		value_printer(const Variable& v);
	};

private:
	bool _is_set, _read_only;
	double _val;

	friend std::ostream& operator <<(std::ostream& f, const Variable& v);

protected:
	/**
	 * Print the variable name (and optionally value) to the stream.
	 *
	 * This method is to be overriden in derived classes.
	 */
	virtual std::ostream& print_to(std::ostream& f) const = 0;

	/**
	 * Instantiate the Variable with no value (unset).
	 */
	Variable();
	/**
	 * Instantiate the Variable with given value.
	 *
	 * @param[in] value Initial value for the variable.
	 * @param[in] read_only Whether any changes to the value should be
	 * prohibited. If set to @c true, any changes to the variable will
	 * result in @c std::logic_error exception.
	 */
	Variable(double value, bool read_only = false);

public:
	virtual ~Variable();

	/**
	 * Obtain a boolean stating whether the variable is set (has any
	 * value).
	 */
	bool is_set() const;

	/**
	 * Obtain a @c double value for the variable.
	 *
	 * This conversion must not be called if the variable is unset.
	 */
	operator double() const;
	/**
	 * Set a new value for the variable.
	 */
	void set_value(double user_val);
	/**
	 * Unset the variable.
	 */
	void unset();

	/**
	 * Obtain the printer the for value alone. This should be used in
	 * conjunction with the @c << operator, i.e.:
	 *
	 * @code
	 * std::cout << "x = " << x.value() << std::endl;
	 * @endcode
	 *
	 * This printer can be used to output unset variables as well.
	 * In that case, the YAML null will be printed (@c ~).
	 */
	value_printer value() const;
};

/**
 * Print the variable name and its value (if set).
 *
 * If a particular variable is set, the output will look like:
 *
 * @code
 * owner::var-name(value)
 * @endcode
 *
 * If the variable is unset, the output will look like:
 *
 * @code
 * owner::var-name
 * @endcode
 */
std::ostream& operator <<(std::ostream& f, const Variable& v);
std::ostream& operator <<(std::ostream& f, const Variable::value_printer& v);

#endif /*_PLANTCALC_VARIABLE_HXX*/
