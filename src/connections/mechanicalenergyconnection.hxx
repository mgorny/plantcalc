/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_CONNECTIONS_MECHANICALENERGYCONNECTION_HXX
#define _PLANTCALC_CONNECTIONS_MECHANICALENERGYCONNECTION_HXX 1

#include "../connection.hxx"
#include "../equations/additiveinverseequation.hxx"
#include "../equations/equalityequation.hxx"
#include "../equations/linearequation.hxx"
#include "../pins/mechanicalenergypin.hxx"

/**
 * A mechanical energy-transfer connection.
 *
 * A connection between two MechanicalEnergyPin objects.
 *
 * A MechanicalEnergyConnection correlates the mechanical power on both
 * ends of the connection.
 */
class MechanicalEnergyConnection : public Connection
{
	MechanicalEnergyPin& _from;
	MechanicalEnergyPin& _to;

	AdditiveInverseEquation _P_eq;

public:
	/**
	 * Instantiate a new MechanicalEnergyConnection.
	 *
	 * @param from A reference to the source pin.
	 * @param to A reference to the destination pin.
	 */
	MechanicalEnergyConnection(MechanicalEnergyPin& from, MechanicalEnergyPin& to);

	virtual MechanicalEnergyPin& from();
	virtual MechanicalEnergyPin& to();

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_CONNECTIONS_MECHANICALENERGYCONNECTION_HXX*/
