//
// Created by james on 2019-11-01.
//

#ifndef TESTPOCO_VOID_TO_OBJ_H
#define TESTPOCO_VOID_TO_OBJ_H


namespace void_to_obj {
	class Person {
	public:
		Person(std::string name) : _name(name) {}

		virtual void print()=0;
		virtual ~Person(){}
	protected:
		std::string _name;
	};

	class Student : public Person {
	public:
		Student(std::string name) : Person(name) {}

		virtual void print() {
			std::cout << "name is: " << _name << std::endl;
			std::cout << "greade is: " << _greade << std::endl;
		}
		int _greade=100;
		~Student(){}
	};

	class Teacher : public Person {
	public:
		int _money=1000;
		Teacher(std::string name) : Person(name) {}

		void print() {
			std::cout << "my name is " << _name << "; today I was your teacher!" << std::endl;
			std::cout << "my money is " << _money << "; today I was your teacher!" << std::endl;
		}
		~Teacher(){}
	};


	void printInfo(Poco::SharedPtr<Person> a);
//	void printInfo(Poco::SharedPtr<void> a);


}
#endif //TESTPOCO_VOID_TO_OBJ_H
