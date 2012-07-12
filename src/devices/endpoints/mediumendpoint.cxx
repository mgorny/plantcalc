/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "mediumendpoint.hxx"
#include "../common/endpoint.ixx"

template class Endpoint<MediumPin>;

MediumEndpoint::MediumEndpoint(double p)
{
	MediumPin& pin = *this;

	pin.p().set_value(p);
}

MediumEndpoint::MediumEndpoint(double p, double T)
{
	MediumPin& pin = *this;

	pin.p().set_value(p);
	pin.T().set_value(T);
}
