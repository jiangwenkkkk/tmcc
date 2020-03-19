//
// Created by james on 2019-10-30.
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

//
// SharedPtrTest.cpp
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//



#include "Poco/SharedPtr.h"
#include "Poco/Exception.h"


using Poco::SharedPtr;
using Poco::NullPointerException;


namespace
{
	class TestObject
	{
	public:
		TestObject(const std::string& data): _data(data)
		{
			++_count;
		}

		virtual ~TestObject()
		{
			--_count;
		}

		const std::string& data()
		{
			return _data;
		}

		static int count()
		{
			return _count;
		}

	private:
		std::string _data;
		static int _count;
	};

	int TestObject::_count = 0;

	class DerivedObject: public TestObject
	{
	public:
		DerivedObject(const std::string& s, int i): TestObject(s), _number(i)
		{
		}

		int number() const
		{
			return _number;
		}

	private:
		int _number;
	};
}


TEST(SharedPtrTest,testSharedPtr)
{
	SharedPtr<TestObject> ptr1;
	assert(ptr1.get()==NULL);
	TestObject* pTO1 = new TestObject("one");
	TestObject* pTO2 = new TestObject("two");
	if (pTO2 < pTO1)
	{
		TestObject* pTmp = pTO1;
		pTO1 = pTO2;
		pTO2 = pTmp;
	}
	assert (pTO1 < pTO2);
	ptr1 = pTO1;
	assert (ptr1.referenceCount() == 1);
	SharedPtr<TestObject> ptr2 = pTO2;
	SharedPtr<TestObject> ptr3 = ptr1;
	assert (ptr1.referenceCount() == 2);
	SharedPtr<TestObject> ptr4;
	assert (ptr1.get() == pTO1);
	assert (ptr1 == pTO1);
	assert (ptr2.get() == pTO2);
	assert (ptr2 == pTO2);
	assert (ptr3.get() == pTO1);
	assert (ptr3 == pTO1);

	assert (ptr1 == pTO1);
	assert (ptr1 != pTO2);
	assert (ptr1 < pTO2);
	assert (ptr1 <= pTO2);
	assert (ptr2 > pTO1);
	assert (ptr2 >= pTO1);

	assert (ptr1 == ptr3);
	assert (ptr1 != ptr2);
	assert (ptr1 < ptr2);
	assert (ptr1 <= ptr2);
	assert (ptr2 > ptr1);
	assert (ptr2 >= ptr1);

	ptr1.swap(ptr2);
	assert (ptr2 < ptr1);
	ptr2.swap(ptr1);

	assert ((ptr1->data() == "one" && ptr2->data() == "two") || (ptr1->data() == "two" && ptr2->data() == "one"));

	try
	{
		assert (ptr4->data() == "four");
//		fail ("must throw NullPointerException");
		throw Exception("bad",10);
	}
	catch (NullPointerException&)
	{
	}

	assert (!(ptr4 == ptr1));
	assert (!(ptr4 == ptr2));
	assert (ptr4 != ptr1);
	assert (ptr4 != ptr2);

	ptr4 = ptr2;
	assert (ptr4 == ptr2);
	assert (!(ptr4 != ptr2));

	assert (TestObject::count() == 2);
	ptr1 = 0;
	ptr2 = 0;
	ptr3 = 0;
	ptr4 = 0;
	assert (TestObject::count() == 0);

	{
		SharedPtr<TestObject> ptr = new TestObject("");
		assert (TestObject::count() == 1);
	}
	assert (TestObject::count() == 0);
}


TEST(SharedPtrTest,testImplicitCast)
{
	{
		// null assign test
		SharedPtr<DerivedObject> ptr2;
		assert(ptr2.get()==NULL);
		SharedPtr<TestObject> ptr1 = ptr2;
	}
	{
		SharedPtr<DerivedObject> ptr2(new DerivedObject("test", 666));
		assert (TestObject::count() == 1);
		SharedPtr<TestObject> ptr1 = ptr2;
		assert (TestObject::count() == 1);
	}
	assert (TestObject::count() == 0);
	SharedPtr<TestObject> ptr1 = new DerivedObject("test", 666);
	assert (TestObject::count() == 1);
	ptr1 = 0;
	assert (TestObject::count() == 0);
}


TEST( SharedPtrTest,testExplicitCast)
{
	SharedPtr<TestObject> ptr1 = new DerivedObject("test", 666);
	SharedPtr<DerivedObject> ptr2 = ptr1.cast<DerivedObject>();
	assert (ptr2.get() != 0);

	// cast the other way round must fail
	ptr1 = new TestObject("test");
	assert (TestObject::count() == 2);
	ptr2 = ptr1.cast<DerivedObject>();
	assert (TestObject::count() == 1);
	assert (ptr2.get() == 0);
}

TEST(new_ptr, new_ptr_had)
{
	int * ptr = new int(10);
	delete ptr;
	*ptr = 11;
	int * a = new int(110);

	std::cout << *ptr << std::endl;

	SharedPtr<int> c = new int(12);
	int *d  = c.get();
	std::cout << *d << std::endl;

	c = new int(113);

	std::cout << *d << std::endl;

}



