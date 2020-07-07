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

class a{
public:
	int change()const {
//		a = 10;
	}
	int changea(){
		a = 101;
	}
private:
	int a;
};

TEST(const_a, t)
{

}

