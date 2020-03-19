//
// Created by james on 2019-09-30.
//

#ifndef TESTPOCO_MY_TASK_H
#define TESTPOCO_MY_TASK_H
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Task.h"
#include "Poco/TaskManager.h"
#include "Poco/DateTimeFormatter.h"
#include <iostream>
#include "Poco/NotificationQueue.h"
#include "Poco/Notification.h"
#include "Poco/AutoPtr.h"
#include "Poco/Mutex.h"
#include "Poco/Thread.h"
#include "notification_test.h"

using Poco::Thread;
using Poco::Util::Application;
using Poco::Util::ServerApplication;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::OptionCallback;
using Poco::Util::HelpFormatter;
using Poco::Task;
using Poco::TaskManager;
using Poco::DateTimeFormatter;
using Poco::NotificationQueue;
using Poco::Notification;
using Poco::AutoPtr;
using Poco::FastMutex;


class WorkNotification: public Notification
	// The notification sent to worker threads.
{
public:
	typedef AutoPtr<WorkNotification> Ptr;

	WorkNotification(int data):
			_data(data)
	{
	}

	int data() const
	{
		return _data;
	}

private:
	int _data;
};

class CookfoodTask : public Task{
public:
	CookfoodTask(NotificationQueue &queue) :_queue(queue),Task("CookfoodTask"){

	}
	void runTask();
private:
	NotificationQueue& _queue;

};

class EatfoodTask : public Task{
public:
	EatfoodTask(NotificationQueue &)
};

class BuyfoodTask : public Task {
public:
	BuyfoodTask(NotificationQueue& queue) : _queue(queue), Task("BuyfoodTask") {
	}

	void runTask() {
		for(int i = 0; i< 100000; i++)
		{
			_queue.enqueueNotification(new WorkNotification(i));
		}

		while (!_queue.empty()) Thread::sleep(200);
		Thread::sleep(500);

		// stop all worker threads
		_queue.wakeUpAll();
	}

private:
	NotificationQueue& _queue;
};

#endif //TESTPOCO_MY_TASK_H
