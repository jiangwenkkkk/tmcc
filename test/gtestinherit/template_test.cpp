//
// Created by james on 2020-04-30.
//

#include <gtest/gtest.h>

class Materia{
public:
	virtual void push()=0;
	virtual ~Materia(){}
};

class WatherMateria : public Materia{
public:
	void push()
	{
		std::cout << "this is water, kill fire very good, no for flammable metal" << std::endl;
	}
	~WatherMateria(){}
};

class ModMateria{
public:
	virtual void push()
	{
		std::cout << "this is mod, kill fire very good, no for flammable metal" << std::endl;
	}
};

template <class T >
class FireExtinguisher
{
public:
	FireExtinguisher(T* materia):_materia(materia){}
	void push()const
	{
		_materia->push();
	}

private:

	T* _materia;

};

class FireMan
{
public:
	void extinguishing(const FireExtinguisher< class Materia>& fireExtinguisher){
		fireExtinguisher.push();
	}

};

TEST(template_class, t)
{
//	ModMateria modMateria;
//	FireExtinguisher<ModMateria> fireExtinguisher(modMateria);
//	FireMan tom;
//	tom.extinguishing(fireExtinguisher);

	WatherMateria watherMateria;
	FireExtinguisher<Materia> fireExtinguishera(&watherMateria);
	FireMan jake;
	jake.extinguishing(fireExtinguishera);
	jake.extinguishing(FireExtinguisher<Materia>(&watherMateria));
//
//	tom.extinguishing(FireExtinguisher<ModMateria>(watherMateria));

}


class Cup{
public:
	void take(int water){
		_capacity+=water;
		std::cout << _capacity << std::endl;
	}


private:
	int _capacity = 0;
};

void hell(Cup a)
{
	a.take(10);
}
TEST(is_ok, just_have){
	hell(Cup());
};