//
// Created by james on 2019-11-22.
//

#ifndef TESTPOCO_GTESTEX_H
#define TESTPOCO_GTESTEX_H

#include <gtest/gtest.h>
#include <vector>
#include "LoggerSystem.h"

class LogTest:public ::testing::Test{
protected:
	virtual void SetUp(){
logger::LoggerSystem::init();
	}

	virtual void TearDown()
	{
logger::LoggerSystem::closeLogger();
	}

};

#endif //TESTPOCO_GTESTEX_H
