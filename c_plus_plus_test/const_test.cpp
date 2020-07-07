//
// Created by james on 2020-06-21.
//
#include <vector>
#include <iostream>

int main()
{
	/*
	int const *p = new int(10);
	*p = 11;
	p = new int(11);

	int *const z = new int(22);
	z = new int(223);

 // 如果出现在*号右边就是指指针自身是常量
 // 如果出现在*号右边就指指针是常量
 */

	std::vector<int> vec{1,2,3,3,4 };

	for(auto iter : vec)
	{
		std::cout << iter << std::endl;
	}

	/*
	const std::vector<int>::iterator iter = vec.begin();
	*iter = 10;
	++iter;
	std::vector<int>::const_iterator cIter = vec.begin();
	*cIter = 11;
	++cIter;
	 const_iter可以遍历vec，不容许改变元素的值

	 */
}

