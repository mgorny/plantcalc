/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_ENDPOINTS_MECHANICALENERGYENDPOINT_HXX
#define PLANTCALC_DEVICES_ENDPOINTS_MECHANICALENERGYENDPOINT_HXX 1

#include "../common/endpoint.hxx"
#include "../../pins/mechanicalenergypin.hxx"

/**
 * An endpoint for mechanical energy.
 *
 * The MechanicalEnergyEndpoint class provides a free endpoint for mechanical
 * energy connection.  It can serve as a consumer (or source) of any amount
 * of mechanical energy.
 */
class MechanicalEnergyEndpoint : public Endpoint<MechanicalEnergyPin>
{
public:
	/**
	 * Instantiate a MechanicalEnergyEndpoint.
	 *
	 * @param[in] name The device name.
	 */
	MechanicalEnergyEndpoint(const char* name);
};

#endif /*PLANTCALC_DEVICES_ENDPOINTS_MECHANICALENERGYENDPOINT_HXX*/
