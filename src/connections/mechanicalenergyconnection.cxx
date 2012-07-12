/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "mechanicalenergyconnection.hxx"

MechanicalEnergyConnection::MechanicalEnergyConnection(MechanicalEnergyPin& from, MechanicalEnergyPin& to)
	: _from(from), _to(to),
	_P_eq(from.P(), to.P())
{
}

MechanicalEnergyPin& MechanicalEnergyConnection::from()
{
	return _from;
}

MechanicalEnergyPin& MechanicalEnergyConnection::to()
{
	return _to;
}

EquationSystem MechanicalEnergyConnection::equations()
{
	EquationSystem ret;

	ret.push_back(&_P_eq);

	return ret;
}
