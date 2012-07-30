/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_ENDPOINTS_MEDIUMENDPOINT_HXX
#define PLANTCALC_DEVICES_ENDPOINTS_MEDIUMENDPOINT_HXX 1

#include "../common/endpoint.hxx"
#include "../../pins/mediumpin.hxx"

/**
 * An endpoint for medium flux.
 *
 * The MediumEndpoint class provides a free endpoint for medium
 * connection. It can serve as a source or consumer for any amount
 * of medium.
 *
 * The medium at the endpoint has a defined pressure. If the endpoint
 * serves as source, the temperature should be specified as well.
 */
class MediumEndpoint : public Endpoint<MediumPin>
{
public:
	/**
	 * Instantiate a MediumEndpoint with a defined pressure.
	 *
	 * @param[in] p The medium pressure [MPa].
	 */
	MediumEndpoint(double p = 0.1);
	/**
	 * Instantiate a MediumEndpoint with a defined pressure
	 * and temperature.
	 *
	 * @param[in] p The medium pressure [MPa].
	 * @param[in] T The medium temperature [K].
	 */
	MediumEndpoint(double p, double T);
};

#endif /*_PLANTCALC_DEVICES_ENDPOINTS_MEDIUMENDPOINT_HXX*/
