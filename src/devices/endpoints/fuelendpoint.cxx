/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "fuelendpoint.hxx"
#include "../common/endpoint.ixx"

template class Endpoint<FuelPin>;

FuelEndpoint::FuelEndpoint(const char* name)
	: Endpoint<FuelPin>(name)
{
}
