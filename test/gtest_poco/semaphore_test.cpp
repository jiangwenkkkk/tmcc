//
// Created by james on 2018-12-31.
//

#include <gtest/gtest.h>
#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "Poco/Semaphore.h"
#include "Poco/Exception.h"

using namespace Poco;
using Poco::Thread;
using Poco::Runnable;
using Poco::Semaphore;
using Poco::TimeoutException;

class SemaRunnable: public Runnable
{
public:
	SemaRunnable(int n, int max): _ran(false), _sema(n, max)
	{
	}

	void run()
	{
		_sema.wait();
		_ran = true;
	}

	bool ran() const
	{
		return _ran;
	}

	void set()
	{
		_sema.set();
	}

	void wait()
	{
		_sema.wait();
	}

	void wait(long milliseconds)
	{
		_sema.wait(milliseconds);
	}

	bool tryWait(long milliseconds)
	{
		return _sema.tryWait(milliseconds);
	}

private:
	bool _ran;
	Semaphore _sema;
};

TEST(semaphore_p,init_zero)
{
	SemaRunnable r(0, 3);
	assert (!r.tryWait(10));
	r.set();
	r.wait();
	try
	{
		r.wait(10000);
//		throw new Exception("timeout");
//		failmsg("must timeout");
	}
	catch (TimeoutException&)
	{
	}
	catch (...)
	{
	//	failmsg("wrong exception");
	}
	r.set();
	r.set();
	assert (r.tryWait(0));
	r.wait();
	assert (!r.tryWait(10));

	Thread t;
	t.start(r);
	Thread::sleep(100);
	assert (!r.ran());
	r.set();
	assert (r.ran());
	t.join();
	assert (r.ran());
	assert (!r.tryWait(10));
}

TEST(t, testInitNonZero)
{
	SemaRunnable r(2, 2);
	r.wait();
	assert (r.tryWait(10));
	assert (!r.tryWait(10));
	r.set();
	assert (r.tryWait(10));
	assert (!r.tryWait(10));
}

TEST(t, sem)
{
	SemaRunnable r(0, 3);
	assert (!r.tryWait(10));
	r.set();
	r.wait();
	try
	{
		r.wait(10000);
//		throw new Exception("timeout");
//		failmsg("must timeout");
	}
	catch (TimeoutException&)
	{
	}
	catch (...)
	{
		//	failmsg("wrong exception");
	}
	r.set();
	r.set();
	assert (r.tryWait(0));
	r.wait();
	assert (!r.tryWait(10));

	Thread t;
	t.start(r);
	Thread::sleep(100);
	assert (!r.ran());
	r.set();
	t.join();
	assert (r.ran());
	assert (!r.tryWait(10));
}