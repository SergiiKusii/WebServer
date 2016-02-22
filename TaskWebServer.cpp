// TaskWebServer.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <boost\bind.hpp>
#include <boost\function.hpp>
#include <string>
#include <boost/asio.hpp>
#include "server.hpp"
//#include <socketapi.h>
//#include <sys\types.h>


int foo(int a, int b)
{
	std::cout << "a: " << a << " b: " << b << std::endl;

	return a + b;

}

int main()
{
	boost::function<int(int)> foo1 = boost::bind(&foo, _1, 10);
	std::cout << "foo1 " << foo1(5) << std::endl;

	int a;
	std::cin >> a;
    return 0;
}


int mainStartServer(int argc, char* argv[])
{
	try
	{
		// Check command line arguments.
		if (argc != 4)
		{
			std::cerr << "Usage: http_server <address> <port> <doc_root>\n";
			std::cerr << "  For IPv4, try:\n";
			std::cerr << "    receiver 0.0.0.0 80 .\n";
			std::cerr << "  For IPv6, try:\n";
			std::cerr << "    receiver 0::0 80 .\n";
			return 1;
		}

		// Initialise the server.
		http::server::server s(argv[1], argv[2], argv[3]);

		// Run the server until stopped.
		s.run();
	}
	catch (std::exception& e)
	{
		std::cerr << "exception: " << e.what() << "\n";
	}

	return 0;
}