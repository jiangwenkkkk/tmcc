//
// Created by james on 2020-07-07.
//

#ifndef TESTPOCO_COUNTER_H
#define TESTPOCO_COUNTER_H


#include <boost/core/noncopyable.hpp>
#include <mutex>


class Counter: boost::noncopyable {
public:
	Counter():value_(0){}
	int64_t value() const;
	int64_t getAndIncrease();

//	Counter(const std::mutex &mutex);

public:
private:
	int64_t value_;
	mutable std::mutex mutex_;
};


#endif //TESTPOCO_COUNTER_H
