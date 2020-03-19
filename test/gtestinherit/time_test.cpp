//
// Created by james on 2019-12-05.
//

#include "gtestex.h"

#include "DistributeTime.h"
#include "Poco/Timestamp.h"

#define _TRY try
#define _CATCH(action) catch(Poco::Exception& e) { action; 		ELOG<<"错误号:"<<e.code()<<ENDL;\
        ELOG<<"错误原因:"<<e.displayText()<<ENDL;	 }\
        catch(std::exception &e) {action; ELOG << "错误原因: " << e.what() << ENDL;}



TEST_F(LogTest, t_m) {
	C_Timer a;
	std::string crontab = "56,59,00,12,17,27; 10,11,14,16; *; *; *;";
	_TRY {
		if (!a.InitTimer(crontab))
			ELOG  <<  "加载IMSI定时刷参corntab失败"  <<  ENDL;
	}
	_CATCH();
	FLOG  << "I ok program...\n" << ENDL;
	for (int i = 0; i < 100000000; i++)
	{
		if (a.TimeOut())
			FLOG  << "I love program...\n" << ENDL;

		Poco::Thread::sleep(30000);
		FLOG << "I am wating you ###" << i%60 <<  ENDL;
	}



}

TEST_F(LogTest, t_timestamp)
{
	Poco::Timestamp a;
	sleep(1);
	Poco::Timestamp b;
	Poco::Timestamp::TimeDiff td = b - a;
	ILOG << td << ENDL;
}
