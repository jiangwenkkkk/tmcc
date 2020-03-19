//
// Created by james on 2019-09-30.
//

#ifndef TESTPOCO_NOTIFICATION_TEST_H
#define TESTPOCO_NOTIFICATION_TEST_H
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
#include "my_task.h"

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



class SampleServer : public ServerApplication {
public:
	SampleServer() : _helpRequested(false) {
	}

	~SampleServer() {
	}

protected:
	void initialize(Application &self) {
		loadConfiguration(); // load default configuration files, if present
		ServerApplication::initialize(self);
		logger().information("starting up");
	}

	void uninitialize() {
		logger().information("shutting down");
		ServerApplication::uninitialize();
	}

	void defineOptions(OptionSet &options) {
		ServerApplication::defineOptions(options);

		options.addOption(
				Option("help", "d", "display help information on command line arguments")
						.required(false)
						.repeatable(false)
						.callback(OptionCallback<SampleServer>(this, &SampleServer::handleHelp)));
		options.addOption(
				Option("hello", "h", "show hello")
						.required(false)
						.argument("name=value")
						.repeatable(true)
						.callback(OptionCallback<SampleServer>(this, &SampleServer::handleHello)));
	}

	void handleHelp(const std::string &name, const std::string &value) {
		_helpRequested = true;
		displayHelp();
		stopOptionsProcessing();
	}

	void handleHello(const std::string &name, const std::string &value) {
		_helloRequested = true;
		sayHello();
		stopOptionsProcessing();
	}

	void displayHelp() {
		HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("OPTIONS");
		helpFormatter.setHeader(
				"A sample server application that demonstrates some of the features of the Util::ServerApplication class.");
		helpFormatter.format(std::cout);
	}

	void sayHello() {
		std::cout << "hello" << std::endl;
	}

	int main(const ArgVec &args) {
		if (!_helpRequested && !_helloRequested) {
			TaskManager tm;
			tm.start(new BuyfoodTask(foodQueue));
			tm.start(new CookfoodTask(foodQueue));
			waitForTerminationRequest();
			tm.cancelAll();
			tm.joinAll();
		}
		return Application::EXIT_OK;
	}

private:
	bool _helpRequested;
	bool _helloRequested;
	NotificationQueue foodQueue;
public:
	static FastMutex   _mutex;

};





#endif //TESTPOCO_NOTIFICATION_TEST_H
