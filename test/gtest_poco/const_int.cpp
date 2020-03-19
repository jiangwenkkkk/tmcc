//
// Created by james on 2019-02-23.
//

#include <gtest.h>

TEST(const_int, t)
{
	int a = 1;
	int* b = &a;
	int* const c = &a;
	int d = 1;
	int const* e = &a;
	e = &d;
//	*e = 10;
	//c = &d;

}