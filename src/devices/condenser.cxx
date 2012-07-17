/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "condenser.hxx"

Condenser::Condenser()
	: CondensingHeatExchanger("C"),
	_DeltaT(_device_id, "DeltaT"),
	_DeltaT_equation(1.0, sec_in().T(),
			1.0, _DeltaT,
			-1.0, sec_out().T())
{
}

Condenser::Condenser(double DeltaT)
	: CondensingHeatExchanger("C"),
	_DeltaT(_device_id, "DeltaT", DeltaT),
	_DeltaT_equation(1.0, sec_in().T(),
			1.0, _DeltaT,
			-1.0, sec_out().T())
{
}

DeviceVariable* Condenser::iter_var_get(int index)
{
	DeviceVariable* ret;

	switch (index)
	{
		case 0:
			ret = &_DeltaT;
			break;
		default:
			ret = 0;
	}

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
