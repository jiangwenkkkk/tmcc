//
// Created by james on 2019-11-14.
//

#include <iostream>
#include <streambuf>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <memory>
#include <thread>
using namespace std;
stringbuf buf;
istream in(&buf);
ostream out(&buf);
bool flag = false;
void threadb() {
	char data[200]={0};
	while (true) {
		if (flag) {
			in >> data;
			cout << "thread B recv:" << data << endl;
			flag = false;
		}
	}
}
int main() {
	thread consumer(threadb);
	char data[200]={0};
	while (true) {
		cin >> data;
		out << data;
		flag = true;
	}
	return 0;
}