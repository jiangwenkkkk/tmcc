//
// Created by james on 2020-06-21.
//

#include <string>
#include <iostream>

using namespace std;

class C {
public:
	int b = 10;
};
class A {};
class B {};

void Printer (int* val,string seperator = "\n")
{
	cout << val<< seperator;
}

int main()
{
	const C *a = new C;
	const C ba =  C();
//	a->b = 10;

//	C *b = const_cast<C *>(a);
//	C *b = a;
	C b = ba;
/*
 * 不能把const对象赋值给变量
 */

//	A * a = new A;
//	B * b = reinterpret_cast<B *>(a);

	const std::string ab = "hello";
	std::string ac = ab;


	int variable = 21;
	const int* const_p = &variable;
	int* modifier = const_cast<int*>(const_p);

	*modifier = 7;
	cout << "variable:" << variable << endl;


	const int consatant = 20;
	//Printer(consatant);//Error: invalid conversion from 'int' to 'int*'
	Printer(const_cast<int *>(&consatant));

}


/*
 * const int * 是指向常量的指针，赋值给int*的时候，就会有冲突，编译器报错。
 *
 * const int* 指向的对象不是不可修改，但是在某一处，突然想修改，这时就可以去除const的属性，然后修改。
 *
 */

/*
 * reinterpret_cast, 对待所有的指针的类型转换
 * static_cast       除了操作类型指针，也能用于执行类型定义的显式的转换，以及基础类型之间的标准转换
 * dynamic_cast 	 只用于对象的指针和引用。不过，与static_cast不同，在后一种情况里（注：即隐式转换的相反过程），dynamic_cast会检查操作是否有效。也就是说，它会检查转换是否会返回一个被请求的有效的完整对象。 检测在运行时进行。如果被转换的指针不是一个被请求的有效完整的对象指针，返回值为NULL.
 * const_cast        这个转换类型操纵传递对象的const属性，或者是设置或者是移除：
 */