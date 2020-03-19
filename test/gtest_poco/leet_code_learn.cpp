//
// Created by james on 2020-03-17.
//

#include <gtest.h>
#include <list>
using namespace std;

class node{
public:
	char ch;
	std::list<node*> left;
	std::list<node*> right;
};
class tree{
public:
	node* head;
	bool insert_val(char before, char last)
	{

	}
};

TEST(leet_code, longest_substring)
{
	std::string str = "hello world";
	int len = str.length();
	node head;
	for (int i = 0; i < len; i++)
	{

	}

}

int is_same(std::string src, int begin, int end, int mid)	
{
	mid =( begin + end) /2;

	if (begin== end)
		if(src[begin]== src[end])
			return mid;
		else
			return -1;

}

bool merge(string src, int a, int b) {

}



int reverse_a(int x) {
	int rev = 0;
	while (x != 0) {
		int pop = x % 10;
		x /= 10;
		if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
		if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
		rev = rev * 10 + pop;
	}
	return rev;
}

TEST(leet_code, reverse_int)
{
	std::cout << reverse_a(93412344243515) << std::endl;

	string a="hello";
	string b = "hello";

	if (a == b)
	{
		std::cout << "ok";
	}
}
