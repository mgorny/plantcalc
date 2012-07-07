/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "deviceid.hxx"

DeviceID::DeviceID(const char* name)
	: _name(name), _num(0)
{
}

std::ostream& operator<<(std::ostream& f, const DeviceID& did)
{
	return f << did._name << did._num;
}

const char* DeviceID::name() const
{
	return _name;
}

int DeviceID::num() const
{
	return _num;
}

void DeviceID::num(int new_num)
{
	_num = new_num;
}
