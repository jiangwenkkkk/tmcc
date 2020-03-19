//
// Created by james on 2019-02-21.
//

#include <gtest.h>
#include <Poco/Task.h>
#include <Poco/Thread.h>
#include <Poco/TaskManager.h>
#include <poco/ThreadPool.h>
#include "my_task.h"

using namespace Poco;

class test_task : public Poco::Task
{
public:
	test_task():Task("test_task"){}
	void runTask(){
		std::cout << "hello" << __FILE__ << __FUNCTION__<< "\n" << std::endl;
	}
};

class show_name : public Poco::Task
{
public:
	show_name():Task("show_name"){}
	void runTask()
	{
		std::cout << "ok" << std::endl;
	}
};

//class SimpleTask: public Poco::Task
//{
//public:
//	SimpleTask(): Task("SimpleTask")
//	{
//	}
//
//	void runTask()
//	{
//		std::cout << "hello" << std::endl;
////		sleep(10000);
//	}
//};

TEST(task_t, t)
{
//	std::string name = "hello";
	test_task a;
	Poco::Thread thread;
	thread.start(a);
	thread.join();
}

TEST(task_manager_t, t) {
	test_task a;

	Poco::TaskManager tm;
	tm.start(&a);
	tm.start(&a);
	tm.start(new show_name);
	tm.cancelAll();
	tm.joinAll();
}

