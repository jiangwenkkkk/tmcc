//
// Created by james on 2019-02-18.
//

#include <gtest/gtest.h>
#include <Poco/Activity.h>
#include <Poco/Thread.h>

using Poco::Activity;
using Poco::Thread;
namespace {
	class ActiveObject
	{
	public:
		ActiveObject():_activity(this, &ActiveObject::run){}
		Activity<ActiveObject>& activity()
		{
			return _activity;
		}

	protected:
		void run()
		{
			int i = 0;
			while(!_activity.isStopped())
				std::cout << i++ << std::endl;
			std::cout << "ok" << std::endl;

		}


	private:
		Activity<ActiveObject> _activity;
	};
}

TEST(NamedEvent_test,t)
{
	ActiveObject me;
	me.activity().start();
	Thread::sleep(1);
	me.activity().stop();
}