//
// Created by james on 2019-10-23.
//
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

int main()
{
	int b = 0;
	int a = 10/b;
	try{
		cout << "hello" << a << endl;
	}
	catch(...) {
		cout << "exception" << endl;
	}

}
