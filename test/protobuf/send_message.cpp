//
// Created by james on 2019-04-18.
//

#include <iostream>
#include <string>
#include "Poco/SharedMemory.h"
#include "student.pb.h"
#include <Poco/Thread.h>

using Poco::SharedMemory;
using namespace::std;

int main(int argc, char** argv)
{

	GOOGLE_PROTOBUF_VERIFY_VERSION;


	tutorial::Student student;

	student.set_id(201421031059);
	*student.mutable_name() = "dablelv";
	student.set_email("dablely@tencent.com");

	tutorial::Student::PhoneNumber* phoneNumber = student.add_phone();
	phoneNumber->set_number("15800948193");
	phoneNumber->set_type(tutorial::Student::MOBILE);


	tutorial::Student::PhoneNumber* phoneNumber1 = student.add_phone();
	phoneNumber1->set_number("0564-4762652");
	phoneNumber1->set_type(tutorial::Student::HOME);

	string serializedStr;
	student.SerializeToString(&serializedStr);

	SharedMemory mem("MySharedMemory", 1024, SharedMemory::AM_WRITE);

	int i = 0;
	for (char* ptr = mem.begin(); ptr != mem.end(); ++ptr)
	{
		*ptr = serializedStr[i++];
	}

	Poco::Thread::sleep(10000000);



	google::protobuf::ShutdownProtobufLibrary();

}
