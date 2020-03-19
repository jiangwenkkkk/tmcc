//
// Created by james on 2018/7/7.
//

#include <iostream>

template<class C>
class option {
public:
	using fp = void (C::*)(int);
	option(C* obj, fp method):_obj(obj), _method(method){}
	virtual void invoke(int a)
	{
		(_obj->*_method)(a);
	}
private:
	option();
	C* _obj;
	fp _method;
};



class tmcc{
public:
	void hello(int val){
		std::cout << val << std::endl;
	}
	static void work(int a)
	{
		std::cout << a << std::endl;
	}
};

int main()
{
	void (tmcc::*f)(int );
	f=&tmcc::hello;
	tmcc a;
	(a.*f)(10);

	void (*ps)(int)=&tmcc::work;
	(*ps)(11);

	tmcc c;
	option<tmcc> tmop(&c, &tmcc::hello);
	tmop.invoke(11);

}