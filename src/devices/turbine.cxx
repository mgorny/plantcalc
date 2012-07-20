/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "turbine.hxx"

Turbine::Turbine(double isen_eff, double mech_eff)
	: ReversibleTurbine("T", isen_eff, mech_eff)
{
}

Turbine::Turbine(double isen_eff, double mech_eff, double pout)
	: ReversibleTurbine("T", isen_eff, mech_eff, pout)
{
}
