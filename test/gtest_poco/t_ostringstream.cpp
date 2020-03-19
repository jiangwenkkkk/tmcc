//
// Created by james on 2019-02-19.
//

#include <gtest.h>
#include <ostream>
#include <sstream>


TEST(o_s,t)
{
	std::ostringstream a;
	a << "a" << "tom" << "a";
	std::cout << a.str();
}

TEST(stream_t, to_int)
{
	int a;
	std::cin >> a;
	std::cout << a << std::endl;
}

TEST(string_stream,t)
{
	std::stringstream str;
	str << "hello world\nhello\n";
	std::cout << str.str();
	char tmp_str[200]={0};
	while (str.getline(tmp_str, 200))
	{
		printf("%s",tmp_str);
	}

}
