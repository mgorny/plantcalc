/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_IDS_DEVICEID_HXX
#define PLANTCALC_IDS_DEVICEID_HXX 1

#include "../id.hxx"

/**
 * A device identifier.
 *
 * An identifier of a Device. Holds the short device name and its
 * successive number in the system (if set).
 *
 * The device name is set through the constructor. It can be obtained
 * then using the name() method.
 *
 * The device number is optional and can be set and obtained using
 * the num() method. The device numbers are usually filled
 * in automatically using System::set_device_ids().
 *
 * If the device number is set, it is appended to the name when
 * printing. Otherwise, the name alone is printed.
 */
class DeviceID : public ID
{
private:
	const char* _name;
	int _num;

protected:
	virtual std::ostream& print_to(std::ostream& f) const;

public:
	/**
	 * Instantiate the device identifier.
	 *
	 * @param[in] name The short device name. It must be non-@c NULL,
	 * and has to be persistent.
	 */
	DeviceID(const char* name);

	/**
	 * Obtain the device name (without the number).
	 */
	const char* name() const;
	/**
	 * Obtain the device number.
	 *
	 * @returns The device number or @c 0 if unset.
	 */
	int num() const;
	/**
	 * Set the device number.
	 */
	void num(int new_num);
};

#endif /*_PLANTCALC_IDS_DEVICEID_HXX*/
