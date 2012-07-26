/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_CONNECTIONS_FUELCONNECTION_HXX
#define _PLANTCALC_CONNECTIONS_FUELCONNECTION_HXX 1

#include "../connection.hxx"
#include "../equations/additiveinverseequation.hxx"
#include "../equations/equalityequation.hxx"
#include "../equations/linearequation.hxx"
#include "../pins/fuelpin.hxx"

/**
 * A fuel-transfer connection.
 *
 * A connection between two FuelPin objects.
 *
 * A FuelConnection correlates the fuel properties on both ends.
 * Additionally, it creates an equation correlating the fuel flux
 * (Fuel::B()) with its energy flux (Fuel::Q()):
 *
 * @f[
 * Q = B Q_w
 * @f]
 */
class FuelConnection : public Connection
{
	FuelPin& _from;
	FuelPin& _to;

	LinearEquation _energy_eq;
	AdditiveInverseEquation _Q_eq;
	EqualityEquation _B_eq, _Qw_eq;

public:
	/**
	 * Instantiate a new FuelConnection.
	 *
	 * @param from A reference to the source pin.
	 * @param to A reference to the destination pin.
	 */
	FuelConnection(FuelPin& from, FuelPin& to);

	virtual FuelPin& from();
	virtual FuelPin& to();

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_CONNECTIONS_FUELCONNECTION_HXX*/
