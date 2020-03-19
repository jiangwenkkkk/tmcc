//
// Created by james on 2019-02-23.
//

#include <gtest.h>
#include <Poco/Notification.h>
#include <Poco/NotificationCenter.h>
#include <Poco/Observer.h>
#include <Poco/Thread.h>
#include <Poco/NotificationQueue.h>
#include <Poco/AutoPtr.h>
#include <Poco/ThreadPool.h>
#include <Poco/Mutex.h>

using Poco::Notification;
using Poco::NotificationCenter;
using Poco::Observer;
using Poco::Thread;
using Poco::NotificationQueue;
using Poco::Runnable;

class hello_no : public Notification {
public:
	void say_hello() {
		std::cout << "hello" << std::endl;
	}

	void do_work() {
		std::cout << "work hard" << std::endl;
	}
};

class t_ob {
public:
	void say(hello_no *nm) {
		nm->say_hello();
	}
};

class t_oc {
public:
	void eat(hello_no *nc) {
		nc->do_work();
	}
};

TEST(notification_t, t) {
	t_ob tm;
	t_oc tc;
	Observer<t_ob, hello_no> a(tm, &t_ob::say);
	Observer<t_oc, hello_no> b(tc, &t_oc::eat);

	hello_no nt;
	NotificationCenter n_center;
	n_center.addObserver(a);
	n_center.addObserver(b);

	n_center.postNotification(&nt);
}

class WorkNotification : public Notification {
public:
	typedef Poco::AutoPtr<WorkNotification> Ptr;

	WorkNotification(int data) : _data(data) {}

	int data() {
		return _data;
	}

private:
	int _data;
};

class Worker : public Runnable {
public:
	//Worker(std::string name, NotificationQueue& queue) : _name(name), _queue(queue) {}
	Worker(const std::string& name, NotificationQueue& queue):
			_name(name),
			_queue(queue)
	{
	}
	void run() {
		for (;;) {
			Notification::Ptr pNf(_queue.waitDequeueNotification());
			if (pNf) {
				{
					Poco::FastMutex::ScopedLock lock(_mutex);
					WorkNotification *p = pNf.cast<WorkNotification>();
					if (p) {
						std::cout << _name << p->data() << std::endl;
					}
				}

			} else
				break;

		}
	}

private:
	std::string _name;
	NotificationQueue& _queue;
	static Poco::FastMutex _mutex;
};

Poco::FastMutex Worker::_mutex;

TEST(notification_thread, t) {
	NotificationQueue queue;
	Worker worker1("work1", queue);
	Worker worker2("work2", queue);
	Worker worker3("work3", queue);

	Poco::ThreadPool::defaultPool().start(worker1);
	Poco::ThreadPool::defaultPool().start(worker2);
	Poco::ThreadPool::defaultPool().start(worker3);

	for (int i = 0; i < 50; ++i) {
		queue.enqueueNotification(new WorkNotification(i));
	}

	while (!queue.empty()) Thread::sleep(200);

	queue.wakeUpAll();
	Poco::ThreadPool::defaultPool().joinAll();
}

