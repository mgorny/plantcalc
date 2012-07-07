/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "connection.hxx"

#include <stdexcept>

Connection::~Connection()
{
}

Substance* Connection::substance()
{
	return 0;
}

void Connection::substance(Substance* new_subst)
{
	if (new_subst)
		throw std::runtime_error("This connection type does not support substances.");
}
