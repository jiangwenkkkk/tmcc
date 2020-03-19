//
// Created by james on 2018/8/6.
//

#include <iostream>
#include <zconf.h>

using namespace std;

int main() {
	int a = 10;
	int b = 11;
	if (pid_t p = fork()) {
		a++;
		b++;
		cout << "child " << "a" << a << endl << "b" << b << endl;
		exit(0);
	} else {
		a--;
		b--;
		cout << "father " << "a" << a << endl << "b" << b << endl;
	}

}