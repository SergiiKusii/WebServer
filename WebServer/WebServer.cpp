// TaskWebServer.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "server.hpp"
#include "wsTrace.hpp"

//#define ISLINUX

#ifdef ISLINUX
#include <unistd.h>
#endif


int main(int argc, char* argv[])
{

	std::string sIp;
	std::string sPort;
	std::string sRoot;

#ifdef ISLINUX
	int rez = 0;
	while ((rez = getopt(argc, argv, "ab:C::d")) != -1) {
		switch (rez) {
		case 'a': printf("found argument \"a\".\n"); break;
		case 'b': printf("found argument \"b = %s\".\n", optarg); break;
		case 'C': printf("found argument \"C = %s\".\n", optarg); break;
		case 'd': printf("found argument \"d\"\n"); break;
		case '?': printf("Error found !\n"); break;
		};
	};
#else
	if (argc != 4)
	{
		std::cerr << "Usage: http_server <address> <port> <doc_root>\n";
		std::cerr << "  For IPv4, try:\n";
		std::cerr << "    receiver 0.0.0.0 80 .\n";
		std::cerr << "  For IPv6, try:\n";
		std::cerr << "    receiver 0::0 80 .\n";
		return 1;
	}

	sIp += argv[1];
	sPort += argv[2];
	sRoot += argv[3];
#endif
	try
	{		
		//std::string sIp("127.0.0.1");
		//std::string sPort("28");
		//std::string sRoot("f:\\git\\WebServer");
		
		//trace(6, "ip: ", sIp.c_str(), " port: ", sPort.c_str(), " Root: ", sRoot.c_str());
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