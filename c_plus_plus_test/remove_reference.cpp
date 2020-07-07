//
// Created by james on 2020-06-22.
//

#include <iostream> // std::cout
#include <type_traits> // std::is_same

template<class T1, class T2>
void print_is_same() {
	std::cout << std::is_same<T1, T2>() << '\n';
}

int main() {
	std::cout << std::boolalpha;

	print_is_same<int, int>();
	print_is_same<int, int &>();
	print_is_same<int, int &&>();

	print_is_same<int, std::remove_reference<int>::type>();
	print_is_same<int, std::remove_reference<int &>::type>();
	print_is_same<int, std::remove_reference<int &&>::type>();
}

/*template <class _Tp> struct _LIBCPP_TEMPLATE_VIS remove_reference        {typedef _Tp type;};
 *使用可以去掉对象的的引用属性，利用返回结构体取得type类型
 *
 */