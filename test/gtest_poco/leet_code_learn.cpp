//
// Created by james on 2020-03-17.
//

#include <gtest.h>
#include <list>
#include <deque>
#include <queue>


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


string longestCommonPrefix(vector<string>& strs) {
	if (strs.empty())
		return "";
	string prefix;
	int shortest_len = 0;
	for(auto iter = strs.begin(); iter != strs.end(); ++iter)
	{
		if (shortest_len < (*iter).size())
			shortest_len = (*iter).size();
	}

	char pos_prefix;
	bool is_end=true;
	int index = 0;
	for (; index < shortest_len; ++index)
	{
		pos_prefix = strs[0][index];
		for(auto iter = strs.begin(); iter != strs.end(); ++iter)
		{
			if (pos_prefix != (*iter)[index])
			{
				is_end=false;
				break;
			}
		}
		if (is_end==false)
			break;
	}

	prefix = strs[0].substr(0,index);
	return prefix;
}

TEST(leet_code, longestCommonPrefix)
{
	vector<string> a={"flower", "flow", "flight"};
	ASSERT_EQ(longestCommonPrefix(a),"fl");
	a={};
	ASSERT_EQ(longestCommonPrefix(a),"");

}

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == nullptr && q == nullptr) return true;
	if (p == nullptr || q == nullptr) return false;
	bool left = true;
	bool right = true;
	if (p->val != q->val)
		return false;

	left = isSameTree(p->right, q->right);
	right =  isSameTree(p->left, q->left);

	return left&right;
}

TEST(leet_code, isSameTree)
{
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.left = &b;
	a.right = &c;

	TreeNode d(1);
	TreeNode e(2);
	TreeNode f(3);
	d.left = &e;
	d.right = &f;

	ASSERT_EQ(isSameTree(&a, &d),true);

	TreeNode a1(1);
	TreeNode b1(2);
	TreeNode c1(3);
	a1.left = &b1;
	a1.right = &c1;

	TreeNode d1(1);
	TreeNode e1(2);
	TreeNode f1(1);
	d1.left = &e1;
	d1.right = &f1;

	ASSERT_EQ(isSameTree(&a1, &d1), false);

	TreeNode a2(1);
	TreeNode b2(-5);
	a1.left = &b2;

	TreeNode d2(1);
	TreeNode e2(-8);
	d2.left = &e2;

	ASSERT_EQ(isSameTree(&a2, &d2), false);
}

bool is_same_a(TreeNode* left, TreeNode* right)
{
	if (left == nullptr && right == nullptr) return true;
	if (left == nullptr || right == nullptr) return false;


	if (left->val != right->val)
		return false;

	return is_same_a(left->left,right->right)&is_same_a(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
	if (root == nullptr) return true;


	return is_same_a(root->left, root->right);
}



TEST(leet_code, isSymmetric)
{
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(2);
	a.left = &b;
	a.right = &c;

	ASSERT_EQ(isSymmetric(&a),true);

	TreeNode a1(1);
	TreeNode b1(2);
	TreeNode c1(3);
	a1.left = &b1;
	a1.right = &c1;

	ASSERT_EQ(isSymmetric(&a1), false);
}

void depth(TreeNode*  node, int& _depth, int index)
{
	if(node == nullptr) return;
	index++;
	if (_depth < index)
		_depth = index;
	depth(node->left, _depth,index);
	depth(node->right,_depth,index);
}

int maxDepth(TreeNode* root) {

	int _depth = 0;
	int index = 0;
	depth(root, _depth, index);
	return _depth;
}

int maxDeptha(TreeNode* root)
{
	if (root == nullptr)return 0;

	std::queue<TreeNode*> q_t;
	q_t.push(root);
	int len = 0;
	while (!q_t.empty()) {
		len++;
		int n = q_t.size();
		for (int i = 0; i < n; i++)
		{
			TreeNode * p = q_t.front(); q_t.pop();
			if(p->left) q_t.push(p->left);
			if(p->right) q_t.push(p->right);
		}
	}

	return len;
}

bool tmp(int a )
{
	std::cout << "hello" << std::endl;
}


TEST(ll,tmp)
{
	cout << tmp(10) << endl;
	cout << tmp(10) << endl;
	cout << tmp(10) << endl;
	cout << tmp(10) << endl;
	cout << tmp(10) << endl;
	cout << tmp(10) << endl;
	cout << tmp(10) << endl;
	cout << tmp(10) << endl;

}

TEST(leet_code, maxDepth)
{
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(2);
	a.left = &b;
	a.right = &c;

	ASSERT_EQ(maxDepth(&a),2);
	ASSERT_EQ(maxDeptha(&a),2);

	TreeNode a1(1);
	TreeNode c1(3);
	a1.right = &c1;

	ASSERT_EQ(maxDepth(&a1), 2);
	ASSERT_EQ(maxDeptha(&a1), 2);

	ASSERT_EQ(maxDepth(nullptr), 0);
	ASSERT_EQ(maxDeptha(nullptr), 0);


}

