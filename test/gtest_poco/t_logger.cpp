//
// Created by james on 2019-02-25.
//

#include <gtest.h>
#include <Poco/ConsoleChannel.h>

using Poco::ColorConsoleChannel;

TEST(logger_t, t)
{
	system("open .");
}

TEST(color_logger_t, t)
{
	std::cout << "\033["<<"1m" << "\033["<<"33"<<"m" <<"hello"<<"\033["<<"0m" <<std::endl;
	std::cout << "\033[01;34m Hello World\033[0m" << std::endl;
	printf("\033[01;34m Hello World\033[0m\n");

}

TEST(adb,bc)
{
	int a = 0x00;
	a >> 7;
	std::cout << a;
}