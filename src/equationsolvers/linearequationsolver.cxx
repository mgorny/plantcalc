/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "linearequationsolver.hxx"
#include "../equations/linearequation.hxx"
#include "../variable.hxx"

#include <algorithm>
#include <cassert>
#include <map>
#include <stdexcept>
#include <vector>

#include <Eigen/Core>
#include <Eigen/QR>

class col_index
{
	int _i;

public:
	col_index()
		: _i(-1)
	{
	}

	void operator=(int x)
	{
		_i = x;
	}

	operator int() const
	{
		return _i;
	}
};

LinearEquationSolver::LinearEquationSolver(EquationSystem& eqs)
	: _eqs(eqs)
{
}

bool LinearEquationSolver::iterate()
{
	typedef std::vector<LinearEquation*> linear_eq_list;
	linear_eq_list lineqs;

	// collect linear equations
	for (EquationSystem::iterator it = _eqs.begin(); it != _eqs.end(); ++it)
	{
		LinearEquation* e = dynamic_cast<LinearEquation*>(*it);

		if (e)
			lineqs.push_back(e);
	}

	const int num_eqs = lineqs.size();
	if (num_eqs == 0)
		return false;

	int curr_var_index = 0;

	typedef std::map<Variable*, col_index> variable_map;
	variable_map varmap;

	// let's assume we can have max num_eqs variables
	// if we get more, it's unsolvable anyway...
	Eigen::MatrixXd coeff_matrix
		= Eigen::MatrixXd::Zero(num_eqs, num_eqs);
	Eigen::VectorXd value_vector(num_eqs);

	linear_eq_list::iterator it;
	int row;
	for (it = lineqs.begin(), row = 0; it != lineqs.end(); ++it)
	{
		LinearEquation& e = **it;
		LinearEquation::list_type::iterator jt;

		double val = 0;

		for (jt = e._vars.begin(); jt != e._vars.end(); ++jt)
		{
			LinearEquation::list_elem_type& cv = *jt;

			Variable* unk_var = 0;
			double coeff = cv.coefficient;

			if (!cv.variable1->is_set())
				unk_var = cv.variable1;
			else
				coeff *= *cv.variable1;

			if (cv.variable2)
			{
				if (!cv.variable2->is_set())
				{
					// XXX: handle that by introducing additional variable
					if (unk_var) // two unknowns
						throw std::runtime_error("Coefficient unknown in linear equation.");
					unk_var = cv.variable2;
				}
				else
					coeff *= *cv.variable2;
			}

			if (!unk_var)
				val -= coeff;
			else
			{
				col_index& col = varmap[unk_var];

				if (col == -1)
					col = curr_var_index++;
				if (col >= num_eqs) // too many variables
					return false;

				coeff_matrix(row, col) = coeff;
			}
		}

		value_vector(row) = val;
		++row;
	}

	Eigen::VectorXd sol_vector = coeff_matrix
			.colPivHouseholderQr().solve(value_vector);

	variable_map::iterator vt;
	for (vt = varmap.begin(); vt != varmap.end(); ++vt)
	{
		Variable& v = *(*vt).first;
		col_index& col = (*vt).second;

		v.set_value(sol_vector(col));
	}

	// remove the solved equations
	// they should be in the same order in both vectors
	EquationSystem::iterator et = _eqs.begin();
	for (it = lineqs.begin(); it != lineqs.end(); ++it)
	{
		Equation* eq = *it;

		assert(et != _eqs.end());
		while (*et != eq)
		{
			++et;
			assert(et != _eqs.end());
		}
		et = _eqs.erase(et);
	}

	return false;
}
