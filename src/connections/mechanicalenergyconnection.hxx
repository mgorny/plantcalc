/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_CONNECTIONS_MECHANICALENERGYCONNECTION_HXX
#define _PLANTCALC_CONNECTIONS_MECHANICALENERGYCONNECTION_HXX 1

#include "../connection.hxx"
#include "../equations/equalityequation.hxx"
#include "../equations/linearequation.hxx"
#include "../pins/mechanicalenergypin.hxx"

class MechanicalEnergyConnection : public Connection
{
	MechanicalEnergyPin& _from;
	MechanicalEnergyPin& _to;

	EqualityEquation _P_eq;

public:
	MechanicalEnergyConnection(MechanicalEnergyPin& from, MechanicalEnergyPin& to);

	virtual MechanicalEnergyPin& from();
	virtual MechanicalEnergyPin& to();

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_CONNECTIONS_MECHANICALENERGYCONNECTION_HXX*/
