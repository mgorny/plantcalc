/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "waterconnection.hxx"

WaterConnection::WaterConnection(MediumPin& from, MediumPin& to)
	: MediumConnection(from, to)
{
}

EquationSystem WaterConnection::equations()
{
	EquationSystem ret;

	return ret;
}
