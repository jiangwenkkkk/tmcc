//
// Created by james on 2018-12-31.
//

#include <gtest/gtest.h>
#include "Poco/SplitterChannel.h"
#include "Poco/AsyncChannel.h"
#include "Poco/Message.h"
#include "Poco/Formatter.h"
#include "Poco/FormattingChannel.h"
#include "Poco/ConsoleChannel.h"
#include "Poco/StreamChannel.h"
#include "TestChannel.h"


using Poco::SplitterChannel;
using Poco::AsyncChannel;
using Poco::FormattingChannel;
using Poco::ConsoleChannel;
using Poco::StreamChannel;
using Poco::Formatter;
using Poco::Message;
using Poco::AutoPtr;


class SimpleFormatter : public Formatter {
public:
	void format(const Message &msg, std::string &text) {
		text = msg.getSource();
		text.append(": ");
		text.append(msg.getText());
	}
};


TEST(ChannelTest, testSplitter) {
	AutoPtr<TestChannel> pChannel = new TestChannel;
	AutoPtr<SplitterChannel> pSplitter = new SplitterChannel;
	pSplitter->addChannel(pChannel.get());
	pSplitter->addChannel(pChannel.get());
	Message msg;
	pSplitter->log(msg);
	assert (pChannel->list().size() == 2);
}

TEST(channel, testFormatting) {
	AutoPtr<TestChannel> pChannel = new TestChannel;
	AutoPtr<Formatter> pFormatter = new SimpleFormatter;
	AutoPtr<FormattingChannel> pFormatterChannel = new FormattingChannel(pFormatter, pChannel.get());
	Message msg("Source", "Text", Message::PRIO_INFORMATION);
	pFormatterChannel->log(msg);
	assert (pChannel->list().size() == 1);
	assert (pChannel->list().begin()->getText() == "Source: Text");
}

TEST(ChannelTest, testConsole) {
	AutoPtr<ConsoleChannel> pChannel = new ConsoleChannel;
	AutoPtr<Formatter> pFormatter = new SimpleFormatter;
	AutoPtr<FormattingChannel> pFormatterChannel = new FormattingChannel(pFormatter, pChannel.get());
	Message msg("Source", "Text", Message::PRIO_INFORMATION);
	for (int i = 0; i < 100; ++i) {
		pFormatterChannel->log(msg);
		std::cout << "hello";
	}
}
