//
// Created by james on 2019-02-26.
//

#include <gtest.h>
#include <Poco/Net/IPAddress.h>

using Poco::Net::IPAddress;


class Base {
public:
	virtual void dummy() {}
};
class Derived : public Base {};

TEST(ip, t) {
	int a = 10;
	int *b = reinterpret_cast<int *>(a);
	int e = 11;
	int *f = &e;

//	std::cout << b << std::endl;

//	int c = 10;
//	int * d = const_cast<int*>(c);
//	const int c = 10;
//	int g = c;
//	int d = const_cast<int&>(c);
//	d = 11;
//	std::cout << d << std::endl;
//	std::cout << c << std::endl;

	const int *c = new int(10);
	int *d = const_cast<int *>(c);
	*d = 11;
	std::cout << *d << std::endl;
	std::cout << *c << std::endl;



	Base* b1 = new Derived();
	Base* b2 = new Base();

	Derived* d1 = dynamic_cast<Derived *>(b1);          // succeeds
//	Derived* d2 = dynamic_cast<Derived *>(b2);          // fails: returns 'NULL'
//*c = 11;
}

//reinterpret_cast是把括号里面的值取出来,转换成尖括号里面的值
//dynamic_cast 加了检查 比static_cast
