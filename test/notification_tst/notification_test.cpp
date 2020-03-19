//
// Created by james on 2019-09-30.
//

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
#include "notification_test.h"
#include "my_task.h"
//#include "notification_test.h"

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

class SampleServer;
class CookfoodTask;
class BuyfookTask;


void CookfoodTask::runTask(){
	for(;;)
	{
		Notification::Ptr pNf(_queue.waitDequeueNotification());
		if (pNf)
		{
			WorkNotification::Ptr pWorkNf = pNf.cast<WorkNotification>();
			if (pWorkNf)
			{
				{

					FastMutex::ScopedLock lock(SampleServer::_mutex);
						std::cout << name() << " got work notification " << pWorkNf->data() << std::endl;
				}
//					Thread::sleep(rnd.next(200));
			}
		} else
			break;
	}

}



FastMutex SampleServer::_mutex;

int main(int argc, char **argv) {
	try {
		SampleServer app;
		return app.run(argc, argv);
	}
	catch (Poco::Exception &exc) {
		std::cerr << exc.displayText() << std::endl;
		return Poco::Util::Application::EXIT_SOFTWARE;
	}
}

