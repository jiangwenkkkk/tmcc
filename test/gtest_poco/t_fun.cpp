//
// Created by james on 2019-03-01.
//

#include <gtest.h>

TEST(system_t, t)
{
	int ret = system("ls");
	std::cout  << ret << std::endl;
	ret = system("compress /Users/james/jameswork/james_clion/¨testpoco/test_active.cpp");
	std::cout  << ret << std::endl;

}