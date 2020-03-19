//
// Created by james on 2019-10-23.
//

#include "b.h"
#include <iostream>
#include "c.h"
int main()
{
#ifdef DCCDEBUG
	std::cout << "hello" << std::endl;
#else
	std::cout << "no" << std::endl;
#endif

	DefineTest a;
	a.PrintFunction();
	return 2;
}

//如果定义了宏,都能找到这个宏,因为宏是预处理的,所以会首先找到这个宏的定义,如果找到了就是正确的.