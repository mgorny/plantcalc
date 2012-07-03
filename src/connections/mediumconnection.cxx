/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "mediumconnection.hxx"

MediumConnection::MediumConnection(MediumPin& from, MediumPin& to)
	: _from(from), _to(to),
	_p_eq(from.p(), to.p()),
	_T_eq(from.T(), to.T()),
	_h_eq(from.h(), to.h())
{
}

MediumConnection::~MediumConnection()
{
}

MediumPin& MediumConnection::from()
{
	return _from;
}

MediumPin& MediumConnection::to()
{
	return _to;
}

EquationSystem MediumConnection::equations()
{
	EquationSystem ret;

	ret.push_back(&_p_eq);
	ret.push_back(&_T_eq);
	ret.push_back(&_h_eq);

	return ret;
}
