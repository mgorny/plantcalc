/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_CONNECTIONS_MEDIUM_WATERCONNECTION_HXX
#define _PLANTCALC_CONNECTIONS_MEDIUM_WATERCONNECTION_HXX 1

#include "../mediumconnection.hxx"
#include "../../equations/mediumstateequation.hxx"

class WaterConnection : public MediumConnection
{
	MediumStateEquation _state_eq;

public:
	WaterConnection(MediumPin& from, MediumPin& to);

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_CONNECTIONS_MEDIUM_WATERCONNECTION_HXX*/
