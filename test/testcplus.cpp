//
// Created by james on 2018/8/13.
//

#include <gtest/gtest.h>
#include <Poco/Dynamic/Struct.h>
#include <Poco/Dynamic/Pair.h>
//#include <utility>

#include "Poco/HashMap.h"

#include "Poco/ThreadLocal.h"
#include "Poco/Thread.h"


#include "Poco/RandomStream.h"


using namespace std;
using namespace Poco;

//mutable can change value in const function
class name {
public:
	void print_name() const {
		cout << _name << endl;
		times++;
		cout << times << endl;
	}

	name(string na) : _name(na), times(0) {}

private:
	const string _name;
	mutable int times;
};

class var {

};

TEST(cplus, multable_t) {
	name tm("tom");
	tm.print_name();

}

//class var{
//public:
//	void swap(var fo){
//		std::swap();
//	}
//
//public:
//	int a;
//};

TEST(swap_s, t) {
	int a = 10;
	int b = 11;
	swap(a, b);
	cout << a;

}

TEST(p_Struct, t) {
	using Poco::Dynamic::Struct;
	Struct<int> a;
	int b = 10;
	auto cm = a.insert(make_pair(10, 11));
	a.insert(make_pair(13, 33));
	a.insert(make_pair(15, 33));
	a.insert(make_pair(14, 33));
	a.insert(make_pair(16, 33));
	a.insert(make_pair(13, 3773));
	auto tm = a.find(10);
}

TEST(p_pair, t) {
	using Poco::Dynamic::Pair;
	Pair<int> a(make_pair(11, 33));
	auto m = a.toString();
	cout << m << endl;
}

TEST(var_t, t_u) {
	const int N = 1000;

	typedef HashMap<int, int> IntMap;
	IntMap hm;

	for (int i = 0; i < N; ++i) {
		hm.insert(IntMap::ValueType(i, i * 2));
	}
	assert (hm.size() == N);

	for (int i = 0; i < N; i += 2) {
		hm.erase(i);
		IntMap::Iterator it = hm.find(i);
		assert (it == hm.end());
	}
	assert (hm.size() == N / 2);

	for (int i = 0; i < N; i += 2) {
		IntMap::Iterator it = hm.find(i);
		assert (it == hm.end());
	}

	for (int i = 1; i < N; i += 2) {
		IntMap::Iterator it = hm.find(i);
		assert (it != hm.end());
		assert (*it == i);
	}

	for (int i = 0; i < N; i += 2) {
		hm.insert(IntMap::ValueType(i, i * 2));
	}

	for (int i = 0; i < N; ++i) {
		IntMap::Iterator it = hm.find(i);
		assert (it != hm.end());
		assert (it->first == i);
		assert (it->second == i * 2);
	}
}

class TLTestRunnable : public Runnable {
public:
	TLTestRunnable(int n) : _n(n) {
	}

	void run() {
		*_count = 0;
		for (int i = 0; i < _n; ++i)
			++(*_count);
		_result = *_count;
	}

	int result() {
		return _result;
	}

private:
	int _n;
	int _result;
	static ThreadLocal<int> _count;
};

ThreadLocal<int> TLTestRunnable::_count;

class test_pro : public Runnable {
public:
	void run() {
		for (int i = 0; i < 10000; ++i) {
			std::cout << "hello world" << std::endl;

		}
	}
};

TEST(threadlocal, test_locality) {
	TLTestRunnable r1(5000);
	TLTestRunnable r2(7500);
	TLTestRunnable r3(6000);
	test_pro r4;
	test_pro r5;
	Thread t1;
	Thread t2;
	Thread t3;
	Thread t4;
	Thread t5;
	t4.start(r4);
	t1.start(r1);
	t2.start(r2);
	t3.start(r3);
	t3.start(r5);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	assert (r1.result() == 5000);
	assert (r2.result() == 7500);
	assert (r3.result() == 6000);
}

TEST(RandomStream, stream) {
	RandomInputStream rnd;

	const int n = 16;
	std::vector<int> d(n, 0);
	for (int i = 0; i < 1000; ++i) {
		unsigned char c;
		rnd >> c;
		d[c & 0x0F]++;
		d[(c >> 4) & 0x0F]++;
	}
	int sum = 0;
	for (int k = 0; k < n; ++k) sum += d[k];
	int avg = sum / n;
	int var = 0;
	for (int k = 0; k < n; ++k) var += (d[k] - avg) * (d[k] - avg);
	var /= n;
	int sd = int(std::sqrt((double) var));

	assert (110 < avg && avg < 140);
	assert (sd < 20);
}