//
// Created by james on 2019-04-17.
//

#include <Poco/SharedMemory.h>
#include <Poco/File.h>
#include <iostream>

using Poco::SharedMemory;
using Poco::File;

int main() {
	File f("/Users/james/jameswork/james_clion/testpoco/test/main_poco/MapIntoMemory.dat");
	SharedMemory mem(f, SharedMemory::AM_WRITE); // read-only access
	for (char *ptr = mem.begin(); ptr != mem.end(); ++ptr) {
		std::cout << *ptr << std::endl;// ...
		*ptr = 'a';
	}
	return 0;
}