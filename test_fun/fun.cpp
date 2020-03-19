//
// Created by james on 2019-05-29.
//

#include <array>
#include <regex>
#include <queue>
#include <gtest.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "fun.h"

using namespace std;

void ve(shared_ptr<TreeNode> node, string &result) {
	string tmp;
	if (node != nullptr) {
		tmp = std::to_string(node->val);
		result += tmp;
	} else {
		tmp = "#";
		result += tmp;
		return;
	}
	ve(node->left, result);
	ve(node->right, result);
}
//
//string serialize(shared_ptr<TreeNode> root)
//{
//	string result;
//	std::queue<shared_ptr<TreeNode>> q_val;
//	q_val.push(root);
//	int is_left = true;
//	while(q_val.size() != 0)
//	{
//		auto next = q_val.front();
//
//		if(next == nullptr)
//		{
//			result += ",#";
//		}
//		if (next != nullptr) {
//			q_val.push(next->left);
//			q_val.push(next->right);
//			result += "," + std::to_string(next->val);
//		}
//
//		q_val.pop();
//	}
//
//	return result;
//	// write your code here
//}

string serialize(shared_ptr<TreeNode> root) {
	queue<shared_ptr<TreeNode>> q_val;
	vector<shared_ptr<TreeNode>> v_val;
	q_val.push(root);
	while (q_val.size() != 0) {
		auto next = q_val.front();
		if (next != nullptr) {
			q_val.push(next->left);
			q_val.push(next->right);
		}
		v_val.push_back(next);
		q_val.pop();
	}

	for (int i = 0; i < v_val.size(); ++i) {
		if (v_val[v_val.size() - 1] == nullptr) {
			v_val.pop_back();
		} else {
			break;
		}
	}

	string result = std::to_string(v_val[0]->val);
	int len = v_val.size();
	for (int j = 1; j < len; ++j) {
		if (v_val[j] == nullptr) {
			result += ",#";
		} else {
			result += "," + std::to_string(v_val[j]->val);
		}
	}

	return result;
}


void insert_tree(TreeNode *head, int val) {

}



//shared_ptr<TreeNode> deserialize(string &data) {
//	// write your code here
//	vector<string> vec_data = split(data, ",");
//	print(vec_data);
//
//	vector<shared_ptr<TreeNode>> tmp_vec;
//	for (auto item:vec_data) {
//		shared_ptr<TreeNode> next;
//		if (item == "#")
//		{
//			next = shared_ptr<TreeNode>(nullptr);
//		}else {
//			next = shared_ptr<TreeNode>(new TreeNode(stoi(item)));
//		}
//		tmp_vec.push_back(std::move(next));
//	}
//	auto head = tmp_vec[0];
//
//	int len = tmp_vec.size()/2;
//	for (int i = 0; i < len; ++i) {
//		tmp_vec[i]->left = tmp_vec[i*2+1];
//		tmp_vec[i]->right = tmp_vec[i*2+2];
//	}
//
//	return head;
//}



vector<string> split(const string &data_src, const string &delimiter) {
	vector<string> result;
	int index = 0;
	int lastindex = 0;
	while ((index = data_src.find(delimiter, lastindex)) != string::npos) {
		result.push_back(data_src.substr(lastindex, index - lastindex));
		lastindex = index + delimiter.length();
	}

	result.push_back(data_src.substr(lastindex, -1));
	return result;
}

int fib(int n) {
	if (n == 1 || n == 2)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

vector<int> merage(vector<int> &left, vector<int> &right) {
	int left_len = left.size();
	int right_len = right.size();
	vector<int> result;

	int i = 0;
	int j = 0;
	while (i < left_len && j < right_len) {
		if (left[i] > right[j]) {
			result.push_back(right[j]);
			j++;
		} else {
			result.push_back(left[i]);
			i++;
		}
	}

	if (i < left_len) {
		for (int k = i; k < left_len; ++k) {
			result.push_back(left[k]);
		}
	}
	if (j < right_len) {
		for (int k = j; k < right_len; ++k) {
			result.push_back(right[k]);
		}
	}
	return result;
}

int find_biggest(vector<int> &a, int n) {
	sort(a.begin(), a.end(), greater<int>());
	return a[n];
}

int nthUglyNumber(int n) {
//	int *uglys = new int[n];
	vector<int> uglys(n);
	uglys[0] = 1;
	int next = 1;
	auto p2 = uglys.begin();
	auto p3 = uglys.begin();
	auto p5 = uglys.begin();
	while (next < n) {
		int m = min(min(*p2 * 2, *p3 * 3), *p5 * 5);
		uglys[next] = m;
		while (*p2 * 2 == uglys[next])
			p2++;
		while (*p3 * 3 == uglys[next])
			p3++;
		while (*p5 * 5 == uglys[next])
			p5++;
		next++;
	}
	int uglyNum = uglys[n - 1];
	//delete[] uglys;
	return uglyNum;
}

int have_ke(int k, int n) {
	if (k == 0 && n == 0) {
		return 1;
	}
	int count = 0;
	for (int i = 0; i < k; ++i) {
		count += single_num(i, n);
	}
	return count;
}

int single_num(int k, int n) {
	if (k == 0 && n == 0) {
		return 1;
	}
	int i = 0;
	while (k > 0) {
		if (k % 10 == n) {
			i++;
		}
		k = k / 10;
	}

	return i;

}

int char_nums(int n) {
	int result = 1;
	for (int i = 1; i <= n; ++i) {
		result *= i;
	}

	cout << result << endl;
	string num = to_string(result);

	regex d("0");

	smatch sm;
	int count = 0;
	while (regex_search(num, sm, d)) {
		num = sm.suffix();
		count++;
	}

	return count;
}

int aplusb(int a, int b) {
	// 主要利用异或运算来完成
	// 异或运算有一个别名叫做：不进位加法
	// 那么a ^ b就是a和b相加之后，该进位的地方不进位的结果
	// 然后下面考虑哪些地方要进位，自然是a和b里都是1的地方
	// a & b就是a和b里都是1的那些位置，a & b << 1 就是进位
	// 之后的结果。所以：a + b = (a ^ b) + (a & b << 1)
	// 令a' = a ^ b, b' = (a & b) << 1
	// 可以知道，这个过程是在模拟加法的运算过程，进位不可能
	// 一直持续，所以b最终会变为0。因此重复做上述操作就可以
	// 求得a + b的值。
	while (b != 0) {
		int _a = a ^b;
		int _b = (a & b) << 1;
		a = _a;
		b = _b;
	}
	return a;
}


vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {

	vector<string> result;
	if (list1.empty() || list2.empty())
		return result;
	int l1 = list1.size();
	int l2 = list2.size();
	int len = l1 + l2;

	for (int i = 0; i != l1; ++i)
//	for(auto item : list1)
	{
		for (int j = 0; j < l2; ++j) {
			if (list2[j] == list1[i]) {
				if (len < (j + i)) {
					result.clear();
					result.push_back(list1[i]);
					len = j + i;
				}
				if (len = (j + i)) {
					result.push_back(list1[i]);
				}
			}
		}
		return result;
	}

	return result;
	// Write your code here
}

vector<string> findRestauranta(vector<string> &list1, vector<string> &list2) {
	int ans = list1.size() + list2.size();
	vector<string> s;
	for (int i = 0; i < list1.size(); i++)
		for (int j = 0; j < list2.size(); j++)
			if (list1[i] == list2[j]) {
				if (ans > i + j) {
					s.clear();
					ans = i + j;
					s.push_back(list1[i]);
				} else if (ans == i + j)
					s.push_back(list1[i]);
			}
	return s;
	// Write your code here
}

void doA(A a) {}

void doB(B b) {}


bool is_four(int num) {
	if ((num & num - 1) != 0)
		return false;

	if ((num & 0x55555555) == num)
		return true;

}

shared_ptr<TreeNode> deserialize(string &data) {
	std::queue<shared_ptr<TreeNode>> queue_tree;
	std::vector<std::string> vec_data = split(data, ",");
	int len = vec_data.size();
	int is_left = true;
	queue_tree.push(shared_ptr<TreeNode>(new TreeNode(std::stoi(vec_data[0]))));
	auto root = queue_tree.front();
	for (int i = 1; i < len; ++i) {
		shared_ptr<TreeNode> next;
		if (vec_data[i] == "#") {
			next = shared_ptr<TreeNode>(nullptr);
//			next = nullptr;
		} else {
			next = shared_ptr<TreeNode>(new TreeNode(std::stoi(vec_data[i])));
			queue_tree.push(next);
		}

		auto pos = queue_tree.front();
		if (is_left) {
			pos->left = next;
		} else {
			pos->right = next;
			queue_tree.pop();
		}

		is_left = !is_left;
	}
	return root;
}

//string turn_str(string &str, int pos) {
//	vector<char> v_str;
//	int len = str.size();
//	for (int i = 0; i < len; ++i) {
//		v_str.push_back(str[i]);
//	}
//	for (int j = 0; j < pos; ++j) {
//		char tmp = v_str.back();
//		v_str.pop_back();
//		v_str.insert(v_str.begin(),tmp);
//	}
//	string result;
//	for (auto item : v_str) {
//		result += item;
//	}
//	return result;
//}


void turn_str(string &str, int offset) {
	int len = str.size();
	if (len == 0) return;
	int pos = offset % len;

	str = str.substr(len - pos, pos) + str.substr(0, len - pos);
}

vector<string> n_to_str(int n) {
	vector<string> result;
	for (int i = 1; i <= n; ++i) {
		string tmp;
		if (i % 15 == 0) {
			tmp = "fizz buzz";
		} else if (i % 3 == 0) {
			tmp = "fizz";
		} else if (i % 5 == 0) {
			tmp = "buzz";
		} else {
			tmp = std::to_string(i);
		}
		result.push_back(tmp);
	}
	return result;
}


void to_tree(map<char, int> m_c, shared_ptr<Node<char>> &node, string tmp, int len, vector<string> &result);

//void get_data(const vector<NestedInteger> &nestedList, vector<int> &result);

vector<string> diff_sort(string &str) {
	map<char, int> v_c;
	static vector<string> result;

	int len = str.size();
	for (int i = 0; i < len; ++i) {
		v_c[str[i]]++;
	}
	shared_ptr<Node<char>> node = shared_ptr<Node<char>>(new Node<char>('\n'));

	string tmp;
	to_tree(v_c, node, tmp, len, result);


	return result;
}

vector<int> tree_sub(vector<int> v_arr, int begin, int end) {

	auto node = shared_ptr<TwoNode>(new TwoNode(v_arr[0]));

	for (int i = 1; i < v_arr.size(); i++) {
		node->add_node(v_arr[i], node);
	}
	vector<int> result;
	node->between(begin, end, node, result);
	return result;
}

int match_str(string source, string target) {
	int len = source.size();
	int tar_len = target.size();
	if (len == 0 && tar_len == 0) {
		return 0;
	}
	int j = 0;
	int before = 0;
	bool flag = true;
	for (int i = 0; i < len;) {
		if (source[i] == target[j]) {
			if (j == 0) {
				before = i;
				flag = true;
			}

			j++;
			i++;

		} else {
			j = 0;
			i = before + 1;
			before = i;
			flag = false;
		}
		if (j == tar_len && flag == true)
			return before;
	}
	return -1;
}

int binarySearch(vector<int> &nums, int target) {
	int mind = nums.size() / 2;
	int low = 0;
	int high = nums.size() - 1;
	int pos = -1;
	while (low <= high) {
		if (nums[mind] == target) {
			pos = mind;
		}
		if (nums[mind] < target) {
			low = mind + 1;
			mind = high - (high - mind) / 2;
		} else if (nums[mind] >= target) {
			high = mind - 1;
			mind = low + (mind - low) / 2;
		}
	}
	return pos;
}

void helper(vector<vector<int> > &results,
			vector<int> &subset,
			vector<int> &nums,
			int start) {
	results.push_back(subset);

	for (int i = start; i < nums.size(); i++) {
		subset.push_back(nums[i]);
		helper(results, subset, nums, i + 1);
		subset.pop_back();
	}
}

vector<vector<int>> subsets(vector<int> nums) {
	vector<vector<int>> result;
	vector<int> tmp;
	sort(nums.begin(), nums.end());

	sub(nums, result, tmp, 0);
	return result;

//	vector<vector<int> > results;
//	vector<int> subset;
//
//	sort(nums.begin(), nums.end());
//	helper(results, subset, nums, 0);
//
//	return results;
}


void TwoNode::add_node(int val, shared_ptr<TwoNode> node) {
	if (val > node->_val) {
		if (node->_right == nullptr) {
			auto new_node = shared_ptr<TwoNode>(new TwoNode(val));
			node->_right = new_node;
		} else
			add_node(val, node->_right);
	} else {
		if (node->_left == nullptr) {
			auto new_node = shared_ptr<TwoNode>(new TwoNode(val));
			node->_left = new_node;
		} else
			add_node(val, node->_left);
	}

}

void TwoNode::between(int a, int b, shared_ptr<TwoNode> node, vector<int> &result) {
	if (node == nullptr) {
		return;
	}
	if (node->_val >= a && node->_val <= b) {
		result.push_back(node->_val);
	}
	between(a, b, node->_left, result);
	between(a, b, node->_right, result);
}


void to_tree(map<char, int> m_c, shared_ptr<Node<char>> &node, string tmpp, int len, vector<string> &result) {
	if (tmpp.size() == len) {
		result.push_back(tmpp);
		return;
	}

	for (auto item : m_c) {
		auto tmp = m_c;
		if (item.second != 0) {
			auto new_node = shared_ptr<Node<char>>(new Node<char>(item.first));
			node->_nodes.push_back(new_node);
			tmp[item.first]--;
			string tmppp = tmpp;
			tmppp.push_back(item.first);
			to_tree(tmp, new_node, tmppp, len, result);
		}
	}
}


void fun::show() {
	std::cout << "hello" << std::endl;
}

void sub(vector<int> &nums, vector<vector<int>> &result, vector<int> &tmp_val, int start) {
	int len = nums.size();
	result.push_back(tmp_val);

	int before_val = nums[start];
	for (int i = start; i < len; ++i) {
		if (before_val == nums[i] && i > start) {
			continue;
		}
		int t = nums[i];
		tmp_val.push_back(t);
		sub(nums, result, tmp_val, i + 1);
		tmp_val.pop_back();
	}
}

void helper_dices(map<int, double> &sum, int n) {
	map<int, double> new_sum;
	if (n == 1)
		return;
	else
		n--;

	for (auto item = sum.begin(); item != sum.end(); ++item) {
		for (int j = 1; j <= 6; j++) {
			int new_val = item->first + j;
			new_sum[new_val] += item->second;
		}

	}
	double count = 0;
	for (auto item = new_sum.begin(); item != new_sum.end(); ++item) {
		count += item->second;
	}

	for (auto item = new_sum.begin(); item != new_sum.end(); ++item) {
		item->second = item->second / count;
	}
//	for (auto item : new_sum)
//	{
//		item.second = item.second/count;
//	}

	sum = new_sum;
	helper_dices(sum, n);
}

vector<pair<int, double>> dicesSum(int n) {
	map<int, double> result;
	if (n > 0) {
		for (int j = 1; j <= 6; j++) {
			result[j] = 0.17;
		}
	}

	helper_dices(result, n);

	vector<pair<int, double>> val_probability;

	for (auto item : result) {
		val_probability.push_back(make_pair(item.first, item.second));
	}
	return val_probability;
}

bool searchMatrix(vector<vector<int>> &matrix, int target){
	// write your code her
	int len = matrix.size();
	for (int i = 0; i < len; ++i)
	{
		if (target >= matrix[i][0] && target <= *(--matrix[i].end()))
		{
			return find(matrix[i].begin(), matrix[i].end(),target)!=matrix[i].end();
		}
	}

	return false;
}

void help_Inter(string s1, string s2, string s3, bool &result)
{

	auto iter = s3.begin(), iter1 = s1.begin(), iter2=s2.begin();
	for(; iter != s3.end(); ++iter)
	{
		if (iter1 != s1.end() && iter2!= s2.end() && *iter1 == *iter && *iter1  == *iter2)
		{
			help_Inter(string(iter1+1, s1.end()),string(iter2,s2.end()),string(iter+1,s3.end()), result);
			help_Inter(string(iter1, s1.end()),string(iter2+1,s2.end()),string(iter+1,s3.end()), result);
		}
		else if(iter1!=s1.end()&&*iter1==*iter)
		{
			++iter1;
		}
		else if (iter2!=s2.end()&&*iter2 == *iter)
		{
			++iter2;
		} else
			return;
	}
	if (iter==s3.end()&&iter2==s2.end()&&iter1==s1.end())
		result = true;
}
bool isInterleave(string &s1, string &s2, string &s3) {
	bool result=false;
	help_Inter(s1,s2,s3,result);
	return result;

}


class NestedInteger {
public:
	bool isInteger() const{ return false;}

	int getInteger() const{ return 1;}

	const vector<NestedInteger> &getList() const{ return vector<NestedInteger>();}
};

vector<int> flatten(vector<NestedInteger> &nestedList) {
	vector<int> result;
	std::queue<NestedInteger> q_N;
	for (auto item : nestedList) {
		q_N.push(item);
	}

	while(!q_N.empty())
	{
		auto tmp = q_N.front();
		if (tmp.isInteger())
			result.push_back(tmp.getInteger());
		else
		{
			auto tmp_v= tmp.getList();
			for (auto item: tmp_v)
			{
				q_N.push(item);
			}
		}

		q_N.pop();
	}

//	get_data(nestedList, result);

	return result;
	// Write your code here
}

void get_data(const vector<NestedInteger> &nestedList, vector<int> &result) {
	for (auto item:nestedList) {
		if (item.isInteger())
			result.push_back(item.getInteger());
		else {
			auto tmp_list = item.getList();
			get_data(tmp_list, result);
		}

	}
}

//int nthUglyNumbera(int n) {
//	// write your code here
//	priority_queue<long,vector<long>,greater<long>>qu;
//	qu.push(1);
//	if(n == 1)return 1;
//	for(int i = 1;i<n;i++){
//		long tmp = qu.top();
//		qu.push(tmp*2);
//		qu.push(tmp*3);
//		qu.push(tmp*5);
//		while(qu.top() == tmp)
//			qu.pop();
//	}
//	return qu.top();
//}
int nthUglyNumbera(int n) {
	// write your code here
	set<long long> bst;
	bst.insert(1);

	while (--n) {
		long long min_num = *bst.begin();
		bst.erase(min_num);
		bst.insert(min_num * 2);
		bst.insert(min_num * 3);
		bst.insert(min_num * 5);
	}

	return *bst.begin();
}



bool validTree(int n, vector< vector<int>> & edges) {
	// write your code here
	map<int, set<int>> graph;

	for(auto item = edges.begin(); item!=edges.end(); ++item)
	{
		graph[(*item)[0]].insert((*item)[1]);
		graph[(*item)[1]].insert((*item)[0]);
	}

	vector<int> seen_node;
	queue<int> q_next;
	q_next.push(0);
	seen_node.push_back(0);

	int len_count = 0;
	while (!q_next.empty())
	{
		int tmp = q_next.front();
		q_next.pop();
		for(auto item:graph[tmp])
		{
			if(find(seen_node.begin(), seen_node.end(), item) != seen_node.end())
				return false;
			graph[item].erase(tmp);
			q_next.push(item);
			seen_node.push_back(item);

		}
	}
	return seen_node.size() == n;

}



vector<int> maxSlidingWindow(vector<int> &nums, int k) {
	vector<int> result;
	if (nums.size() == 0) return result;


	int len = nums.size();
	if (len <= k)
	{
		auto a = max_element(nums.begin(),nums.end());
		result.push_back(*a);
		return result;
	}

	deque<int> window;
	for(int i = 0; i< k ; i++)
	{
		window.push_front(nums[i]);
	}


	int tmp_max = *max_element(window.begin(), window.end());
	result.push_back(tmp_max);

	for (int i = k; i< len; i++)
	{
		window.push_front(nums[i]);
		window.pop_back();
		result.push_back(max(tmp_max,nums[i]));
	}
	return result;
	// write your code here
}

bool operator < (const Connection& c1, const Connection& c2) {
	if (c1.cost != c2.cost)
		return c1.cost < c2.cost;

	if (c1.city1 != c2.city1)
		return c1.city1 < c2.city1;

	return c1.city2 < c2.city2;
}


vector<Connection> lowestCost(vector<Connection>& connections){

}