/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "linearequationsolver.hxx"
#include "../equations/linearequation.hxx"
#include "../exceptions/contradictionerror.hxx"
#include "../variable.hxx"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <map>
#include <stdexcept>
#include <vector>

#include <Eigen/Core>
#include <Eigen/LU>

namespace
{
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
}

LinearEquationSolver::LinearEquationSolver(EquationSystem& eqs, double epsilon)
	: _eqs(eqs), _epsilon(epsilon)
{
}

bool LinearEquationSolver::iterate()
{
	EquationSystem& eqs = _eqs;
	typedef std::vector<LinearEquation*> linear_eq_list;
	linear_eq_list lineqs;

	// collect linear equations
	for (EquationSystem::iterator it = eqs.begin(); it != eqs.end(); ++it)
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

	// gather variable counts
	linear_eq_list::iterator it;
	for (it = lineqs.begin(); it != lineqs.end();)
	{
		LinearEquation& e = **it;
		LinearEquation::list_type::iterator jt;

		bool accepted = true;

		for (jt = e._vars.begin(); jt != e._vars.end(); ++jt)
		{
			LinearEquation::list_elem_type& cv = *jt;

			Variable* unk_var = 0;

			if (!cv.variable1->is_set())
				unk_var = cv.variable1;

			if (cv.variable2 && !cv.variable2->is_set())
			{
				// if there's no usable coefficient, drop that eq
				if (unk_var)
				{
					it = lineqs.erase(it);
					accepted = false;
					break;
				}
				unk_var = cv.variable2;
			}

			if (unk_var)
			{
				col_index& col = varmap[unk_var];

				if (col == -1)
					col = curr_var_index++;
			}
		}

		if (accepted)
			++it;
	}

	const int num_vars = varmap.size();
	Eigen::MatrixXd coeff_matrix
		= Eigen::MatrixXd::Zero(num_eqs + 1, num_vars);
	Eigen::VectorXd value_vector(num_eqs + 1);

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
					assert(!unk_var);
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
				assert(col < num_vars);

				coeff_matrix(row, col) = coeff;
			}
		}

		value_vector(row) = val;
		++row;
	}

	Eigen::FullPivLU<Eigen::MatrixXd> lu = coeff_matrix.fullPivLu();

	Eigen::VectorXd sol_vector = lu.solve(value_vector);
	Eigen::VectorXd null_vector = lu.kernel().rowwise().sum();

	double error = (coeff_matrix * sol_vector - value_vector).norm();

	if (std::abs(error) > _epsilon)
		throw ContradictionError();

	std::vector<bool> keep_equations(num_eqs, false);

	variable_map::iterator vt;
	for (vt = varmap.begin(); vt != varmap.end(); ++vt)
	{
		Variable& v = *(*vt).first;
		col_index& col = (*vt).second;

		if (null_vector(col) > 0.5)
		{
			// find all equations with the variable and remove them
			// so they will remain in the original system of equations

			for (int i = 0; i < num_eqs; ++i)
			{
				if (std::abs(coeff_matrix(i, col)) > _epsilon)
					keep_equations[i] = true;
			}

			continue;
		}

		v.set_value(sol_vector(col));
	}

	// remove the solved equations
	// they should be in the same order in both vectors
	EquationSystem::iterator et = eqs.begin();
	for (linear_eq_list::size_type i = 0; i < lineqs.size(); ++i)
	{
		if (keep_equations[i])
			continue;

		Equation* eq = lineqs[i];

		assert(et != eqs.end());
		while (*et != eq)
		{
			++et;
			assert(et != eqs.end());
		}
		et = eqs.erase(et);
	}

	return false;
}
