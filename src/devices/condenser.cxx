/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "condenser.hxx"

Condenser::Condenser(const char* name)
	: CondensingHeatExchanger(name),
	_DeltaT(_device_id, "DeltaT"),
	_DeltaT_equation(1.0, _sec_in.T(),
			1.0, _DeltaT,
			-1.0, _sec_out.T())
{
}

Condenser::Condenser(const char* name, double DeltaT)
	: CondensingHeatExchanger(name),
	_DeltaT(_device_id, "DeltaT", DeltaT),
	_DeltaT_equation(1.0, _sec_in.T(),
			1.0, _DeltaT,
			-1.0, _sec_out.T())
{
}

Condenser::variable_list_type Condenser::variables()
{
	variable_list_type ret;

	ret.push_back(&_DeltaT);

	return ret;
}

Variable& Condenser::DeltaT()
{
	return _DeltaT;
}

EquationSystem Condenser::equations()
{
	EquationSystem ret = CondensingHeatExchanger::equations();

	ret.push_back(&_DeltaT_equation);

	return ret;
}
