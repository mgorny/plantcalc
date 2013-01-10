/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "condenser2.hxx"

Condenser2::Condenser2(const char* name)
	: CondensingHeatExchanger2(name),
	_DeltaT(_device_id, "DeltaT"),
	_DeltaT_equation(1.0, _sec_in.T(),
			1.0, _DeltaT,
			-1.0, _sec_out.T())
{
}

Condenser2::Condenser2(const char* name, double DeltaT)
	: CondensingHeatExchanger2(name),
	_DeltaT(_device_id, "DeltaT", DeltaT),
	_DeltaT_equation(1.0, _sec_in.T(),
			1.0, _DeltaT,
			-1.0, _sec_out.T())
{
}

Condenser2::variable_list_type Condenser2::variables()
{
	variable_list_type ret;

	ret.push_back(&_DeltaT);

	return ret;
}

Variable& Condenser2::DeltaT()
{
	return _DeltaT;
}

EquationSystem Condenser2::equations()
{
	EquationSystem ret = CondensingHeatExchanger2::equations();

	ret.push_back(&_DeltaT_equation);

	return ret;
}
