/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_SYSTEM_HXX
#define _PLANTCALC_SYSTEM_HXX 1

#include "device.hxx"
#include "connection.hxx"

#include <vector>

class System
{
	std::vector<Device*> _devices;
	std::vector<Connection*> _connections;

public:
	System();

	void push_back(Device& dev);
	void push_back(Connection& conn);
};

#endif /*_PLANTCALC_SYSTEM_HXX*/
