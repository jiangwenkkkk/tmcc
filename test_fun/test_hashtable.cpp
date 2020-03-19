//
// Created by james on 2019-04-29.
//

#include <gtest.h>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

TEST(hash_t, t)
{
	std::unordered_map<std::string, std::string> a;
	a.insert({"hello", "helloa"});
	a.insert({"hell", "helloa"});
	a.insert({"hel", "helloa"});
	a.insert({"he", "helloa"});
	a.insert({"h", "helloa"});



//	std::unordered_map<int, std::string> a;
//	a.insert({1, "helloa"});
////	a.insert("hell", "helloa");
////	a.insert("hel", "helloa");
////	a.insert("he", "helloa");
////	a.insert("h", "helloa");

	for(auto tm : a)
	{
		cout << tm.first << "=>" << tm.second << endl;
	}
}

