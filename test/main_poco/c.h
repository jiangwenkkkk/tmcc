//
// Created by james on 2019-10-23.
//

#ifndef TESTPOCO_C_H
#define TESTPOCO_C_H

class DefineTest{
public:
	void PrintFunction()
	{
#ifdef DCCDEBUG
		std::cout << __FUNCTION__ << std::endl;
#else
		std::cout << "no" << __FUNCTION__ << std::endl;
#endif
	}
};
#endif //TESTPOCO_C_H
