//
// Created by james on 2019-12-03.
//

#include "gtest.h"
#include "auditMain.h"
#include "DistributeTime.h"

#define _TRY try
#define _CATCH(action) catch(Poco::Exception& e) { action; 		ELOG<<"错误号:"<<e.code()<<ENDL;\
        ELOG<<"错误原因:"<<e.displayText()<<ENDL;	 }\
        catch(exception &e) {action; ELOG << "错误原因: " << e.what() << ENDL;}

TEST(audit_main, expire_t)
{
	auto a = audit::AuditMain();
	a.start();
}

TEST(time_crontab, t_m) {
	C_Timer a;
	std::string crontab = "*; *; *; *; *;";
	_TRY {
		if (!a.InitTimer(crontab))
			return;
	}
	_CATCH();

	for (int i = 0; i < 100000000; i++)
	{
		if (a.TimeOut())
			std::cout << "I love program...\n" << std::endl;

		Poco::Thread::sleep(900);
		std::cout << "I am wating you ###" << i%60 <<  std::endl;
	}



}