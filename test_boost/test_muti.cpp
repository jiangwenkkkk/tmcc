//
// Created by james on 2019-04-14.
//

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <algorithm>
#include <iostream>
#include <string>
#include "boost/algorithm/string.hpp"
#include "boost/multi_index_container.hpp"
#include "boost/multi_index/ordered_index.hpp"
#include "boost/multi_index/hashed_index.hpp"
#include "boost/multi_index/identity.hpp"
#include "boost/multi_index/member.hpp"



struct Employee {
	Employee(int id_, const std::string& name_) :
			id(id_),
			name(name_) {
	}

	int id;//编号
	std::string name;//姓名

	//default compare by id
	bool operator<(const Employee& employee) const {
		return id < employee.id;
	}

	friend std::ostream& operator<<(std::ostream& out, const Employee& employee) {
		out << employee.id << "\t" << employee.name << std::endl;
		return out;
	}
};//Employee

typedef boost::multi_index::multi_index_container<
Employee,
boost::multi_index::indexed_by<
		boost::multi_index::ordered_unique<
		boost::multi_index::identity<Employee> >,
boost::multi_index::ordered_non_unique<
boost::multi_index::member<Employee, std::string, &Employee::name> >
>
> EmployeeSet;

/*
 * 临时屏蔽
int main()
{
	EmployeeSet employees;

	employees.insert({5, "Jeff Dean"});
	employees.insert({1, "Google"});
	employees.insert({3, "Bidu"});
	employees.insert({2, "Markus Heule"});
	employees.insert({4, "Vlad Losev"});

	const EmployeeSet::nth_index<1>::type& name_index = employees.get<0>();
	std::copy(
			name_index.begin(),
			name_index.end(),
			std::ostream_iterator<Employee>(std::cout));
}
 */