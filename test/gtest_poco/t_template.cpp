//
// Created by james on 2019-02-23.
//

#include <gtest.h>
#include <deque>
#include "t_stack.h"

using namespace tmc;
template<class T1, class T2>
class Shower {
public:
	void say() {
		std::cout << _id << " " << _name << std::endl;
	}

	Shower(T1 id, T2 name) : _id(id), _name(name) {}

private:
	T1 _id = 10;
	T2 _name;
};

//template <>
//class Shower<int, std::string>
//{
//};
//
//
//TEST(tmp, t)
//{
//	Shower<int, std::string> b(11, "he");
//	b.say();
//
//}

template<class T>
inline void show_value(T t) {
	std::cout << t << std::endl;
}

inline char const *max(char const *a, char const *b) {
	return std::strcmp(a, b) > 0 ? a : b;
}

template <class T>
inline T const* max(T const* a, T const* b, T const* c) {
	return ::max(::max(a, b), c);
}

template<class T>
inline T const &max(T const &a, T const &b) {
	return a > b ? a : b;
}

template<class T>
inline T const &max(T const &a, T const &b, T const &c) {
	return ::max(::max(a, b), c);
}

template<class T>
inline T maxa(T a, T b) {
	return a > b ? a : b;
}




TEST(show_value, t) {
	show_value(100);
	show_value(100.1);
}
TEST(char_const, t)
{
	const char *tm1 = "hello1";
	const char *tm2 = "hello2";
	const char *tm3 = "hello3";
	std::cout << ::max(tm1, tm2, tm3) << std::endl;
	std::cout << ::max("a", "b", "c") << std::endl;

}

TEST(max_T, t) {
	std::cout << max(10, 11) << std::endl;
	std::cout << max<double>(10.1, 11) << std::endl;
//	std::cout << max<double>(10.1, 11, 10) << std::endl;
	const char* c = ::max("hell", "no");
	std::cout << ::max("hell", "no") << std::endl;
//	std::cout << ::max("hell", "no", "ze") << std::endl;
	const char *tm1 = "hello1";
	const char *tm2 = "hello2";
	const char *tm3 = "hello3";

	//std::cout << ::max(tm1, tm2, tm3) << std::endl;
	std::cout << ::max(tm1, tm2) << std::endl;

	const std::string a = "he";
	const std::string b = "me";
	std::cout << ::max<std::string>(a, b) << std::endl;
//	std::cout << max("hello", "no", "ew") << std::endl;
}

//模板,设置里面的类型,可以直接完成转换
//字符串无法直接通过 > 比较

//template<class T>
//class Stack {
//private:
//	std::vector<T> elems;
//public:
//	void push(T const &element) {
//		elems.push_back(element);
//	}
//
//	void pop() {
//		if (elems.empty())
//			throw std::out_of_range("Stack<>::pop: empty stack");
//		elems.pop_back();
//	}
//
//	T top() const {
//		if (elems.empty())
//			throw std::out_of_range("Stack<>::top: empty stack");
//
//		return elems.back();
//	}
//
//	bool empty() const {
//		return elems.empty();
//	}
//};


//template<class T, class CONT>
//template<class T2>
//Stack<T, CONT> &Stack<T, CONT>::operator=(const Stack<T2> &) {
//	return *this;
//}


TEST(stack_oper, t)
{
//	Stack<int,std::vector> a;
//	a.push(10);
//	Stack<double,std::vector> b;
//	b = a;

}

TEST(stack_t, t)
{
	Stack<int> grade;
	grade.push(10);
	grade.push(20);
	grade.push(310);

	std::cout << grade.top() << std::endl;
	grade.pop();
	std::cout << grade.top() << std::endl;
	grade.pop();
	std::cout << grade.top() << std::endl;
	grade.pop();
	grade.pop();
}

TEST(stack_diff_container, t)
{
	Stack<int, std::deque> grade;
	grade.push(10);
	grade.push(20);
	grade.push(310);

	std::cout << grade.top() << std::endl;
	grade.pop();
	std::cout << grade.top() << std::endl;
	grade.pop();
	std::cout << grade.top() << std::endl;
	grade.pop();
	grade.pop();
}

TEST(const_t, t)
{
	const int& a = 10;
	int b = 11;
	const int &c = b;
	std::cout << a << std::endl;
}

TEST(char_strcmp, t)
{
	std::cout << strcmp("hello1", "hello2") << std::endl;
	std::cout << strcmp("b", "a") << std::endl;
	std::cout << strcmp("b", "b") << std::endl;
	int a = 10 > 11? 1:0;
	std::cout << a << std::endl;

	int b = strcmp("hello1", "hello2") > 11? 1:0;
	std::cout << b << std::endl;
	b = std::strcmp("hello1", "hello2") > 11? 1:0;
	std::cout << b << std::endl;
}

template <class T>
void printcoll(T const& coll)
{
//	using pos = T::const_iterator;
	typename T::const_iterator pos;
	typename  T::const_iterator end(coll.end());

	for(pos = coll.begin(); pos != end; ++pos)
	{
		std::cout << *pos << " ";
	}

	std::cout << std::endl;
}

TEST(pr_t, t)
{
	std::vector<int> va={0,2,1,3,4,5};

	printcoll(va);
}

template <int N>
void printBitset(std::bitset<N> const& bs)
{
	std::cout << bs.template to_string<char,std::char_traits<char>, std::allocator<char> >('a','b');
//	to_string<char, char_traits<char>, allocator<char> >(__zero, __one);

}

TEST(pb,t)
{
	std::bitset<32> a;
	a.set(6);
//	std::cout << a.to_string('0','1') << std::endl;
	printBitset<32>(a);
}

TEST(vec_push_front,t)
{
	std::vector<int> a;
	a.push_back(1111);
}
//

TEST(base_t, t)
{
	Derived<int> a;
	a.foo();
}

