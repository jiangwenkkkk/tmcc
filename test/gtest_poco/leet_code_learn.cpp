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


int romanToInt(string s) {

}
TEST(leet_code, romanToInt)
{
	string a = "MCMXCIV";
	romanToInt(a);
}


int myAtoi(string str) {
	int result = 0;
	int len = str.size();
	int index = 0;
	int temp = 0;
	bool is_num = false;
	int sign = 1;
	while(len > index)
	{
		temp = str[index];

		if(temp=='-' && is_num == false)
		{
			sign = -1;
			is_num = true;
			index++;
			continue;
		}


		if(temp=='+' && is_num == false)
		{
			sign = 1;
			is_num = true;
			index++;
			continue;
		}

		if(temp >= '0' && temp <= '9')
		{
			temp = str[index] - '0';
			is_num = true;
			int max =  INT_MAX/10;
			int min =  INT_MIN/10;
			if(result > INT_MAX/10 || (result == INT_MAX/10 && temp >= 7)) return INT_MAX;
			if(result < INT_MIN/10 || (result == INT_MIN/10 && temp >= 8)) return INT_MIN;

			result = result*10+temp*sign;
			index++;
			continue;
		}

		if(temp==' '&& is_num == false)
		{
			index++;
			continue;
		}
		else if (temp == ' ' && is_num == true)
			break;


		if(is_num == false)
			return 0;
		else
			break;
	}
	return result;
}

TEST(leet_code, myAtoi){
	ASSERT_EQ(myAtoi("4193 with words"),4193);
	ASSERT_EQ(myAtoi("a 4193 with words"),0);
	ASSERT_EQ(myAtoi("-91283472332"),-2147483648);
	ASSERT_EQ(myAtoi(" -91283472332"),-2147483648);
	ASSERT_EQ(myAtoi(" +91283472332"),2147483647);
	ASSERT_EQ(myAtoi(" ++91283472332"),0);
	ASSERT_EQ(myAtoi("3.14"),3);
	ASSERT_EQ(myAtoi("3a"),3);
	ASSERT_EQ(myAtoi("3a3"),3);


//	std::cout << myAtoi("3.12");

	string a=" - -110--0";
	std::cout << atoi(a.c_str());
	a="abc3.14";
	std::cout << atoi(a.c_str());
}
