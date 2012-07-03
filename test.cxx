#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include "src/devices/boiler.hxx"
#include "src/devices/condenser.hxx"

#include "src/connections/medium/waterconnection.hxx"

#include <vector>
#include <iostream>

int main()
{
	Boiler b(.9, 10, 773.15);
	Condenser c;

	WaterConnection bc(b.out(), c.in());
	WaterConnection cb(c.out(), b.in());

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

			std::cout << d.equations() << std::endl;
		}

		for (connection_list::iterator it = connections.begin();
				it != connections.end(); ++it)
		{
			Connection& c = **it;

			std::cout << c.equations() << std::endl;
			std::cout << std::boolalpha << c.equations()[0]->solve() << std::endl;
			std::cout << c.equations() << std::endl;
		}
	}
	while (0);

	return 0;
}
