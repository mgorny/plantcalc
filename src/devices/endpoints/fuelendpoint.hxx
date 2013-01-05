/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_ENDPOINTS_FUELENDPOINT_HXX
#define PLANTCALC_DEVICES_ENDPOINTS_FUELENDPOINT_HXX 1

#include "../common/endpoint.hxx"
#include "../../pins/fuelpin.hxx"

/**
 * An endpoint for fuel flux.
 *
 * The FuelEndpoint class provides a free endpoint for fuel connection.
 * It can serve as a source (or consumer) of any amount of fuel.
 */
class FuelEndpoint : public Endpoint<FuelPin>
{
public:
	/**
	 * Instantiate a FuelEndpoint.
	 *
	 * @param[in] name The device name.
	 */
	FuelEndpoint(const char* name);
};

#endif /*_PLANTCALC_DEVICES_ENDPOINTS_FUELENDPOINT_HXX*/
