//
// Created by james on 2019-01-01.
//

#include <gtest/gtest.h>

#include "Poco/Clock.h"
#include "Poco/Thread.h"
#include <iostream>


using Poco::Clock;
using Poco::Thread;

TEST( ClockTest,testClock)
{
	Clock t1;
	Thread::sleep(200);
	Clock t2;
	Clock t3 = t2;
	assert (t1 != t2);
	assert (!(t1 == t2));
	assert (t2 > t1);
	assert (t2 >= t1);
	assert (!(t1 > t2));
	assert (!(t1 >= t2));
	assert (t2 == t3);
	assert (!(t2 != t3));
	assert (t2 >= t3);
	assert (t2 <= t3);
	Clock::ClockDiff d = (t2 - t1);
	assert (d >= 180000 && d <= 300000);

	Clock::ClockDiff acc = Clock::accuracy();
	assert (acc > 0 && acc < Clock::resolution());
	std::cout << "Clock accuracy: " << acc << std::endl;

	t1.swap(t2);
	assert (t1 > t2);
	t2.swap(t1);

	Clock now;
	Thread::sleep(201);
	assert (now.elapsed() >= 200000);
	assert (now.isElapsed(200000));
	assert (!now.isElapsed(2000000));
}