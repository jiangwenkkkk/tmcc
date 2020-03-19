//
// Created by james on 2019-12-09.
//

//
// ChannelTest.cpp
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Poco/SplitterChannel.h"
#include "Poco/AsyncChannel.h"
#include "Poco/AutoPtr.h"
#include "Poco/Message.h"
#include "Poco/Formatter.h"
#include "Poco/FormattingChannel.h"
#include "Poco/ConsoleChannel.h"
#include "Poco/StreamChannel.h"
#include "TestChannel.h"
#include <sstream>


using Poco::SplitterChannel;
using Poco::AsyncChannel;
using Poco::FormattingChannel;
using Poco::ConsoleChannel;
using Poco::StreamChannel;
using Poco::Formatter;
using Poco::Message;
using Poco::AutoPtr;

#include <gtest.h>


class SimpleFormatter: public Formatter
{
public:
	void format(const Message& msg, std::string& text)
	{
		text = msg.getSource();
		text.append(": ");
		text.append(msg.getText());
	}
};



TEST(channel,testSplitter)
{
	AutoPtr<TestChannel> pChannel = new TestChannel;
	AutoPtr<SplitterChannel> pSplitter = new SplitterChannel;
	pSplitter->addChannel(pChannel.get());
	pSplitter->addChannel(pChannel.get());
	Message msg;
	pSplitter->log(msg);
	assert (pChannel->list().size() == 2);
}


//
//TEST(channel,testAsync){
//	AutoPtr<TestChannel> pChannel = new TestChannel;
//	AutoPtr<AsyncChannel> pAsync = new AsyncChannel(pChannel.get());
//	pAsync->open();
//	Message msg;
//	pAsync->log(msg);
//	pAsync->log(msg);
//	pAsync->close();
//	assert (pChannel->list().size() == 2);
//}
//
//
//TEST(channel,testFormatting)
//{
//	AutoPtr<TestChannel> pChannel = new TestChannel;
//	AutoPtr<Formatter> pFormatter = new SimpleFormatter;
//	AutoPtr<FormattingChannel> pFormatterChannel = new FormattingChannel(pFormatter, pChannel.get());
//	Message msg("Source", "Text", Message::PRIO_INFORMATION);
//	pFormatterChannel->log(msg);
//	assert (pChannel->list().size() == 1);
//	assert (pChannel->list().begin()->getText() == "Source: Text");
//}
//
//
//TEST(channel,testConsole)
//{
//	AutoPtr<ConsoleChannel> pChannel = new ConsoleChannel;
//	AutoPtr<Formatter> pFormatter = new SimpleFormatter;
//	AutoPtr<FormattingChannel> pFormatterChannel = new FormattingChannel(pFormatter, pChannel.get());
//	Message msg("Source", "Text", Message::PRIO_INFORMATION);
//	pFormatterChannel->log(msg);
//}
//
//
//TEST(channel,testStream)
//{
//	std::ostringstream str;
//	AutoPtr<StreamChannel> pChannel = new StreamChannel(str);
//	AutoPtr<Formatter> pFormatter = new SimpleFormatter;
//	AutoPtr<FormattingChannel> pFormatterChannel = new FormattingChannel(pFormatter, pChannel.get());
//	Message msg("Source", "Text", Message::PRIO_INFORMATION);
//	pFormatterChannel->log(msg);
//	assert (str.str().find("Source: Text") == 0);
//}
//
