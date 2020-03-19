//
// Created by james on 2019-06-06.
//

#include <iostream>
#include <vector>

void add(std::vector<int> &a )
{
	for (auto item = a.begin(); item != a.end(); ++item) {
		std::cout << *item << std::endl;
	}
//	auto print = [](int& b){std::cout << b << std::endl;};
//	for_each(a.begin(), a.end(), print);

}
int main()
{
	std::vector<int> a= {10, 11, 23, 334};
	add(a);

}