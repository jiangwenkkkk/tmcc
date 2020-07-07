//
// Created by james on 2020-06-23.
//

#include <iostream>
using namespace std;

class HugeMem{
public:
	HugeMem(int size):sz(size >0? size : 1){
		c = new int[sz];
	}
	~HugeMem(){
		delete [] c;}
	HugeMem(HugeMem && hm): sz(hm.sz), c(hm.c){
		hm.c = nullptr;
	}
	int *c;
	int sz;
};

class Moveable{
public:
	Moveable():i(new int(3)), h(1024){}
	~Moveable(){ delete i; }
	Moveable(Moveable && m):h(move(m.h))
	{
		i = m.i;
		*i = 10;
		cout << __func__ << "nono " << endl;
		*(m.i)=*(m.i)+1;
		m.i = nullptr;

	}
	int * i;
	HugeMem h;
};


Moveable GetTemp()
{
	Moveable tmp = Moveable();
	cout << hex << "huge mem from " << __func__ << " @" << tmp.h.c << "value is " << *tmp.i << endl;
	return tmp;
}

int main()
{
	Moveable a(GetTemp());
	cout << hex << "huge mem from " << __func__ << " @" << a.h.c <<  "value is " << *a.i  << endl;
}