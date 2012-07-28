/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICE_HXX
#define _PLANTCALC_DEVICE_HXX 1

#include "equationsystem.hxx"
#include "pin.hxx"
#include "ids/deviceid.hxx"
#include "variables/ownedvariable.hxx"

#include <vector>

/**
 * A machine performing any technical process on energy flowing
 * through it.
 *
 * Each device has an identifier which can be obtained using
 * the device_id() method. The identifier contains a short device name,
 * and an optional number which could be used to uniquely identify
 * a device in a System. These numbers can be filled automatically in
 * using System::set_device_ids() method.
 *
 * Each device has a number of pins, and optionally variables. Those can
 * be obtained using named getters or the pins() and variables()
 * methods.
 *
 * The process being performed by the device is represented through
 * a number of equations. Those equations can be obtained using
 * equations() method. These can refer to variables of the device,
 * variables of its pins and local constants.
 *
 * Each device can be connected to other devices through use
 * of connections. The connections are done on the pins, and the device
 * is not aware of them.
 *
 * Additionally, a device can have 'internal' connections between its
 * pins. Those are used to express the medium flow through the device.
 * The interlinking between two pins can be checked using
 * pins_connected() method.
 */

class Device
{
public:
	typedef std::vector<OwnedVariable*> variable_list_type;
	typedef std::vector<Pin*> pin_list_type;

protected:
	/**
	 * The device identifier.
	 *
	 * This protected field should be used when instantiating pins
	 * in derived classes.
	 */
	DeviceID _device_id;
	/**
	 * Instantiate the Device, setting its name in the identifier.
	 *
	 * @param[in] name The short name for the device. The string will
	 * not be copied and thus must be constant.
	 */
	Device(const char* name);

	friend std::ostream& operator<<(std::ostream& f, Device& dev);

public:
	virtual ~Device();

	/**
	 * Obtain the equations expressing the process performed by the device.
	 *
	 * The equations referenced in the returned system are owned
	 * by the Device class and must not be freed. The variables
	 * referenced in them are similarly owned by the Device class, one
	 * of its pins or are statically allocated, and must not be freed.
	 *
	 * Any successive call to equations() will return the same
	 * equations. The list will not contain any @c NULL pointers.
	 */
	virtual EquationSystem equations() = 0;

	/**
	 * Check whether two given pins are interlinked within the device.
	 * If two pins are interlinked, it means that the same medium needs
	 * to flow through them.
	 *
	 * This function works correctly only on pins belonging
	 * to the particular Device instance. With other Pin instances,
	 * the return value is undefined.
	 *
	 * The argument order is irrelevant, i.e.:
	 * @code pins_connected(a, b) == pins_connected(b, a) @endcode
	 *
	 * @returns True if the pins are interlinked, false otherwise.
	 */
	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const = 0;

	/**
	 * Obtain the device identifier for this device.
	 */
	DeviceID& device_id();

	/**
	 * Obtain the complete list of pins belonging to this Device.
	 *
	 * The returned list will contain pointers to Pin instances
	 * belonging to the device. These are owned by the device,
	 * and must not be freed.
	 *
	 * This method should only be used in high-level interfaces which
	 * operate on devices upcasted to the Device class. It is preferred
	 * that Pin instances obtained this way are used through their
	 * high-level interface as well rather than being downcasted
	 * to their respective types.
	 *
	 * Any successive call to pins() will return the same list.
	 * The list will not contain any @c NULL pointers.
	 */
	virtual pin_list_type pins() = 0;
	/**
	 * Obtain the complete list of variables belonging to this Device.
	 *
	 * The returned list will contain pointers to DeviceVariable
	 * instances belonging to the device. These are owned by the device,
	 * and must not be freed.
	 *
	 * Any successive call to variables() will return the same list.
	 * The list will not contain any @c NULL pointers.
	 */
	virtual variable_list_type variables() = 0;
};

/**
 * Print the device information (including pins and variables).
 *
 * This method will print the complete device information including:
 * - the device identifier,
 * - the pins belonging to the device,
 * - the variables belonging to the device and its pins.
 */
std::ostream& operator<<(std::ostream& f, Device& dev);

#endif /*_PLANTCALC_DEVICE_HXX*/
