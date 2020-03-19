//
// Created by james on 2019-04-18.
//

#include <iostream>
#include <string>
#include "student.pb.h"

using namespace std;

int main()
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
	cout << "serialization result: " << serializedStr << endl;
	cout << endl << "debugString: " << student.DebugString();

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