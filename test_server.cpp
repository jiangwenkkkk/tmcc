//
// Created by james on 2018/8/4.
//

#include <iostream>
#include "Poco/Util/ServerApplication.h"

using Poco::Util::Application;
using Poco::Util::ServerApplication;

class MyServerApplication : public ServerApplication
{
public:

};

int main(int argc, char** argv)
{
	MyServerApplication app;
	return app.run(argc, argv);
}