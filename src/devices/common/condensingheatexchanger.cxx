/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "condensingheatexchanger.hxx"
#include "../../variables/constant.hxx"

static Constant xsat(0.0);

CondensingHeatExchanger::CondensingHeatExchanger(const char* name)
	: MediumFlowDevice(name),
	_secondary_mass_eq(_sec_in.D(), _sec_out.D()),
	_primary_pressure_eq(in().p(), out().p()),
	_primary_saturation_eq(out().x(), xsat),
	_energy_balance_eq(1, in().D(), in().h(),
			1, _sec_in.D(), _sec_in.h(),
			-1, out().D(), out().h(),
			-1, _sec_out.D(), _sec_out.h()),
	_sec_in(_device_id, "sec-in"),
	_sec_out(_device_id, "sec-out")
{
}

Pin* CondensingHeatExchanger::iter_pin_get(int index)
{
	Pin* ret;

	if (index < _iter_first_free_index)
		return MediumFlowDevice::iter_pin_get(index);
	else
		index -= _iter_first_free_index;

	switch (index)
	{
		case 0:
			ret = &_sec_in;
			break;
		case 1:
			ret = &_sec_out;
			break;
		default:
			ret = 0;
	}

	return ret;
}

DeviceVariable* CondensingHeatExchanger::iter_var_get(int index)
{
	return 0;
}

MediumPin& CondensingHeatExchanger::sec_in()
{
	return _sec_in;
}

MediumPin& CondensingHeatExchanger::sec_out()
{
	return _sec_out;
}

bool CondensingHeatExchanger::pins_connected(const Pin& lhs, const Pin& rhs) const
{
	if (MediumFlowDevice::pins_connected(lhs, rhs))
		return true;

	if (&lhs == &_sec_in && &rhs == &_sec_out)
		return true;
	if (&lhs == &_sec_out && &rhs == &_sec_in)
		return true;

	return false;
}

EquationSystem CondensingHeatExchanger::equations()
{
	EquationSystem ret = MediumFlowDevice::equations();

	ret.push_back(&_secondary_mass_eq);
	ret.push_back(&_primary_pressure_eq);
	ret.push_back(&_primary_saturation_eq);
	ret.push_back(&_energy_balance_eq);

	return ret;
}
