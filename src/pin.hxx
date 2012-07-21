/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_PIN_HXX
#define _PLANTCALC_PIN_HXX 1

#include "ids/deviceid.hxx"
#include "ids/pinid.hxx"
#include "variables/ownedvariable.hxx"

#include <ostream>
#include <vector>

/**
 * A single inlet or outlet in a device.
 *
 * The pin represents any kind of inlet or outlet. Pins belong to
 * a particular device, and are owned by it. However, the Pin class does
 * not directly hold any reference to the device owning it.
 *
 * Each pin has an identifier which can be obtained using the pin_id()
 * method. The identifier contains a name for the pin, and a reference
 * to the DeviceID of device holding it.
 *
 * Each pin holds a number of variables. These can be obtained using
 * direct getters or the variables() method.
 *
 * Each pin can be connected to another pin using the Connection class.
 * The pin itself is not aware of the connection, neither does ensure
 * that only one connection applies to it. However, it is invalid to
 * connect more than a single connection to a single pin.
 */
class Pin
{
	friend std::ostream& operator<<(std::ostream& f, Pin& pin);

public:
	typedef std::vector<OwnedVariable*> variable_list_type;

protected:
	/**
	 * The pin identifier.
	 *
	 * This protected field should be used when instantiating variables
	 * in derived classes.
	 */
	PinID _pin_id;
	/**
	 * Instantiate the Pin, and its identifier.
	 *
	 * @param[in] dev_id Reference to the owning device identifier.
	 * @param[in] name The pin name.
	 */
	Pin(DeviceID& dev_id, const char* name);

public:
	virtual ~Pin();

	/**
	 * Obtain the pin identifier.
	 */
	PinID& pin_id();

	/**
	 * Obtain the list of variables belonging to this Pin.
	 *
	 * The returned list will contain pointers to PinVariable instances
	 * belonging to this pin. These are owned by the pin, and must not
	 * be freed.
	 *
	 * Any successive call to variables() will return the same list.
	 * The list will not contain any @c NULL pointers.
	 */
	virtual variable_list_type variables() = 0;
};

std::ostream& operator<<(std::ostream& f, Pin& pin);

#endif /*_PLANTCALC_PIN_HXX*/
