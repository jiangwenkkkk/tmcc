//
// Created by james on 2019-11-22.
//

#include "LoggerSystem.h"


#include "Poco/Logger.h"
#include "Poco/LogStream.h"
#include "Poco/AutoPtr.h"

#include "Poco/Logger.h"
#include "Poco/PatternFormatter.h"
#include "Poco/FormattingChannel.h"
#include "Poco/ConsoleChannel.h"
#include "Poco/FileChannel.h"
#include "Poco/Message.h"


using Poco::Logger;
using Poco::PatternFormatter;
using Poco::FormattingChannel;
using Poco::ConsoleChannel;
using Poco::ColorConsoleChannel;
using Poco::FileChannel;
using Poco::Message;

using Poco::Logger;
using Poco::LogStream;
using Poco::Channel;
using Poco::Message;
using Poco::AutoPtr;

/*
int main()
{
	std::cout << "..." << std::endl;

	AutoPtr<ColorConsoleChannel> pChannel = new ColorConsoleChannel;
	Logger& root = Logger::root();
	root.setChannel(pChannel.get());

//	LogStream ls(root,Poco::Message::Priority::PRIO_ERROR);
//
//	ls << "information" << ' ' << 1 << std::endl;

//	Poco::LogStream(root, Poco::Message::Priority::PRIO_ERROR) << "[" << Poco::Path(__FILE__).getFileName() << ":" << __LINE__ << "::" << __func__ << "] " ;
	Poco::LogStream ls(root, Poco::Message::Priority::PRIO_ERROR) ;
//	ls<< "[" << Poco::Path(__FILE__).getFileName() << ":" << __LINE__ << "::" << __func__ << "] " ;
	ls << "a" << std::endl;
//	ELOG << "hello" << "hello" ;
//	ILOG << "hello" << "hello" ;
}
*/