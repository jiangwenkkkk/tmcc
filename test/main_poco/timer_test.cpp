//
// Created by james on 2019-11-03.
//

#include "Poco/Thread.h"
#include "Poco/Stopwatch.h"

#include "Poco/Foundation.h"
#include "Poco/Timer.h"
#include "Poco/Event.h"
#include <iostream>

using Poco::Timer;
using Poco::TimerCallback;
using Poco::Thread;
using Poco::Stopwatch;

class TimerTest
{
public:
	TimerTest(const std::string& name):_name(name){

	}
	~TimerTest(){}


public:
	void onTimer(Poco::Timer& t)
	{
		std::cout << "hello" << std::endl;
		std::cout << _name << std::endl;
	}

private:
	std::string _name;
	Poco::Event _event;
};

int main()
{
	Poco::Timer timer(0, 60000);
	TimerTest timerTest("test");
	TimerCallback<TimerTest> tc(timerTest, &TimerTest::onTimer);

	timer.start(tc);
	Poco::Thread::sleep(100000);
	timer.stop();

}
