#ifndef __DISTRIBUTE_TIME_H_
#define __DISTRIBUTE_TIME_H_



#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>

#include "Poco/StringTokenizer.h"
#include "Poco/RegularExpression.h"

#define LEN_CONFIG_STRING				2048
#define CRON_NUM								5

class C_Timer
{
		public:
				C_Timer();
				~C_Timer();
				
				bool InitTimer( std::string &corntime);
				bool TimeOut();
				bool GetCommand();
				void EnableTimer();
				void DisableTimer();
				
		private:
				bool SetTm( const struct tm* );
				bool TmEqualMinute( const struct tm*, const struct tm* );
				bool Match( const struct tm* );
				void ResetDataMember();
		private:
				short int    m_Minute[60];
				short int    m_Hour[24];
				short int    m_MonthDay[32];
				short int    m_Month[12];
				short int    m_WeekDay[7];
				             
				bool         m_FlagMinute;
				bool         m_FlagHour;
				bool         m_FlagMonthDay;
				bool         m_FlagMonth;
				bool         m_FlagWeekDay;
				             
				struct tm    m_LastAlarm;
				             
				bool         m_TimerIsAvailable;
				bool         m_IsTimeOut; 
};

#endif