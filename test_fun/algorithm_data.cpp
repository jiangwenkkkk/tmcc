//
// Created by james on 2019-05-29.
//

#include <gtest.h>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include "fun.h"
#include "heap.h"

TEST(is_4, t) {
	queue<int> ab;
	ab.push(10);
	for (int i = 0; i < 0xFFF; ++i) {
		if (is_four(i))
			std::cout << i << std::endl;
	}
	ab.pop();
	std::cout << std::endl;
}

TEST(alg, queue_t) {
	std::queue<int> a;
	for (int i = 0; i < 10; ++i) {
		a.push(i);
	}
	for (int j = 0; j < 20; ++j) {
		std::cout << a.front() << std::endl;
		a.pop();
	}

}

TEST(algo, turn_str) {
	string a = "hello";
	turn_str(a, 2);
	ASSERT_EQ(string("lohel"), a);
}


TEST(algo, fizzbuzz) {
	auto a = n_to_str(15);
}


TEST(algo, diff_sort) {
	string a = "abcc";
	auto re = diff_sort(a);
	vector<int> b = {1, 3};
	print(re);
}

TEST(algo, tree_sub) {
	vector<int> val = {20, 8, 22, 4, 12};
	auto result = tree_sub(val, 10, 22);
	int t_r[] = {12, 20, 22};

	//ASSERT_EQ(result, vector<int>(t_r, t_r + sizeof(t_r)/ sizeof(int)));
}

TEST(algo, mathch_str) {
	ASSERT_EQ(1, match_str("hello", "ell"));
	ASSERT_EQ(2, match_str("hello", "ll"));
	ASSERT_EQ(2, match_str("hello", "l"));
	ASSERT_EQ(-1, match_str("source", "target"));
//	ASSERT_EQ(1, match_str("hello", "a"));
}

TEST(algo, binarySearch) {
	int a[] = {3, 4, 5, 8, 8, 8, 8, 10, 13, 14};
	vector<int> v_val(a, a + sizeof(a) / sizeof(int));
	ASSERT_EQ(3, binarySearch(v_val, 8));

	int b[] = {1, 4, 4, 5, 7, 7, 8, 9, 9, 10};
	vector<int> v_val1(b, b + sizeof(b) / sizeof(int));
	ASSERT_EQ(0, binarySearch(v_val1, 1));

	int c[] = {4, 5, 9, 9, 12, 13, 14, 15, 15, 18};
	vector<int> v_val2(c, c + sizeof(c) / sizeof(int));
	ASSERT_EQ(-1, binarySearch(v_val2, 10));
}

TEST(algo, subsets) {
	vector<vector<int>> result = {{},
								  {4},
								  {5},
								  {4, 5}};
	vector<int> v_val = {4, 5, 5, 5};
	ASSERT_EQ(result, subsets(v_val));
}

TEST(algo, set_eq) {
	set<int> a = {1, 3, 5, 6};
	set<int> b = {1, 3, 5, 4};

	ASSERT_EQ(a, b);
}

TEST(algo, dicesSum) {
	vector<pair<int, double >> v_val = {{1, 0.17},
										{2, 0.17},
										{3, 0.17},
										{4, 0.17},
										{5, 0.17},
										{6, 0.17}};
	dicesSum(2);
	ASSERT_EQ(v_val, dicesSum(2));
}

TEST(algo, map) {
	map<int, int> a;
	for (int i = 0; i < 10; ++i) {
		a[i] = i;
	}
	auto print = [](const pair<int, int> &a) { cout << a.second << endl; };
	for_each(a.begin(), a.end(), print);

	for (auto item : a) {
		item.second += 1;
	}
	for_each(a.begin(), a.end(), print);

	for (auto iter = a.begin(); iter != a.end(); ++iter) {
		iter->second += 1;
	}

	for_each(a.begin(), a.end(), print);

//	ASSERT_EQ(1, a);


}


int add(vector<int> &a) {
	for (auto item = a.begin(); item != a.end(); ++item) {
		std::cout << *item << std::endl;
	}
}

TEST(aajjj, ba) {
	map<int, int> tmp;
	tmp.insert(make_pair(11, 11));
//	tmp[1] =2;
	vector<int> a = {10, 11, 323};
	add(a);
}

TEST(algo, make_heap)
{
  auto a = 	LFUCache(3);
//	a.set(2, 2);
//	a.set(1, 1);
//	a.get(2);
//	a.get(1);
//	a.get(2);
//	a.set(3, 3);
//	a.set(4, 4);
//	a.get(3);
//	a.get(2);
//	a.get(1);
//	a.get(4);

	a.set(1, 10);
	a.set(2, 20);
	a.set(3, 30);
	a.get(1);
	a.set(4, 40);
	a.get(4);
	a.get(3);
	a.get(2);
	a.get(1);
	a.set(5, 50);
	a.get(1);
	a.get(2);
	a.get(3);
	a.get(4);
	a.get(5);

}

TEST(algo,searchMatrix)
{
	vector<vector<int>> matrix = {{1,4,},{6,7,8}};
//	ASSERT_FALSE(searchMatrix(matrix,6));
	ASSERT_TRUE(searchMatrix(matrix,6));
}

TEST(algo,isInterleave)
{
	string a ="aabcc";

	string b =  "dbbca";

	string c =  "aadbbcbcac";
	ASSERT_TRUE(isInterleave(a,b ,c));
};

TEST(algo_data, max_size)
{
	std::map<int,string> s;
	std::set<string> ss;
	std::cout << "Maximum size of a 'map' is " << s.max_size() << "\n";
	std::cout << "Maximum size of a 'map' is " << ss.max_size() << "\n";
}

TEST(data, priority_queue)
{
	int ia[9] = {0,1,2,3,4,8,9,3,5};
	priority_queue<int> ipq(ia, ia+9);
	cout << "size=" << ipq.size() << endl; // size=9
	for(int i=0; i<ipq.size(); ++i)
		cout << ipq.top() << ' '; // 9 9 9 9 9 9 9 9 9
	cout << endl;
	while(!ipq.empty()) {
		cout << ipq.top() << ' '; // 9 8 5 4 3 3 2 1 0
		ipq.pop();
	}
	cout << endl;
}

TEST(data, set_test)
{
	set<int> a;
	vector<int>b;
	b.push_back(1);
	a.insert(25);
	a.insert(26);
	a.insert(27);
	a.insert(28);
	a.insert(29);
	a.insert(11);
	a.insert(12);
	a.insert(13);
	a.insert(14);
	a.insert(15);
	a.insert(16);
	a.insert(17);
	a.insert(18);
	a.insert(19);
	a.insert(21);
	a.insert(22);
	a.insert(23);
	a.insert(24);


	for (auto item = a.begin(); item != a.end(); ++item) {
		cout << *item << endl;
	}

}
TEST(data, map)
{
	map<int,int> a;
	vector<int>b;
	a[16]=11;
	a[17]=11;
	a[18]=11;
	a[19]=11;
	a[20]=11;
	a[10]=11;
	a[11]=11;
	a[12]=11;
	a[13]=11;
	a[14]=11;
	a[15]=11;

	a[21]=11;
	a[22]=11;
	a[23]=11;
	a[24]=11;
	a[25]=11;
	a[26]=11;
	a[27]=11;
	a[28]=11;
	a[29]=11;

	for (auto item = a.begin(); item != a.end(); ++item) {
		cout << (*item).first <<" " << item->second << endl;
	}
}

TEST(algo, validTree)
{
	vector<vector<int>> edges={{0,1},{0,2},{0,3},{1,4}};
	validTree(3, edges);
}


TEST(algo, under_set)
{
	unordered_set<int> a;
	a.insert(10);
	a.insert(9);
	a.insert(11);
	a.insert(2);
	a.insert(112);
	a.insert(103);

	for (auto item = a.begin(); item!= a.end(); ++item)
	{
		cout << *item << endl;
	}
}


TEST(algo, min_tree)
{
	
}

TEST(algo, priority_queue_test)
{
	vector<int> a ={1,3,2,11,4,5};
	Co_dd::priority_queue p_q(a.begin(),a.end());
	ASSERT_EQ(11, p_q.top());
	p_q.push(13);
	ASSERT_EQ(13, p_q.top());
	p_q.pop();
	ASSERT_EQ(11, p_q.top());

}