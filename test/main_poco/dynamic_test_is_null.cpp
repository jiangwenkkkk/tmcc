//
// Created by james on 2019-10-18.
//

#include <string>
#include <iostream>
#include <vector>


class father{
public:
	father(std::string name):_name(name){}
	virtual ~father(){}
	void show_name()const{std::cout << _name << std::endl;}
	virtual void play()const{std::cout << "play car" << std::endl;}
private:
	std::string _name;
};


class son:public father{
public:
	son(std::string name):father(name){}
	virtual ~son(){}
	void play()const{std::cout << "play mode car" << std::endl;}
};

class daughter : public father{
public:
	daughter(std::string name):father(name){}
	virtual ~daughter(){}
	void play()const{std::cout << "play baba" << std::endl;}
};


int main()
{
	std::vector<father*> a;
	a.push_back(new son("tom"));
	a.push_back(new daughter("saisy"));
	a.push_back(new father("bob"));

	for (int i = 0; i < a.size(); ++i) {
		const son* ps = dynamic_cast<const son*>(a[i]);
		if(ps)
		{
			ps->show_name();
			ps->play();
		}
	}
}


//dynamic_cast只能够正确转换,否则返回空指针