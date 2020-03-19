//
// Created by james on 2019-03-09.
//

#include <gtest.h>
#include <map>
#include <string>
#include <functional>
#include <unordered_map>
#include <vector>

using std::map;


TEST(map, t)
{
	map<int, std::string>b;
//	b.insert(std::make_pair(1, "hello"));
	b[10] = "hello";
	b[11] = "tom";
	b[1] ="zk";
	b[21] = "zook";
	b[32] = "tom";

	for(auto item = b.begin(); item != b.end(); ++item)
	{
		std::cout << (*item).first << "->" << (*item).second << std::endl;
	}
}

TEST(unorder_map, t)
{
	std::unordered_map<int, std::string> b;
	b[10] = "hello";
	b[11] = "tom";
	b[21] = "zook";
	b[32] = "tom";

	for(auto item = b.begin(); item != b.end(); ++item)
	{
		std::cout << (*item).first << "->" << (*item).second << std::endl;
	}
}


TEST(ve, t)
{
	std::vector<int> a={1,2,3,4,5,6,7};

	for (auto iter = a.begin(); iter != a.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

	for (auto iter = a.rbegin(); iter != a.rend(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

}


TEST(t_t, t)
{
	printf("%d", 'B');
	printf("%d", 'b');
	printf("%d", 'a');
}
