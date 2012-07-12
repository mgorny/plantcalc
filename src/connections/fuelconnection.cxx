/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "fuelconnection.hxx"

FuelConnection::FuelConnection(FuelPin& from, FuelPin& to)
	: _from(from), _to(to),
	_Q_eq(from.Q(), to.Q()),
	_B_eq(from.B(), to.B()),
	_Qw_eq(from.Qw(), to.Qw())
{
	_energy_eq.update(1, to.Q());
	_energy_eq.update(-1, to.B(), to.Qw());
}

FuelPin& FuelConnection::from()
{
	return _from;
}

FuelPin& FuelConnection::to()
{
	return _to;
}

EquationSystem FuelConnection::equations()
{
	EquationSystem ret;

	ret.push_back(&_energy_eq);
	ret.push_back(&_Q_eq);
	ret.push_back(&_B_eq);
	ret.push_back(&_Qw_eq);

	return ret;
}
