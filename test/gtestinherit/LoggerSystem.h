//
// Created by james on 2019-11-20.
//

#ifndef TESTPOCO_LOGGERSYSTEM_H
#define TESTPOCO_LOGGERSYSTEM_H


#include <string>
#include <iostream>

#include "Poco/Format.h"
#include "Poco/FormattingChannel.h"
#include "Poco/PatternFormatter.h"
#include "Poco/Channel.h"
#include "Poco/AsyncChannel.h"
#include "Poco/ConsoleChannel.h"
#include "Poco/FileChannel.h"
#include "Poco/LogStream.h"
#include "Poco/Util/Application.h"
#include "Poco/Path.h"
#include "Poco/File.h"

namespace logger {
	class LoggerSystem {
	public:
		static void init() {
			Poco::Channel* pOutChnnel = nullptr;
			pOutChnnel = new Poco::ColorConsoleChannel;
			const auto &format =
												   "%Y%m%d %H:%M:%S.%c [%q] [%P] %t" ;
			auto pFormat = new Poco::PatternFormatter( format );
			pFormat->setProperty( "times", "local" );
			auto pFormatChannel = new Poco::FormattingChannel( pFormat, pOutChnnel );

			// 打开写日志线程
			auto pAsyncChannel = new Poco::AsyncChannel( pFormatChannel );
			pAsyncChannel->open();

			Poco::Logger::root().setChannel( pAsyncChannel );

			// 设置日志等级
			const auto& logLevel = "debug" ;
			Poco::Logger::root().setLevel( logLevel );
//			Poco::LogStream(Poco::Logger::root(), Poco::Message::PRIO_INFORMATION) << "[" << Poco::Path(__FILE__).getFileName() << ":" << __LINE__ << "::" << __func__ << "] " ;
		}

		static void closeLogger()
		{
			auto *pAsyncChannel = static_cast<Poco::AsyncChannel*>
			( Poco::Logger::root().getChannel() );
			pAsyncChannel->close();
			auto *pFormatChannel = pAsyncChannel->getChannel();
			if ( pFormatChannel ) {
				pFormatChannel->close();
			}
			Poco::Logger::root().close();
		}

	};


	namespace {
#define __LOG(level) \
    Poco::LogStream(Poco::Logger::root(), level) \
    << "[" << Poco::Path(__FILE__).getFileName() << ":" << __LINE__ << "::" << __func__ << "] "
	}

#define TLOG __LOG(Poco::Message::PRIO_TRACE)
#define DLOG __LOG(Poco::Message::PRIO_DEBUG)
#define ILOG __LOG(Poco::Message::PRIO_INFORMATION)
#define NLOG __LOG(Poco::Message::PRIO_NOTICE)
#define WLOG __LOG(Poco::Message::PRIO_WARNING)
#define ELOG __LOG(Poco::Message::PRIO_ERROR)
#define CLOG __LOG(Poco::Message::PRIO_CRITICAL)
#define FLOG __LOG(Poco::Message::PRIO_FATAL)

#define ENDL std::endl;
}


#endif //TESTPOCO_LOGGERSYSTEM_H
