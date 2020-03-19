//
// Created by james on 2019-02-26.
//

#include <Poco/Environment.h>
#include <gtest.h>

TEST(env_t, t)
{
	std::cout << Poco::Environment::osName()  << std::endl;
	std::cout << Poco::Environment::osVersion()  << std::endl;
	std::cout << Poco::Environment::nodeName()  << std::endl;
	std::cout << Poco::Environment::osDisplayName()  << std::endl;
	std::cout << Poco::Environment::nodeId()  << std::endl;
}