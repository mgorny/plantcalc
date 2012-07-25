/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "id.hxx"

std::ostream& operator<<(std::ostream& f, const ID& id)
{
	return id.print_to(f);
}
