//
// Created by james on 2019-04-18.
//

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

	SharedMemory mem("MySharedMemory", 1024, SharedMemory::AM_WRITE, 0, false);

	string serializedStr;
	int i = 0;
	char* ptr;
	for (ptr = mem.begin(); *ptr != '\0'; ++ptr)
	{
		serializedStr += *ptr;
	}

	serializedStr += *ptr;


	tutorial::Student deserializedStudent;
	if(!deserializedStudent.ParseFromString(serializedStr)){
		cerr << "Failed to parse student." << endl;
		return -1;
	}

	cout << "----------------反序列化--------------------" << endl;
	cout << "deserializedStudent debugString: " << deserializedStudent.DebugString();
	cout << "Name: " << deserializedStudent.name() << endl;
	cout << "student id " << deserializedStudent.id() << endl;

	if (deserializedStudent.has_email())
	{
		cout << "E-mail address: " << deserializedStudent.email() << endl;
	}

	for (int j = 0; j < deserializedStudent.phone_size(); ++j) {
		const tutorial::Student::PhoneNumber &phoneNumber2 = deserializedStudent.phone(j);

		switch (phoneNumber2.type())
		{
			case tutorial::Student::MOBILE:
				cout << "Mobile phone #: ";
				break;
			case tutorial::Student::HOME:
				cout << "Home phone #: ";
				break;
		}
		cout << phoneNumber2.number() << endl;
	}

	google::protobuf::ShutdownProtobufLibrary();
}
