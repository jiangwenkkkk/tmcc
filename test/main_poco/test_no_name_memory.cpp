//
// Created by james on 2019-04-17.
//

#include <iostream>
#include "Poco/SharedMemory.h"

using Poco::SharedMemory;

int main(int argc, char** argv)
{
	SharedMemory mem("MySharedMemory", 1024, SharedMemory::AM_WRITE);
	for (char* ptr = mem.begin(); ptr != mem.end(); ++ptr)
	{
		*ptr = 'a';
		std::cout << *ptr << std::endl;

	}
	return 0;
}
