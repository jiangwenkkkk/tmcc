//
// Created by james on 2019-11-01.
//

#include <iostream>
#include <string>
#include "Poco/SharedPtr.h"
#include "void_to_obj.h"

void void_to_obj::printInfo(Poco::SharedPtr<void_to_obj::Person> a) {
//	Poco::SharedPtr<Student> b
//	Student* c = reinterpret_cast<Poco::SharedPtr<Student>>(a);
//	Student* c = reinterpret_cast<Student*>(a);
//	Poco::SharedPtr<Student> c = reinterpret_cast<Student*>(a);
//	Poco::SharedPtr<Student>* c = static_cast<Poco::SharedPtr<Student>*>(a);
//	c.print();
	Poco::SharedPtr<void_to_obj::Student> b = a.cast<void_to_obj::Student>();
	if(b.get() != NULL)
		b->print();
	else
		std::cout << "no we can't " << std::endl;

	if(a.cast<void_to_obj::Student>().get()!= nullptr)
		b->print();
	else
		std::cout << "no again" << std::endl;
}
//void void_to_obj::printInfo(Poco::SharedPtr<void> a) {
////	Poco::SharedPtr<Student> b
////	Student* c = reinterpret_cast<Poco::SharedPtr<Student>>(a);
////	Student* c = reinterpret_cast<Student*>(a);
////	Poco::SharedPtr<Student> c = reinterpret_cast<Student*>(a);
////	Poco::SharedPtr<Student>* c = static_cast<Poco::SharedPtr<Student>*>(a);
////	c.print();
//	Poco::SharedPtr<void_to_obj::Student> b = a.cast<void_to_obj::Student>();
//	b->print();
//}
//using namespace void_to_obj;

	int main()
	{
//		Poco::SharedPtr<void_to_obj::Person> a = new void_to_obj::Student("tom");
		Poco::SharedPtr<void_to_obj::Person> a = new void_to_obj::Student("tom");

		a->print();
		void_to_obj::printInfo(a);
	}

