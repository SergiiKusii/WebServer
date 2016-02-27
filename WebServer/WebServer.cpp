// TaskWebServer.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "server.hpp"
#include "wsTrace.hpp"

#include <thread>

//#define ISLINUX

#ifdef ISLINUX
#include <unistd.h>
#include <sys/types>
#endif

/*typedef*/ struct communicatios
{
	std::string sIp;
	std::string sPort;
	std::string sRoot;
} /*COMMUN*/; 

communicatios scanPram(int argc, char* argv[])
{
	std::string sIp;
	std::string sPort;
	std::string sRoot;

#ifdef ISLINUX
	int rez = 0;
	while ((rez = getopt(argc, argv, "h:p:d:e")) != -1) {
		switch (rez) {
		case 'h':
			sIp += optarg;
			break;
		case 'p':
			sPort += optarg;
			break;
		case 'd':
			sRoot += optarg;
			break;
		default:
			return communicatios();
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
		return communicatios();
		}

	sIp += argv[1];
	sPort += argv[2];
	sRoot += argv[3];
#endif

	return{ sIp, sPort, sRoot };
}

void runServer(communicatios comm)
{

	try
	{
		//trace(6, "ip: ", sIp.c_str(), " port: ", sPort.c_str(), " Root: ", sRoot.c_str());
		http::server::server s(comm.sIp, comm.sPort, comm.sRoot);

		// Run the server until stopped.
		s.run();
	}
	catch (std::exception& e)
	{
		std::cerr << "exception: " << e.what() << "\n";
	}

}

int main(int argc, char* argv[])
{
	communicatios comm = scanPram(argc, argv);

#ifdef ISLINUX

	if (fork())
	{
		return 0;
	}
	else
	{
		runServer(communicatios comm);
	}

#else
	std::thread tr(runServer, comm);

	int a; 
	std::cin >> a;
#endif

	return 0;
}