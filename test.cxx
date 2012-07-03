#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include "src/devices/boiler.hxx"
#include "src/devices/condenser.hxx"

#include "src/connections/medium/waterconnection.hxx"

#include <vector>

int main()
{
	Boiler b(.9, 10, 773.15);
	Condenser c;

	WaterConnection bc(b.out(), c.in());
	WaterConnection cb(c.in(), b.out());

	typedef std::vector<Device*> device_list;
	device_list devices;
	devices.push_back(&b);
	devices.push_back(&c);

	typedef std::vector<Connection*> connection_list;
	connection_list connections;
	connections.push_back(&bc);
	connections.push_back(&cb);

	do
	{
		for (device_list::iterator it = devices.begin();
				it != devices.end(); ++it)
		{
			Device& d = **it;
		}

		for (connection_list::iterator it = connections.begin();
				it != connections.end(); ++it)
		{
			Connection& c = **it;
		}
	}
	while (0);

	return 0;
}
