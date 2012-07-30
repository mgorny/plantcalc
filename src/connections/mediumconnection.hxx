/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_CONNECTIONS_MEDIUMCONNECTION_HXX
#define PLANTCALC_CONNECTIONS_MEDIUMCONNECTION_HXX 1

#include "../connection.hxx"
#include "../equations/additiveinverseequation.hxx"
#include "../equations/equalityequation.hxx"
#include "../equations/mediumstateequation.hxx"
#include "../pins/mediumpin.hxx"
#include "../substances/mediumsubstance.hxx"

/**
 * A medium-transfer connection.
 *
 * A connection between two MediumPin objects.
 *
 * A MediumConnection correlates the medium properties on both ends.
 * Additionally, it creates a MediumStateEquation correlating
 * the medium properties.
 *
 * In order for MediumStateEquation to be able to calculate
 * the properties, a correct MediumSubstance has to be set using
 * substance() method.
 */
class MediumConnection : public Connection
{
	MediumPin& _from;
	MediumPin& _to;

	EqualityEquation _p_eq, _T_eq, _h_eq, _s_eq, _x_eq;
	AdditiveInverseEquation _D_eq;
	const MediumSubstance* _substance;
	MediumStateEquation _state_eq;

public:
	/**
	 * Instantiate a new MediumConnection.
	 *
	 * @param[in,out] from A reference to the source pin.
	 * @param[in,out] to A reference to the destination pin.
	 */
	MediumConnection(MediumPin& from, MediumPin& to);

	virtual MediumPin& from();
	virtual MediumPin& to();

	virtual const MediumSubstance* substance();
	virtual void substance(const Substance* new_subst);
	void substance(const MediumSubstance* new_subst);

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_CONNECTIONS_MEDIUMCONNECTION_HXX*/
