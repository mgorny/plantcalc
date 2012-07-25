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

class FuelConnection : public Connection
{
	FuelPin& _from;
	FuelPin& _to;

	LinearEquation _energy_eq;
	AdditiveInverseEquation _Q_eq;
	EqualityEquation _B_eq, _Qw_eq;

public:
	FuelConnection(FuelPin& from, FuelPin& to);

	virtual FuelPin& from();
	virtual FuelPin& to();

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_CONNECTIONS_FUELCONNECTION_HXX*/
