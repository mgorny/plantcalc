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

#include <ostream>
#include <vector>

class System
{
public:
	typedef std::vector<Device*> device_list;
	typedef std::vector<Connection*> connection_list;

private:
	class graph_generator
	{
		System& _s;

		friend std::ostream& operator<<(std::ostream& f, System::graph_generator g);

	public:
		graph_generator(System& s);
	};

	device_list _devices;
	connection_list _connections;

	friend std::ostream& operator<<(std::ostream& f, System& s);
	friend std::ostream& operator<<(std::ostream& f, System::graph_generator& g);
	friend class graph_generator;

public:
	System();

	void push_back(Device& dev);
	void push_back(Connection& conn);

	void set_device_ids();
	void set_substances();

	EquationSystem equations();
	device_list& devices();
	connection_list& connections();
	graph_generator graph();
};

std::ostream& operator<<(std::ostream& f, System& s);
std::ostream& operator<<(std::ostream& f, System::connection_list& cl);
std::ostream& operator<<(std::ostream& f, System::graph_generator g);

#endif /*_PLANTCALC_SYSTEM_HXX*/
