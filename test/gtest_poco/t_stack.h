//
// Created by james on 2019-02-24.
//

#ifndef TESTPOCO_T_STACK_H
#define TESTPOCO_T_STACK_H

#include <deque>

namespace tmc
{
	template<class T, template <class ELEM, class ALLOC=std::allocator<ELEM>> class CONT = std::deque>
	class Stack {
	private:
		CONT<T> elems;
	public:
		void push(T const &element) {
			elems.push_back(element);
		}

		void pop() {
			if (elems.empty())
				throw std::out_of_range("Stack<>::pop: empty stack");
			elems.pop_back();
		}

		T top() const {
			if (elems.empty())
				throw std::out_of_range("Stack<>::top: empty stack");

			return elems.back();
		}

		bool empty() const {
			return elems.empty();
		}


//		template <class T2, template <class ELEM> class CONT2>
//				Stack<T, CONT>&operator=(const Stack<T2, CONT2>&);
//
		template<class T2, template <class ELEM, class ALLOC=std::allocator<ELEM>> class CONT2 = std::deque>
		Stack<T, CONT>&operator=(const Stack<T2,CONT2> &);
	};

	template<class T, template <class ELEM, class ALLOC=std::allocator<ELEM>> class CONT>
	template<class T2, template <class ELEM, class ALLOC=std::allocator<ELEM>> class CONT2>
			Stack<T, CONT> &Stack<T, CONT>::operator=(const Stack<T2,CONT2> &opt2) {
		if ((void*)&opt2 == (void*)this)
			return *this;

		Stack<T2, CONT2>tmp(opt2);
		elems.clear();
		while (!tmp.empty())
		{
			elems.push_front(tmp.top());
			tmp.pop();
		}
		return *this;
	}

	template <class T>
	class Base{
			public:
				void exit(){}
			};

	template <class T>
	class Derived: public Base<T>{
	public:
		void foo()
		{
			Base<T>::exit();
		}
	};
}

#endif //TESTPOCO_T_STACK_H
