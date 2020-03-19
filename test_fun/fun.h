//
// Created by james on 2019-05-29.
//

#ifndef TESTPOCO_FUN_CH_H
#define TESTPOCO_FUN_CH_H
//
// Created by james on 2019-05-29.
//

#include <array>
#include <regex>
#include <queue>
#include <gtest.h>
#include <stack>
#include <list>
#include <unordered_map>

using namespace std;

namespace fun{
	void show();
}
class TreeNode {
public:
	int val;
	std::shared_ptr<TreeNode>left, right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
		cout << __FUNCTION__ << endl;
	}
	~TreeNode(){
		cout << __FUNCTION__<< endl;
	}
};

string serialize(shared_ptr<TreeNode> root);

template <class T>
void print(vector<T>& a)
{
	for (auto item : a)
	{
		cout << item << endl;
	}
}
void insert_tree(TreeNode* head, int val);

vector<string> split(const string &data, const string &delimiter);

shared_ptr<TreeNode> deserialize(string &data) ;

vector<string> split(const string &data_src, const string &delimiter) ;

int fib(int n);

vector<int> merage(vector<int> &left, vector<int> &right) ;

int find_biggest(vector<int> &a, int n) ;

int nthUglyNumber(int n) ;
int have_ke(int k, int n);

int single_num(int k, int n) ;

int char_nums(int n);

int aplusb(int a, int b);

class ab {
	friend void addm(ab a) {
		cout << __FUNCTION__ << endl;
		a.tmm();
	}

private:
	void tmm() {
		cout << __FUNCTION__ << endl;
	}

public:
	~ab() {
		cout << __FUNCTION__ << endl;
	}

};

vector<string> findRestauranta(vector<string> &list1, vector<string> &list2);
vector<string> findRestaurant(vector<string> &list1, vector<string> &list2);

class sb {
private:
	sb(int a);

	int _a;
};

class test_unit {
public:

	~test_unit() {
		cout << __FUNCTION__ << endl;
	}
};

struct A {
	A(int) {}

	operator bool() const { return true; }
};

struct B {
	explicit B(int) {}

	explicit operator bool() const { return true; }
};

void doA(A a);

void doB(B b);
bool is_four(int num);
class teT {
	int age;

	void sed() {
		this->age = 10;
//		printf("%d", &this);
	}
};

union UnionTest {
	UnionTest() : i(10) {};
	int i;
	double d;
};

static union {
	int i;
	double d;
};


class Singer {
public:
	Singer *getinstance() {
		if (_instance == nullptr) {
			_instance = new Singer();
			return _instance;
		}
		return _instance;
	}

private:
	static Singer *_instance;

	Singer() {

	}

};
void ve(shared_ptr<TreeNode> node, string& result);

void turn_str(string &str, int offset);

vector<string> n_to_str(int n);

template <class T>
class Node {
public:
	vector<shared_ptr<Node>> _nodes;
	T _val;
public:
	Node(T val):_val(val)
	{
	}
};
vector<string> diff_sort(string &string1);

vector<int> tree_sub(vector<int> v_arr, int begin, int end);

class TwoNode{
public:
	int _val;
	shared_ptr<TwoNode> _left, _right;
public:
	TwoNode(int val) : _val(val){}
	void add_node(int val, shared_ptr<TwoNode> node);
	void between(int a, int b, shared_ptr<TwoNode> node, vector<int> &result);
};

class MinStack {
public:
	MinStack() {
		// do intialization if necessary
	}

	/*
	 * @param number: An integer
	 * @return: nothing
	 */
	void push(int number) {
		// write your code here
		stk.push(number);
		if (minstk.empty() or minstk.top() >= number) {
			minstk.push(number);
		}
	}

	/*
	 * @return: An integer
	 */
	int pop() {
		// write your code here
		int val = stk.top();
		stk.pop();
		return val;
	}

	/*
	 * @return: An integer
	 */
	int min() {
		// write your code here
		return minstk.top();
	}
	stack<int> stk, minstk;

};

int match_str(string source,string target);

int binarySearch(vector<int> &nums, int target);
void sub(vector<int> &nums, vector<vector<int>> &result, vector<int> &tmp_val, int start);
vector<vector<int>> subsets(vector<int> nums);

vector<pair<int, double>> dicesSum(int n);


struct Comp
{
	bool operator()(const shared_ptr<pair<int,int>>& s1, const shared_ptr<pair<int,int>>& s2)
	{
		return s1->second < s2->second;
	}
};

class LFUCache {
public:
	/*
	* @param capacity: An integer
	*/
	LFUCache(int capacity) {
		// do intialization if necessary
		_capacity = capacity;
	}

	/*
	 * @param key: An integer
	 * @param value: An integer
	 * @return: nothing
	 */
	bool big(pair<int,int>& a,pair<int,int>& b){
		if (a.first == b.first)
			return true;
		else
			return false;
	}
	void set(int key, int value) {
		if(_capacity < 0) return;
		if (get(key) != -1)
		{
			_m_val[key].first = value;
			return;
		}

		if (_m_val.size() >= _capacity)
		{
			auto last_key = _freq[_minFreq].begin();
			_m_val.erase(*last_key);
			_freq[_minFreq].erase(last_key);
			iters.erase(*last_key);
		}

		_m_val[key]=make_pair(value,1);
		_freq[1].push_back(key);
		iters[key]=--_freq[1].end();
		_minFreq = 1;

	}

	/*
	 * @param key: An integer
	 * @return: An integer
	 */
	int get(int key) {
		// write your code here
		if (_m_val.count(key) == 0)
			return -1;
		_freq[_m_val[key].second].erase(iters[key]);
		++_m_val[key].second;
		_freq[_m_val[key].second].push_back(key);
		iters[key] = --_freq[_m_val[key].second].end();
		if (_freq[_minFreq].empty()) _minFreq++;
		return _m_val[key].first;

	}

private:

	unordered_map<int, pair<int,int>> _m_val;
	unordered_map<int, std::list<int>> _freq;
	unordered_map<int, std::list<int>::iterator> iters;

	int _capacity, _minFreq;
};

bool searchMatrix(vector<vector<int>> &matrix, int target);

bool isInterleave(string &s1, string &s2, string &s3);

int nthUglyNumbera(int n) ;
bool validTree(int n, vector<vector<int>> &edges);
vector<int> maxSlidingWindow(vector<int> &nums, int k);


class Connection {
public:
	string city1, city2;
	int cost;

	Connection(string &city1, string &city2, int cost) {

		this->city1 = city1;

		this->city2 = city2;

		this->cost = cost;
	}
};

vector<Connection> lowestCost(vector<Connection>& connections);

#endif //TESTPOCO_FUN_CH_H
