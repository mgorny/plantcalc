#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include "src/devices/boiler.hxx"

int main()
{
	Boiler b(.9, 10, 773.15);

	return 0;
}
