/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_CONNECTIONS_MEDIUMCONNECTION_HXX
#define _PLANTCALC_CONNECTIONS_MEDIUMCONNECTION_HXX 1

#include "../connection.hxx"
#include "../equations/equalityequation.hxx"
#include "../pins/mediumpin.hxx"

class MediumConnection : public Connection
{
	MediumPin& _from;
	MediumPin& _to;

	EqualityEquation _p_eq, _T_eq, _h_eq;

protected:
	MediumConnection(MediumPin& from, MediumPin& to);

public:
	virtual ~MediumConnection();

	virtual MediumPin& from();
	virtual MediumPin& to();

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_CONNECTIONS_MEDIUMCONNECTION_HXX*/
