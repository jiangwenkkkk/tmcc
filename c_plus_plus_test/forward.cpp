////
//// Created by james on 2020-06-20.
////
#include <iostream>
#include <memory>
#include <utility>

struct A {
	A(int&& n) { std::cout << "rvalue overload, n=" << n << "\n"; }
	A(int& n)  { std::cout << "lvalue overload, n=" << n << "\n"; }
};

class B {
public:
	template<class T1, class T2, class T3>
	B(T1&& t1, T2&& t2, T3&& t3) :
			a1_{std::forward<T1>(t1)},
			a2_{std::forward<T2>(t2)},
			a3_{std::forward<T3>(t3)}
	{
	}

private:
	A a1_, a2_, a3_;
};

//template<class T, class U>
//std::unique_ptr<T> make_unique1(U&& u)
//{
//	return std::unique_ptr<T>(new T(std::forward<U>(u)));
//}

template<class T, class U>
std::unique_ptr<T> make_unique1(U&& u)
{
	return std::unique_ptr<T>(new T(u));
}

template<class T, class... U>
std::unique_ptr<T> make_unique2(U&&... u)
{
	return std::unique_ptr<T>(new T(std::forward<U>(u)...));
}



template <typename T>
void func(T&& arg)
{
}

int main()
{
	int&&　ref_int = 10;
	func(ref_int);
	auto p1 = make_unique1<A>(2); // rvalue
	int i = 1;
	auto p2 = make_unique1<A>(i); // lvalue

	std::cout << "B\n";
	auto t = make_unique2<B>(2, i, 3);
}
/*
 *
 * 不用forward
lvalue overload, n=2
lvalue overload, n=1
B
rvalue overload, n=2
lvalue overload, n=1
rvalue overload, n=3

rvalue overload, n=2
lvalue overload, n=1
B
rvalue overload, n=2
lvalue overload, n=1
rvalue overload, n=3
由此可以发现ref_int被认为是左值，
 */
//
//#include <iostream>
//
//
//struct A {
//	int value;
//	explicit A(int value) : value(value) {
//		std::cout << "construct" << std::endl;
//	}
//	~A() {
//		std::cout << "deconstruct" << std::endl;
//	}
//};
//
//void test(A&& a, double b) {
//	std::cout << a.value << " " << b << std::endl;
//	a.value = 10;
//}
//
//template <class... Args>
//void test_forward(Args&... args) {
//	test(std::forward<Args>(args)...);
//}
//
//int main() {
//	A a(1);
//	float b = 2.1;
//	test_forward(a, b);
////	test_forward(a, b);
//	a.value = 2;
//	test_forward(a, b);
////	test_forward(a, b);
//	std::cout << a.value << std::endl;
//
//	A ab(1);
//	float bb = 2.1;
////	test(ab, bb);
//	test(std::move(ab), bb);
//	++ab.value;
//	test(static_cast<A&&>(ab), bb);
//	std::cout << ab.value << std::endl;
//	return 0;
//	return 0;
//}