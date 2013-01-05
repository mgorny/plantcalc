/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include <cassert>

#include "boiler.hxx"

Boiler::Boiler(const char* name, double eff)
	: MediumFlowDevice(name),
	_efficiency(_device_id, "eta", eff),
	_fuel_in(_device_id, "fuel-in"),
	_energy_balance_eq(1.0, _in.D(), _in.h(),
			1.0, _efficiency, _fuel_in.Q(),
			1.0, _out.D(), _out.h()),
	_pressure_eq(_in.p(), _out.p())
{
}

Boiler::Boiler(const char* name, double eff, double pout, double Tout)
	: MediumFlowDevice(name),
	_efficiency(_device_id, "eta", eff),
	_fuel_in(_device_id, "fuel-in"),
	_energy_balance_eq(1.0, _in.D(), _in.h(),
			1.0, _efficiency, _fuel_in.Q(),
			1.0, _out.D(), _out.h()),
	_pressure_eq(_in.p(), _out.p())
{
	MediumPin& mout = _out;
	mout.p().set_value(pout);
	mout.T().set_value(Tout);
}

Boiler::pin_list_type Boiler::pins()
{
	pin_list_type ret = MediumFlowDevice::pins();

	ret.push_back(&_fuel_in);

	return ret;
}

Boiler::variable_list_type Boiler::variables()
{
	variable_list_type ret;

	ret.push_back(&_efficiency);

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
	ret.push_back(&_pressure_eq);

	return ret;
}
