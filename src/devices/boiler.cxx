/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include <cassert>

#include "boiler.hxx"

Boiler::Boiler(double eff)
	: MediumFlowDevice("B"),
	_efficiency(_device_id, "eta", eff),
	_fuel_in(_device_id, "fuel-in"),
	_energy_balance_eq(1.0, _in.D(), _in.h(),
			1.0, _efficiency, _fuel_in.Q(),
			-1.0, _out.D(), _out.h())
{
}

Boiler::Boiler(double eff, double pout, double Tout)
	: MediumFlowDevice("B"),
	_efficiency(_device_id, "eta", eff),
	_fuel_in(_device_id, "fuel-in"),
	_energy_balance_eq(1.0, _in.D(), _in.h(),
			1.0, _efficiency, _fuel_in.Q(),
			-1.0, _out.D(), _out.h())
{
	MediumPin& mout = _out;
	mout.p().set_value(pout);
	mout.T().set_value(Tout);
}

Pin* Boiler::iter_pin_get(int index)
{
	Pin* ret;

	if (index < _iter_first_free_index)
		return MediumFlowDevice::iter_pin_get(index);
	else
		index -= _iter_first_free_index;

	switch (index)
	{
		case 0:
			ret = &_fuel_in;
			break;
		default:
			ret = 0;
	}

	return ret;
}

DeviceVariable* Boiler::iter_var_get(int index)
{
	DeviceVariable* ret;

	switch (index)
	{
		case 0:
			ret = &_efficiency;
			break;
		default:
			ret = 0;
	}

	return ret;
}

Variable& Boiler::efficiency()
{
	return _efficiency;
}

FuelPin& Boiler::fuel_in()
{
	return _fuel_in;
}

EquationSystem Boiler::equations()
{
	EquationSystem ret = MediumFlowDevice::equations();

	ret.push_back(&_energy_balance_eq);

	return ret;
}
