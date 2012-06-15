#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include "src/devices/boiler.hxx"
#include "src/devices/condenser.hxx"

#include "src/connections/medium/waterconnection.hxx"

int main()
{
	Boiler b(.9, 10, 773.15);
	Condenser c;

	WaterConnection bc(b.out(), c.in());
	WaterConnection cb(c.in(), b.out());

	return 0;
}
