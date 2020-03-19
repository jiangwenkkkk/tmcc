//
// Created by james on 2019-02-18.
//
#include <gtest/gtest.h>
#include <Poco/Event.h>
#include <Poco/Thread.h>
#include <Poco/Runnable.h>

using Poco::Runnable;
using Poco::Event;
using Poco::Thread;

Event b;

void hello(void * arg)
{

	sleep(2);
	std::cout << "hello" << std::endl;

	b.wait();
}

class MyRunnable : public Runnable
{
public:
	MyRunnable():_ran(false),_event(false)
	{
	}
	void run()
	{
		Thread* pThread = Thread::current();
		if (pThread)
			_threadName = pThread->name();
		_ran = true;
		_event.wait();

	}
	void notify()
	{
		_event.set();
	}
private:
	bool _ran;
	std::string _threadName;
	Event _event;
};


class TrySleepRunnable : public Runnable
{
public:
	TrySleepRunnable()
	{

	}


	void run()
	{
		std::cout << "hi" << std::endl;
		Thread::trySleep(10000000);
		std::cout << "ok" << std::endl;
	}
private:
};
TEST(event, t)
{
	Poco::Event a;
	Poco::Thread thread;
	thread.start(hello);

	thread.join();
}

TEST(my_run, t)
{

	Poco::Thread thread;
	assert(!thread.isRunning());
	MyRunnable a;

	thread.start(a);

	assert(thread.isRunning());
	a.notify();
	thread.join();
	assert(!thread.isRunning());

}

TEST(thread_trywait, t)
{
	Thread a;
	TrySleepRunnable b;
	a.start(b);
	std::cout << "no" << std::endl;
	Thread::sleep(1000);
	std::cout << "no" << std::endl;
	a.wakeUp();
	a.join();
}


TEST(thread_e, t)
{
	Thread thread;
	Thread threadb;
	MyRunnable a;
	thread.start(a);
	threadb.start(a);
	a.notify();
	thread.join();
}

TEST(thread_t, ev_set)
{
	Poco::Event a;
	a.set();
	a.wait();
}



