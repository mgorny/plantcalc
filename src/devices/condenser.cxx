/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "condenser.hxx"

Condenser::Condenser()
{
}

MediumPin& Condenser::in()
{
	return _in;
}

MediumPin& Condenser::out()
{
	return _out;
}

MediumPin& Condenser::sec_in()
{
	return _sec_in;
}

MediumPin& Condenser::sec_out()
{
	return _sec_out;
}
