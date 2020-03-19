//
// Created by james on 2019-08-19.
//

#ifndef TESTPOCO_MY_TASK_H
#define TESTPOCO_MY_TASK_H

#include <gtest.h>
#include <Poco/Task.h>
#include <Poco/Thread.h>
#include <Poco/TaskManager.h>
#include <poco/ThreadPool.h>

using namespace Poco;

class SimpleTask: public Poco::Task
{
public:
	SimpleTask(): Task("SimpleTask")
	{
	}

	void runTask()
	{
		std::cout << "hello" << std::endl;
//		sleep(10000);
	}
};




#endif //TESTPOCO_MY_TASK_H
