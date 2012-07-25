/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_IDS_DEVICEID_HXX
#define _PLANTCALC_IDS_DEVICEID_HXX 1

#include "../id.hxx"

class DeviceID : public ID
{
private:
	const char* _name;
	int _num;

protected:
	virtual std::ostream& print_to(std::ostream& f) const;

public:
	DeviceID(const char* name);

	const char* name() const;
	int num() const;
	void num(int new_num);
};

#endif /*_PLANTCALC_IDS_DEVICEID_HXX*/
