//
// Created by james on 2019-05-30.
//

#include <gtest.h>
#include <array>
#include <regex>
#include <queue>
#include "fun.h"
#include <deque>



TEST(l_f, t) {
	vector<string> l1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
	vector<string> l2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};

	vector<string> a = findRestaurant(l1, l2);
	for (auto item : a) {
		cout << item << endl;
	}
	std::cout << "hell" << std::endl;
}



TEST(a, t) {
	char p[] = "hell";
	char z[] = "hell";
	char const *a = p;
	char *const b = p;
	*b = 'a';
	cout << sizeof(p) << endl;
	cout << sizeof(p + 1) << endl;
	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;
	printf("%s", p);
//	Bit rmode:2;
//	b =z;
//	*a = 'a';

}


TEST(a, b) {
	UnionTest u;

	union {
		int i;
		double d;
	};

	std::cout << u.i << std::endl;

	::i = 20;
	std::cout << ::i << std::endl;

	i = 30;
	std::cout << i << std::endl;

}


TEST(e, t) {
	A a1(1);
	A a2 = 1;
	A a3{1};
	A a4 = {1};
	A a5 = (A) 1;
	doA(1);
	if (a1);
	bool a6（a1）;
	bool a7 = a1;
	bool a8 = static_cast<bool>(a1);
	B b1(1);
	//B b2 = 1;
	B b3{1};
//	B b4 = { 1 };
//	B b5 = (B)1;
	doB(static_cast<B>(1));
	if (b1);
	bool b6(b1);
//	bool b7 = b1;
	bool b8 = static_cast<bool>(b1);

}



TEST(t_s, t) {
	unique_ptr<int> a(new int(10));
	unique_ptr<test_unit> b(new test_unit());
//	unique_ptr<test_unit>c=b;
//	cout << *a << endl;

}






TEST(s_t, t) {
//	array<int>zzz;


	int a = 0xab5f;
	int *c = &a;
	char d = 'a';
	char *e = &d;
//	c = static_cast<int*>(e);
//	e = static_cast<char*>(c);
	char b = static_cast<char>(a);
	cout << a << b << "a " << "a" << endl;
	typeid(c);
}


TEST(ar, t) {
	std::array<int, 5> myarray = {2, 16, 77, 34, 50};
	std::cout << "myarray contains:";
	for (auto it = myarray.begin(); it != myarray.end(); ++it)
		std::cout << ' ' << *it << endl;
	std::cout << '\n';

}



TEST(get_num, t) {
	cout << char_nums(10);
}

TEST(tm, t) {
	std::string s = "Some people, when confronted with a problem, think "
					"\"I know, I'll use regular expressions.\" "
					"Now they have two problems.";

	std::regex self_regex("REGULAR EXPRESSIONS",
						  std::regex_constants::ECMAScript | std::regex_constants::icase);
	if (std::regex_search(s, self_regex)) {
		std::cout << "Text contains the phrase 'regular expressions'\n";
	}

	std::regex word_regex("(\\S+)");
	auto words_begin =
			std::sregex_iterator(s.begin(), s.end(), word_regex);
	auto words_end = std::sregex_iterator();

	std::cout << "Found "
			  << std::distance(words_begin, words_end)
			  << " words\n";

	const int N = 6;
	std::cout << "Words longer than " << N << " characters:\n";
	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
		std::smatch match = *i;
		std::string match_str = match.str();
		if (match_str.size() > N) {
			std::cout << "  " << match_str << '\n';
		}
	}

	std::regex long_word_regex("(\\w{7,})");
	std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
	std::cout << new_s << '\n';
}

TEST(rs, t) {
	string a = "0000"
			   "tm0";
	regex d("0");

	smatch sm;
	while (regex_search(a, sm, d)) {
		cout << sm.str() << endl;
		a = sm.suffix();
	}
}



TEST(t_have, t_nums) {
	cout << have_ke(10, 1);
	cout << have_ke(0, 0);
}



TEST(get_ugly, t) {
	cout << nthUglyNumber(1);
}



TEST(find_biggest, qt) {
	vector<int> a{1, 323, 13, 14, 11, 3, 1134214, 123, 421};
	cout << find_biggest(a, 3);
}

TEST(find_biggest, qtb) {
	cout << "e";
}

TEST(local, merage_t) {
	vector<int> a = {1};
	vector<int> b = {1};
	auto c = merage(b, a);
	for (auto item : c) {
		cout << item << endl;
	}
}




TEST(jiuzhang, tree_ser_de)
{
	string tree_ser = "3,9,20,#,#,15,7";
	auto tree = deserialize(tree_ser);

	string str = serialize(tree);
}


TEST(algo, fib)
{
	EXPECT_EQ(1, fib(1));
	EXPECT_EQ(1, fib(2));
	EXPECT_EQ(5, fib(5));
	ASSERT_EQ(8, fib(6));
}

TEST(algo, map_t)
{
	map<int, int> a;
	a.insert(make_pair(1, 101));
	cout << a[1] << endl;

	char ab[4];
	sprintf(ab, "%04d", 1);
	cout << ab;
}

TEST(algo, queue_t)
{
	std::queue<int> a;
	for (int i = 0; i < 10; ++i) {
		a.push(i);
	}

	for (int j = 0; j < 10; ++j) {
		cout << a.front() << endl;
		a.pop();
	}
}

TEST(t,def)
{
#if ABCdaa
	cout << "hello" << endl;
#endif
	cout << "a" << endl;
}

TEST(fun, atoll_t)
{
	std::cout << atoll("")<<endl;
}