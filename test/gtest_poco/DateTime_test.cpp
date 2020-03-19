//
// Created by james on 2020-01-10.
//

#include <gtest.h>
#include <Poco/DateTime.h>
#include <Poco/Timestamp.h>


TEST(date_t, t)
{
	Poco::DateTime a;

	std::cout << a.month() << std::endl;
}

TEST(date_t, date_t_time_stamp_Test)
{
	Poco::Timestamp tmp;
	std::cout << tmp.epochMicroseconds() << std::endl;

	Poco::DateTime dateTime(tmp);
	std::cout << dateTime.month() << std::endl;
	std::cout << dateTime.day() << std::endl;

	Poco::Timestamp last = tmp.epochMicroseconds() - 2*60*60*24;
	std::cout << last.epochMicroseconds() << std::endl;
	std::cout << last.epochTime() << std::endl;
	Poco::DateTime dateTime1(last);
	std::cout << dateTime1.month() << std::endl;
	std::cout << dateTime1.day() << std::endl;
}

TEST(date_t, date_t_from_epochTime_Test)
{
	Poco::Timestamp tmp;
	auto last = Poco::Timestamp::fromEpochTime(tmp.epochTime() - 2*60*60*24);
	Poco::DateTime before_yesterday(last);
	std::cout << before_yesterday.day() << std::endl;
}