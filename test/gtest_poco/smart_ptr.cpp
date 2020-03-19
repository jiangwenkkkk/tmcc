//
// Created by james on 2019-02-21.
//

#include <gtest.h>
#include <memory>
#include <Poco/AutoPtr.h>


class smart_ptr{
public:
	smart_ptr(int a):_a(a)
	{}

	void say_a()
	{
		std::cout << _a << std::endl;
	}

	virtual ~smart_ptr() {
		std::cout << "brok" << std::endl;

	}
	void release()
	{
		_count--;
		if(_count == 0)
			delete this;
	}

	void duplicate()
	{
		++_count;
	}


private:
	int _a;
	int _count;
};

class Cant_copy
{
public:
	void release()
	{
		;
	}

};

TEST(hello, t)
{
	{
		std::auto_ptr<smart_ptr> a(new smart_ptr(9));
		a->say_a();
		auto b = a;
	}

	std::cout << "ok" << std::endl;
}

TEST(unique_ptr_t, copy)
{
//	std::unique_ptr<smart_ptr> a(new smart_ptr(11));

//	auto b = std::move(a);
}

TEST(P_auto_ptr, t)
{
	Poco::AutoPtr<smart_ptr> a(new smart_ptr(1));
	auto b = a;

	assert(!a);
}