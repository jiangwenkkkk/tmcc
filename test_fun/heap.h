//
// Created by james on 2019-07-06.
//

#ifndef TESTPOCO_HEAP_H
#define TESTPOCO_HEAP_H

namespace Co_dd{
	class priority_queue{
	public:
		priority_queue(vector<int>::iterator begin, vector<int>::iterator end):c(begin, end){
			make_heap();
		}
		void push(int val){
			c.push_back(val);
			int len = c.size();
			for (int i = len-1; i > 0; ) {
				if(c[i] > c[i/2])
					swap(c[i], c[i / 2]);
				i = i/2;
			}
		}
		void pop()
		{
			c.erase(c.begin());
			make_heap();
		}

		int top(){
			return c[0];
		}

	private:
		vector<int> c;
	private:
		void make_heap(){
			int len = c.size();
			for (int i = 0; i < len; ++i) {
				for (int j = i; j > 0;) {
					if(c[j] > c[j/2])
					{
						swap(c[j], c[j/2]);
					}
					j = j/2;
				}
			}
		}

	};
}
#endif //TESTPOCO_HEAP_H
