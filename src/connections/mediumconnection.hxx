/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_CONNECTIONS_MEDIUMCONNECTION_HXX
#define _PLANTCALC_CONNECTIONS_MEDIUMCONNECTION_HXX 1

#include "../connection.hxx"
#include "../equations/equalityequation.hxx"
#include "../equations/mediumstateequation.hxx"
#include "../pins/mediumpin.hxx"
#include "../substances/mediumsubstance.hxx"

class MediumConnection : public Connection
{
	MediumPin& _from;
	MediumPin& _to;

	EqualityEquation _p_eq, _T_eq, _h_eq, _s_eq, _x_eq, _D_eq;
	MediumSubstance* _substance;
	MediumStateEquation _state_eq;

public:
	MediumConnection(MediumPin& from, MediumPin& to);

	virtual MediumPin& from();
	virtual MediumPin& to();

	virtual MediumSubstance* substance();
	virtual void substance(Substance* new_subst);
	void substance(MediumSubstance* new_subst);

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_CONNECTIONS_MEDIUMCONNECTION_HXX*/
