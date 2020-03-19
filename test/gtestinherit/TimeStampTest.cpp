//
// Created by james on 2019-12-03.
//

#include "gtestex.h"
#include "Poco/Timestamp.h"
#include "Poco/Thread.h"


using Poco::Timestamp;
using Poco::Thread;



TEST_F(LogTest, testTimestamp)
{
	Timestamp t1;

	std::cout << t1.epochTime() << std::endl;
	Thread::sleep(200);
	Timestamp t2;
	Timestamp t3 = t2;
	assert (t1 != t2);
	assert (!(t1 == t2));
	assert (t2 > t1);
	assert (t2 >= t1);
	assert (!(t1 > t2));
	assert (!(t1 >= t2));
	assert (t2 == t3);
	assert (!(t2 != t3));
	assert (t2 >= t3);
	assert (t2 <= t3);
	Timestamp::TimeDiff d = (t2 - t1);
	assert (d >= 180000 && d <= 300000);

	t1.swap(t2);
	assert (t1 > t2);
	t2.swap(t1);

	Timestamp::UtcTimeVal tv = t1.utcTime();
	Timestamp t4 = Timestamp::fromUtcTime(tv);
	assert (t1 == t4);

	Timestamp epoch(0);
	tv = epoch.utcTime();
	assert (tv >> 32 == 0x01B21DD2);
	assert ((tv & 0xFFFFFFFF) == 0x13814000);

	Timestamp now;
	Thread::sleep(201);
	assert (now.elapsed() >= 200000);
	assert (now.isElapsed(200000));
	assert (!now.isElapsed(2000000));
//	assert (-1==1);

#if defined(_WIN32)
	{
		Timestamp now;
		Poco::UInt32 low;
		Poco::UInt32 high;
		now.toFileTimeNP(low, high);
		Timestamp ts = Timestamp::fromFileTimeNP(low, high);
		assert (now == ts);
	}
#endif
}

TEST(time_stmp, t)
{
	Timestamp t1;
	Thread::sleep(2000);
	Timestamp t2;
	Timestamp t3 = t2;

	Timestamp::TimeDiff d = (t2 - t1);
	std::cout << d << std::endl;
}

//bool AuditMain::expired(int& cnt, Timestamp& now)
//{
//	if (cnt) {
//		cnt--;
//		return false;
//	}
//	else {
//		Timestamp last;
//		now.swap(last);
//		DateTime dt(now);
//		int min = dt.minute();
//		if (lastMinute != min && timeInterval != 0 && min % timeInterval == 5) {
//			lastMinute = min;
//			return true;
//		}
//		else {
//			Timestamp::TimeDiff td = now - last; //micro seconds
//			if (td > 30000000 || td <= 0)
//				cnt = 0;
//			else if (td < 300000)
//				cnt = 100;
//			else
//				cnt = 30000000 / td - 1;
//			ILOG << "Last minute: " << lastMinute << ", now: " << min << ENDL;
//			if (lastMinute != -1 && lastMinute != min && (lastMinute + 1) % 60 != min) {
//				int itermin = (lastMinute + 1) % 60;
//				while(itermin != min) {
//					if (timeInterval != 0 && itermin % timeInterval == 5) {
//						lastMinute = min;
//						ELOG << "Something wrong may happen, Last minute: " << lastMinute << ", now: " << min << ENDL;
//						return true;
//					}
//					itermin = (itermin+1) % 60;
//				}
//				lastMinute = min;
//			}
//			else {
//				lastMinute = min;
//			}
//			return false;
//		}
//	}
//}
//


