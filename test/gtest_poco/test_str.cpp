//
// Created by james on 2019-01-20.
//

#include <gtest/gtest.h>
#include <string>
#include <stdio.h>

TEST(str, a) {
	std::string a = "hello";
	std::cout << a;
}

TEST(chang_num, a) {
	int num = 2736;
	//if (num == 0) return num;

	std::vector<int> ve_num;
	int num_a = num;
	while (num_a) {
		ve_num.push_back(num_a % 10);
		num_a = num_a / 10;
	}

	auto ve_sort = ve_num;
	std::sort(ve_sort.begin(), ve_sort.end());
	for (auto iter = --ve_num.end(), iter_sort = --ve_sort.end(); iter < ve_num.end(); --iter, --iter_sort) {
		if (*iter < *iter_sort) {
			auto max = std::find(ve_num.begin(), iter, *iter_sort);
			std::swap(*max, *iter);
			break;
		}
	}

	int it = 1;
	for (auto i : ve_num) {
		num_a = i * it + num_a;
		it = 10 * it;
	}
	std::cout << num_a;
}


TEST(max, a) {
	std::vector<int> nums = {-2, 2, -3, 4, -1, 2, 1, -5, 3};
	int sum = 0, minSum = 0, maxSum = -1;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		maxSum = std::max(maxSum, sum - minSum);
		minSum = std::min(minSum, sum);
	}
	std::cout << maxSum;

}

TEST(cout_ascii, t)
{
	char b = 'a';
	int a = int('a');
	std::cout << a;
}

TEST(str_t, split_str)
{
	std::string str = "20191130230350";
	std::cout << str.substr(1,2);
	std::cout << str.substr(4,2) << std::endl;
	int b = std::stoi(str.substr(4,2));
	std::cout << b << std::endl;
}