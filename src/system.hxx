/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_SYSTEM_HXX
#define _PLANTCALC_SYSTEM_HXX 1

#include "device.hxx"
#include "connection.hxx"
#include "equationsystem.hxx"

#include <vector>

class System
{
	typedef std::vector<Device*> device_list;
	typedef std::vector<Connection*> connection_list;

	device_list _devices;
	connection_list _connections;

public:
	System();

	void push_back(Device& dev);
	void push_back(Connection& conn);

	void set_device_ids();
	void set_substances();

	EquationSystem equations();
	device_list& devices();
	connection_list& connections();
};

#endif /*_PLANTCALC_SYSTEM_HXX*/
