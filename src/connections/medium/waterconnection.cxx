/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "waterconnection.hxx"
#include "../../substances/media/h2omedium.hxx"

static H2OMedium h2o_medium;

WaterConnection::WaterConnection(MediumPin& from, MediumPin& to)
	: MediumConnection(from, to)
{
	substance(&h2o_medium);
}
