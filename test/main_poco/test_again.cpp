//
// Created by james on 2019-04-17.
//

#include <iostream>
#include "Poco/SharedMemory.h"

using Poco::SharedMemory;

int main(int argc, char** argv)
{
	SharedMemory mem("hia", 4096, SharedMemory::AM_WRITE, 0, false);
	for (char* ptr = mem.begin(); ptr != mem.end(); ++ptr)
	{
		std::cout << *ptr << std::endl;
	}
	return 0;
}

