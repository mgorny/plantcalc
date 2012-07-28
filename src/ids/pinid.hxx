/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_IDS_PINID_HXX
#define _PLANTCALC_IDS_PINID_HXX 1

#include "../id.hxx"
#include "deviceid.hxx"

/**
 * A pin identifier.
 *
 * An identifier of a Pin. Holds the short pin name and a reference
 * to its owner (device) identifier.
 *
 * Both the pin name and the owner are set through the constructor. They
 * can be obtained using name() and device_id() methods, respectively.
 *
 * When output, the device identifier is prepended to the pin
 * identifier, and a dot symbol (@c .) is used as a separator.
 */
class PinID : public ID
{
private:
	const DeviceID& _device;
	const char* _name;

protected:
	virtual std::ostream& print_to(std::ostream& f) const;

public:
	/**
	 * Instantiate the pin identifier.
	 *
	 * @param device The owning device identifier.
	 * @param name The short pin name. It must be non-@c NULL,
	 * and has to be persistent.
	 */
	PinID(const DeviceID& device, const char* name);

	/**
	 * Obtain the owning device identifier.
	 */
	const DeviceID& device_id() const;

	/**
	 * Obtain the (local) pin name.
	 */
	const char* name() const;
};

#endif /*_PLANTCALC_IDS_PINID_HXX*/
