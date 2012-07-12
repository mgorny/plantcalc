/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_ENDPOINTS_MEDIUMENDPOINT_HXX
#define _PLANTCALC_DEVICES_ENDPOINTS_MEDIUMENDPOINT_HXX 1

#include "../common/endpoint.hxx"
#include "../../pins/mediumpin.hxx"

class MediumEndpoint : public Endpoint<MediumPin>
{
public:
	MediumEndpoint(double p = 0.1);
	MediumEndpoint(double p, double T);
};

#endif /*_PLANTCALC_DEVICES_ENDPOINTS_MEDIUMENDPOINT_HXX*/
