#include <iostream>

//
// Created by james on 2020-06-20.
//
class Name {
public:
	Name(int a):_a(a){}
	int get_a(){
		return _a;
	}
//private:
	~Name(){

}
int _a= 10;
};
int main()
{
	Name a(1);
	std::cout << a.get_a() << std::endl;
}

/*
 * c++是静态绑定语言，编译器管理栈上对象的生命周期，编译器在为类对象分配栈空间时，会先检查类的析构函数的访问性。若析构函数不可访问，则不能在栈上创建对象。
 * 通过将析构函数设为私有函数，将导致不能在栈上分配
 */