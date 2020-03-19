//
// Created by james on 2019-05-02.
//

#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
#include <gtest.h>
#include <stdlib.h>
#include <string>

char* fun()
{
	system("say hello");
	return "hello";
}
TEST(sync, t)
{
	std::future<char*> result1( std::async(fun));

	std::cout << result1.get() << std::endl;
}

TEST(pair_t,t)
{
	std::pair<int, int> a;
}

class book
{
private:
	std::string name;
public:

};