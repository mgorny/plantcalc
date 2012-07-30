/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_SYSTEM_HXX
#define PLANTCALC_SYSTEM_HXX 1

#include "device.hxx"
#include "connection.hxx"
#include "equationsystem.hxx"

#include <ostream>
#include <vector>

/**
 * A system of connected devices.
 *
 * The System class is the main class collecting devices and connections
 * in a system, and performing common tasks on them.
 *
 * The System is constructed as an empty class. Devices and connections
 * can be added to it using the overloaded push_back() method.
 */
class System
{
public:
	typedef std::vector<Device*> device_list;
	typedef std::vector<Connection*> connection_list;
	typedef std::vector<connection_list> connection_group_list;

	class graph_generator
	{
		const System& _s;

		friend std::ostream& operator<<(std::ostream& f, const System::graph_generator g);

	public:
		graph_generator(const System& s);
	};

private:
	device_list _devices;
	connection_list _connections;

	friend std::ostream& operator<<(std::ostream& f, const System& s);
	friend std::ostream& operator<<(std::ostream& f, const System::graph_generator g);
	friend class graph_generator;

public:
	/**
	 * Instantiate an empty system.
	 */
	System();

	/**
	 * Add a device to the system.
	 */
	void push_back(Device& dev);
	/**
	 * Add a connection to the system.
	 */
	void push_back(Connection& conn);

	/**
	 * Set successive device numbers for devices.
	 */
	void set_device_ids();
	/**
	 * Set substances in interlinked connections.
	 *
	 * If any of the interlinked connections has a substance set,
	 * the same substance will be set for the remaining connections.
	 *
	 * @throws NonHomogeneousSubstanceError if two interlinked
	 * connections use have two different substances set.
	 */
	void set_substances();

	/**
	 * Obtain the complete system of equations for the system.
	 *
	 * The resulting equation set contains equations provided by all
	 * the devices and all the connections.
	 */
	EquationSystem equations() const;
	/**
	 * Obtain the list of devices in the system.
	 */
	const device_list& devices() const;
	/**
	 * Obtain the list of connections in the system.
	 */
	const connection_list& connections() const;
	/**
	 * Obtain the list of interlinked connection groups.
	 *
	 * The resulting list contains lists of interlinked connections.
	 */
	connection_group_list grouped_connections() const;
	/**
	 * Obtain the GraphViz (.dot) graph printer for the system.
	 *
	 * The graph can be printed to a file, and then passed
	 * to one of the GraphViz tools.
	 */
	const graph_generator graph() const;
};

/**
 * Print all the devices in a system.
 *
 * The device list will be YAML-formatted, and contain all the devices,
 * their variables and pins, and variables of their pins.
 */
std::ostream& operator<<(std::ostream& f, const System& s);
/**
 * Print all the connections in a system, in a table.
 *
 * The connections will be grouped by type. For each type,
 * a tab-separated table with all the connections and values of their
 * variables will be printed.
 */
std::ostream& operator<<(std::ostream& f, const System::connection_list& cl);
/**
 * Print the system graph.
 *
 * The graph will be in GraphViz (.dot) format. It will include
 * connections and their variables.
 */
std::ostream& operator<<(std::ostream& f, const System::graph_generator g);

#endif /*_PLANTCALC_SYSTEM_HXX*/
