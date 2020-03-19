//
// Created by james on 2019-01-03.
//

#include "UDPEchoServer.h"
#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/NetworkInterface.h"
#include "Poco/Net/NetException.h"
#include "Poco/Timespan.h"
#include "Poco/Stopwatch.h"
#include <gtest.h>

using Poco::Net::Socket;
using Poco::Net::DatagramSocket;
using Poco::Net::SocketAddress;
using Poco::Net::IPAddress;
#ifdef POCO_NET_HAS_INTERFACE
using Poco::Net::NetworkInterface;
#endif
using Poco::Timespan;
using Poco::Stopwatch;
using Poco::TimeoutException;
using Poco::InvalidArgumentException;
using Poco::IOException;



TEST(DatagramSocketTest,testEcho)
{
	UDPEchoServer echoServer;
	DatagramSocket ss;
	char buffer[256];
	ss.connect(SocketAddress("127.0.0.1", echoServer.port()));
	int n = ss.sendBytes("hello", 5);
	assert (n == 5);
	n = ss.receiveBytes(buffer, sizeof(buffer));
	assert (n == 5);
	assert (std::string(buffer, n) == "hello");
	ss.close();
}
