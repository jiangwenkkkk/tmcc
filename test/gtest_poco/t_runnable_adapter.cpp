//
// Created by james on 2019-02-20.
//

#include <gtest.h>
#include <Poco/RunnableAdapter.h>
#include <Poco/Thread.h>


using Poco::RunnableAdapter;
using Poco::Thread;
class test_ad
{
public:
	void say_hello()
	{
		std::cout << "helloa" << std::endl;
	}
};


TEST(r_ada, t)
{
	test_ad a;
	RunnableAdapter<test_ad> ra(a, &test_ad::say_hello);
	Thread thread;

	thread.start(ra);
	thread.join();
}

/*
 * 适配器非常好用啊,这样我就不用继承自runable了
 */