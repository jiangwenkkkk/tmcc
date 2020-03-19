//
// Created by james on 2019-09-30.
//

//
// NotificationCenterTest.cpp
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Poco/NotificationCenter.h"
#include "Poco/Observer.h"
#include "Poco/NObserver.h"
#include "Poco/AutoPtr.h"
#include <gtest/gtest.h>


using Poco::NotificationCenter;
using Poco::Observer;
using Poco::NObserver;
using Poco::Notification;
using Poco::AutoPtr;


class TestNotification: public Notification
{
};


class NotificationCenterTest
{
public:
	NotificationCenterTest(const std::string& name){}
	~NotificationCenterTest(){}


public:
	void handle1(Poco::Notification* pNf);
	void handle2(Poco::Notification* pNf);
	void handle3(Poco::Notification* pNf);
	void handleTest(TestNotification* pNf);
	void handleAuto(const Poco::AutoPtr<Poco::Notification>& pNf);

public:
	std::set<std::string> _set;
};


TEST(NotificationCenterTest, test1 )
{
	NotificationCenter nc;
	nc.postNotification(new Notification);
}

//
TEST( NotificationCenterTest,test2)
{
	NotificationCenter nc;
	auto pNotificationCenterTest = new NotificationCenterTest("hell");
	Observer<NotificationCenterTest, Notification> o(*pNotificationCenterTest, &NotificationCenterTest::handle1);
	nc.addObserver(o);
	assert (nc.hasObserver(o));
	assert (nc.hasObservers());
	assert (nc.countObservers() == 1);
	nc.postNotification(new Notification);
	assert (pNotificationCenterTest->_set.size() == 1);
	assert (pNotificationCenterTest->_set.find("handle1") != pNotificationCenterTest->_set.end());
	nc.removeObserver(Observer<NotificationCenterTest, Notification>(*pNotificationCenterTest, &NotificationCenterTest::handle1));
	assert (!nc.hasObserver(o));
	assert (!nc.hasObservers());
	assert (nc.countObservers() == 0);
}

//
TEST( NotificationCenterTest,test3)
{
	NotificationCenter nc;
	auto pNotificationCenterTest = new NotificationCenterTest("hell");
	Observer<NotificationCenterTest, Notification> o1(*pNotificationCenterTest, &NotificationCenterTest::handle1);
	Observer<NotificationCenterTest, Notification> o2(*pNotificationCenterTest, &NotificationCenterTest::handle2);
	nc.addObserver(o1);
	assert (nc.hasObserver(o1));
	nc.addObserver(o2);
	assert (nc.hasObserver(o2));
	assert (nc.hasObservers());
	assert (nc.countObservers() == 2);
	nc.postNotification(new Notification);
	assert (pNotificationCenterTest->_set.size() == 2);
	assert (pNotificationCenterTest->_set.find("handle1") != pNotificationCenterTest->_set.end());
	assert (pNotificationCenterTest->_set.find("handle2") != pNotificationCenterTest->_set.end());
	nc.removeObserver(Observer<NotificationCenterTest, Notification>(*pNotificationCenterTest, &NotificationCenterTest::handle1));
	assert (!nc.hasObserver(o1));
	nc.removeObserver(Observer<NotificationCenterTest, Notification>(*pNotificationCenterTest, &NotificationCenterTest::handle2));
	assert (!nc.hasObserver(o2));
	assert (!nc.hasObservers());
	assert (nc.countObservers() == 0);
}


TEST( NotificationCenterTest,test4)
{
	NotificationCenter nc;
	auto pNotificationCenterTest = new NotificationCenterTest("hell");
	Observer<NotificationCenterTest, Notification> o1(*pNotificationCenterTest, &NotificationCenterTest::handle1);
	Observer<NotificationCenterTest, Notification> o2(*pNotificationCenterTest, &NotificationCenterTest::handle2);
	nc.addObserver(o1);
	assert (nc.hasObserver(o1));
	nc.addObserver(o2);
	assert (nc.hasObserver(o2));
	nc.postNotification(new Notification);
	assert (pNotificationCenterTest->_set.size() == 2);
	assert (pNotificationCenterTest->_set.find("handle1") != pNotificationCenterTest->_set.end());
	assert (pNotificationCenterTest->_set.find("handle2") != pNotificationCenterTest->_set.end());
	nc.removeObserver(Observer<NotificationCenterTest, Notification>(*pNotificationCenterTest, &NotificationCenterTest::handle1));
	assert (!nc.hasObserver(o1));
	nc.removeObserver(Observer<NotificationCenterTest, Notification>(*pNotificationCenterTest, &NotificationCenterTest::handle2));
	assert (!nc.hasObserver(o2));
	pNotificationCenterTest->_set.clear();
	nc.postNotification(new Notification);
	assert (pNotificationCenterTest->_set.empty());
	Observer<NotificationCenterTest, Notification> o3(*pNotificationCenterTest, &NotificationCenterTest::handle3);
	nc.addObserver(o3);
	assert (nc.hasObserver(o3));
	nc.postNotification(new Notification);
	assert (pNotificationCenterTest->_set.size() == 1);
	assert (pNotificationCenterTest->_set.find("handle3") != pNotificationCenterTest->_set.end());
	nc.removeObserver(Observer<NotificationCenterTest, Notification>(*pNotificationCenterTest, &NotificationCenterTest::handle3));
	assert (!nc.hasObserver(o3));
}

//
TEST( NotificationCenterTest,test5)
{
	NotificationCenter nc;
	auto pNotificationCenterTest = new NotificationCenterTest("hell");
	nc.addObserver(Observer<NotificationCenterTest, Notification>(*pNotificationCenterTest, &NotificationCenterTest::handle1));
	nc.addObserver(Observer<NotificationCenterTest, TestNotification>(*pNotificationCenterTest, &NotificationCenterTest::handleTest));
	nc.postNotification(new Notification);
	assert (pNotificationCenterTest->_set.size() == 1);
	assert (pNotificationCenterTest->_set.find("handle1") != pNotificationCenterTest->_set.end());
	pNotificationCenterTest->_set.clear();
	nc.postNotification(new TestNotification);
	assert (pNotificationCenterTest->_set.size() == 2);
	assert (pNotificationCenterTest->_set.find("handle1") != pNotificationCenterTest->_set.end());
	assert (pNotificationCenterTest->_set.find("handleTest") != pNotificationCenterTest->_set.end());
	nc.removeObserver(Observer<NotificationCenterTest, Notification>(*pNotificationCenterTest, &NotificationCenterTest::handle1));
	nc.removeObserver(Observer<NotificationCenterTest, TestNotification>(*pNotificationCenterTest, &NotificationCenterTest::handleTest));
}
//
//
//void NotificationCenterTest::testAuto()
//{
//	NotificationCenter nc;
//	nc.addObserver(NObserver<NotificationCenterTest, Notification>(*this, &NotificationCenterTest::handleAuto));
//	nc.postNotification(new Notification);
//	assert (_set.size() == 1);
//	assert (_set.find("handleAuto") != _set.end());
//	nc.removeObserver(NObserver<NotificationCenterTest, Notification>(*this, &NotificationCenterTest::handleAuto));
//}
//
//
//void NotificationCenterTest::testDefaultCenter()
//{
//	NotificationCenter& nc = NotificationCenter::defaultCenter();
//	nc.addObserver(Observer<NotificationCenterTest, Notification>(*this, &NotificationCenterTest::handle1));
//	nc.postNotification(new Notification);
//	assert (_set.size() == 1);
//	assert (_set.find("handle1") != _set.end());
//	nc.removeObserver(Observer<NotificationCenterTest, Notification>(*this, &NotificationCenterTest::handle1));
//}
//

void NotificationCenterTest::handle1(Poco::Notification* pNf)
{
	poco_check_ptr (pNf);
	AutoPtr<Notification> nf = pNf;
	_set.insert("handle1");
}


void NotificationCenterTest::handle2(Poco::Notification* pNf)
{
	poco_check_ptr (pNf);
	AutoPtr<Notification> nf = pNf;
	_set.insert("handle2");
}


void NotificationCenterTest::handle3(Poco::Notification* pNf)
{
	poco_check_ptr (pNf);
	AutoPtr<Notification> nf = pNf;
	_set.insert("handle3");
}


void NotificationCenterTest::handleTest(TestNotification* pNf)
{
	poco_check_ptr (pNf);
	AutoPtr<TestNotification> nf = pNf;
	_set.insert("handleTest");
}


void NotificationCenterTest::handleAuto(const AutoPtr<Notification>& pNf)
{
	_set.insert("handleAuto");
}


