//
// Created by james on 2020-07-03.
//

#include <gtest.h>
#include <cmath>

TEST(count_math, t)
{
	double Probability_sum = 0;
	for (int i = 1; i < INT_MAX; ++i) {
		auto tmp = 1/(2*static_cast<double >(i));
		Probability_sum += tmp;
	}
	std::cout << Probability_sum << std::endl;
}

TEST(count_math_ci, t)
{
	double Probability_sum = 0;
	for (int i = 1; i < INT_MAX; ++i) {
		auto power = std::pow(2, i);
		auto tmp = 1/power;
		Probability_sum += tmp;
	}
	std::cout << Probability_sum << std::endl;
}

/*
 * 1.统计程序执行时间
请实现`CalcFunc`, 让其等待1us的概率为1/2， 等待2us的概率为1/4，...,等待n us的概率为1/(2 * n). 将`calc.cpp`编译成静态库`calc.a`
 通过编写函数测试
 1. 如果没次的通过的时候，所有的情况是并行的，那么就有加起来的和要大与1,结果是11.0324.如果是这样的,那么最终的结果是不正确的.
 所以,所有的概率不是一定出现的,而是每次跑的话,而是
 */