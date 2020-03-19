#include "DistributeTime.h"

using namespace std;
using namespace Poco;

/*初始化时间事件管理器*/
C_Timer::C_Timer()
{
		ResetDataMember();
}


/*销毁时间时间管理器*/
C_Timer::~C_Timer()
{
		ResetDataMember();
}


/*重置时间事件*/
void C_Timer::ResetDataMember()
{
		memset( m_Minute, 0, sizeof(m_Minute) );
		memset( m_Hour, 0, sizeof(m_Hour) );
		memset( m_MonthDay, 0, sizeof(m_MonthDay) );
		memset( m_Month, 0, sizeof(m_Month) );
		memset( m_WeekDay, 0, sizeof(m_WeekDay) );
		m_FlagMinute = true;
		m_FlagHour = true;
		m_FlagMonthDay = true;
		m_FlagMonth = true;
		m_FlagWeekDay = true;
		memset( &m_LastAlarm, 0, sizeof(m_LastAlarm) );
		m_TimerIsAvailable = false;
		m_IsTimeOut = false;
}


/*时间点比较。精确度：分钟*/
bool C_Timer::TmEqualMinute( const struct tm* tm_A, const struct tm* tm_B )
{
		if( tm_A->tm_min != tm_B->tm_min )
		{
				return false;
		}

		if( tm_A->tm_hour != tm_B->tm_hour )
		{
				return false;
		}

		if( tm_A->tm_mday != tm_B->tm_mday )
		{
				return false;
		}

		if( tm_A->tm_mon != tm_B->tm_mon )
		{
				return false;
		}

		if( tm_A->tm_year != tm_B->tm_year )
		{
				return false;
		}

		if( tm_A->tm_wday != tm_B->tm_wday )
		{
				return false;
		}

		if( tm_A->tm_yday != tm_B->tm_yday )
		{
				return false;
		}

		if( tm_A->tm_isdst != tm_B->tm_isdst )
		{
				return false;
		}

		return true;
}


/*检测时间点是否已经计算*/
bool C_Timer::SetTm( const struct tm* in_pTm )
{

		if( true == TmEqualMinute( in_pTm, &m_LastAlarm ) )
		{
				return false;
		}
		else
		{
				memset( &m_LastAlarm, 0, sizeof(struct tm) );
				memcpy( &m_LastAlarm, in_pTm, sizeof(struct tm) );
				return true;
		}
}


/*crontab计划时间点匹配*/
bool C_Timer::Match( const struct tm* in_pTm )
{

		if( 1 !=  m_Minute[in_pTm->tm_min] )
		{
				return false;
		}

		if( true == m_FlagHour )
		{
				if( 1 != m_Hour[in_pTm->tm_hour] )
				{
						return false;
				}
		}

		if( true == m_FlagMonthDay )
		{
				if( 1 != m_MonthDay[in_pTm->tm_mday] )
				{
						return false;
				}
		}

		if( true == m_FlagMonth )
		{
				if( 1 != m_Month[in_pTm->tm_mon] )
				{
						return false;
				}
		}

		if( true == m_FlagWeekDay )
		{
				if( 1 != m_WeekDay[in_pTm->tm_wday] )
				{
						return false;
				}
		}

		return true;

}
/*已触发事件获取*/
bool C_Timer::GetCommand()
{
	  if( false == m_TimerIsAvailable )
		{
				return false;
		};

		if( true == m_IsTimeOut )
		{
				m_IsTimeOut = false;
				return true;
		}
		else
		{
				return false;
		}
};


/*时间点检测*/
bool C_Timer::TimeOut()
{
		if( false == m_TimerIsAvailable )
		{
				return false;
		}

		time_t     t_Time;
		struct tm* t_pTm;

		time( &t_Time );
		t_pTm = localtime( &t_Time );

		if( false == Match( t_pTm ) )
		{
				return false;
		}

		if( false == SetTm( t_pTm ) )
		{
				return false;
		}
		else
		{
				m_IsTimeOut = true;
				return true;
		}

}


/*启动timer*/
void C_Timer::EnableTimer()
{
		m_TimerIsAvailable = true;
}


/*禁用timer*/
void C_Timer::DisableTimer()
{
		m_TimerIsAvailable = false;
}



/*载入时间事件到事件管理器中*/
bool C_Timer::InitTimer( std::string &corntime)
{
		char* t_pchLeft ;
		char* t_pchRight;
		
		//定时配置
		if(corntime.empty())
		{
				return false;
		}
		//分隔字符串
		StringTokenizer t1(corntime, ";",StringTokenizer::TOK_TRIM | StringTokenizer::TOK_IGNORE_EMPTY);

		if(t1.count()!=CRON_NUM)
		{
				return false;
		}
		
		char  t_cronTemp[CRON_NUM][LEN_CONFIG_STRING+1];

		memset( t_cronTemp, 0, sizeof(t_cronTemp) );
		int t_iCounter = 0;
		for( t_iCounter = 0; t_iCounter < CRON_NUM; t_iCounter++ )
		{
				memcpy( t_cronTemp[t_iCounter],t1[t_iCounter].c_str(),t1[t_iCounter].length());
		}
		
		/*分钟不能为空或者配置通配符号* */
		for( t_iCounter=0; t_iCounter < CRON_NUM; t_iCounter++ )
		{
				switch( t_iCounter )
				{
						case 0: //minute
								/*两者都不成立->false*/
								if(
										( 0 == strlen(t_cronTemp[t_iCounter]) ) ||
										( 0 == strcmp( t_cronTemp[t_iCounter], "*" ) )
									)
								{
										return false;
								}
								break;
						case 1: //hour
						case 2: //mDay
						case 3: //month
						case 4: //weekDay
								break;
						default:
								break;
				}
		}
		/*移除字符串中的空格*/
		/*加载配置*/
		for( t_iCounter=0; t_iCounter < CRON_NUM; t_iCounter++ )
		{
				if( 0 == strcmp( t_cronTemp[t_iCounter], "*") )
				{
						switch( t_iCounter )
						{
								case 0://Minute
										m_FlagMinute = false;
										break;
								case 1://Hour
										m_FlagHour = false;
										break;
								case 2://m_Day
										m_FlagMonthDay = false;
										break;
								case 3://Month
										m_FlagMonth = false;
										break;
								case 4://m_weekDay
										m_FlagWeekDay = false;
										break;
								default:
										break;
						}
				}
				else
				{
						char t_atoiTemp[LEN_CONFIG_STRING+1];
						t_pchLeft = t_cronTemp[t_iCounter];
						t_pchRight = t_cronTemp[t_iCounter];

						bool t_flagLoop = true;

						while( t_flagLoop )
						{

								memset( t_atoiTemp, 0, sizeof(t_atoiTemp) );
								if( NULL != ( t_pchRight = strchr( t_pchRight, ',' ) ) )
								{
										memcpy( t_atoiTemp, t_pchLeft, (t_pchRight-t_pchLeft) );
										t_pchLeft = ++t_pchRight;
								}
								else
								{
										strcpy( t_atoiTemp, t_pchLeft );
										t_flagLoop = false;
								}


								/*检测时间点配置合法性：是否为数字字符或存在空洞*/
								for( int i=0; i<=strlen(t_atoiTemp); i++ )
								{
										if( '0' <= t_atoiTemp[i] <= '9' )
										{
										}
										else
										{
												return false;
										}
								}

								switch( t_iCounter )
								{
										case 0:
												/*检测配置时间点合法性*/
												if( 0 <= atoi(t_atoiTemp) <= 59 )
												{
														m_Minute[atoi(t_atoiTemp)] = 1;
												}
												else
												{
														return false;
												}
												break;
										case 1:
												if( 0 <= atoi(t_atoiTemp) <= 23 )
												{
														m_Hour[atoi(t_atoiTemp)] = 1;
												}
												else
												{
														return false;
												}
												break;
										case 2:
												if( 1 <= atoi(t_atoiTemp) <= 31 )
												{
														m_MonthDay[atoi(t_atoiTemp)] = 1;
												}
												else
												{
														return false;
												}
												break;
										case 3:  //1-12 ->- 0-11
												if( 1 <= atoi(t_atoiTemp) <= 12 )
												{
														m_Month[atoi(t_atoiTemp)-1] = 1;
												}
												else
												{
														return false;
												}
												break;
										case 4:
												if( 0 <= atoi(t_atoiTemp) <= 6 )
												{
														m_WeekDay[atoi(t_atoiTemp)] = 1;
												}
												else
												{
														return false;
												}
												break;
										default:
												break;
								}
						}

				}


		}

		EnableTimer();
		return true;
}