// TaskWebServer.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <boost\bind.hpp>
#include <boost\function.hpp>
#include <string>
#include <boost/asio.hpp>
#include "server.hpp"
#include "wsTrace.hpp"

int main(int argc, char* argv[])
{
	try
	{
		// Check command line arguments.
		if (0 && argc != 4)
		{
			std::cerr << "Usage: http_server <address> <port> <doc_root>\n";
			std::cerr << "  For IPv4, try:\n";
			std::cerr << "    receiver 0.0.0.0 80 .\n";
			std::cerr << "  For IPv6, try:\n";
			std::cerr << "    receiver 0::0 80 .\n";
			return 1;
		}

		// Initialise the server.
		//http::server::server s(argv[1], argv[2], argv[3]);
		std::string sIp("127.0.0.1");
		std::string sPort("28");
		std::string sRoot("f:\\git\\WebServer");
		
		trace(6, "ip: ", sIp.c_str(), " port: ", sPort.c_str(), " Root: ", sRoot.c_str());
		http::server::server s(sIp, sPort, sRoot);

		// Run the server until stopped.
		s.run();
	}
	catch (std::exception& e)
	{
		std::cerr << "exception: " << e.what() << "\n";
	}

	int a;
	std::cin >> a;

	return 0;
}