//
// Created by james on 2019-12-10.
//

#include <gtest.h>

TEST(hex_t,move_left)
{
	char a = 155;
	std::cout << a << std::endl;
	char d = a>>1;
	char c = a>>2;
	char b = a>>4;

	std::cout << b << std::endl;
}

TEST(hex_t,move_left_a)
{
	int a = 1;
	std::cout << a << std::endl;
	int c = a>>2;
	std::cout << c << std::endl;
	int b = a>>4;
	std::cout << b << std::endl;
	int d = a << 2;
	std::cout << d << std::endl;
}

TEST(hex_char,move_left_a)
{
	char a = 1;
	std::cout << a << std::endl;
	char e = a>>2;
	std::cout << e << std::endl;
	char c = a>>2;
	std::cout << c << std::endl;
	char b = a>>4;
	std::cout << b << std::endl;
	char d = a << 2;
	std::cout << d << std::endl;
}


TEST(hex_char_first_is_o,move_left_a)
{
	char a = 128;
	std::cout << a << std::endl;
	char e = a>>2;
	std::cout << e << std::endl;
	char c = a>>2;
	std::cout << c << std::endl;
	char b = a>>4;
	std::cout << b << std::endl;
	char d = a << 2;
	std::cout << d << std::endl;
}

TEST(hex_char_first_is_1,move_left_a)
{
	char a = 1;
	std::cout << a << std::endl;
	char e = a<<1;
	std::cout << e << std::endl;
	char c = a<<2;
	std::cout << c << std::endl;
	char b = a<<4;
	std::cout << b << std::endl;
	char d = a << 2;
	std::cout << d << std::endl;
}



TEST(hex_char_first_is_o,move_right_a)
{
	char a = 128;
	std::cout << a << std::endl;
	char e = a<<1;
	std::cout << e << std::endl;
	char c = a<<2;
	std::cout << c << std::endl;
	char b = a<<4;
	std::cout << b << std::endl;
	char d = a << 2;
	std::cout << d << std::endl;
}

TEST(hex_char_first_is_1,move_right_a)
{
	char a = 129;
	std::cout << a << std::endl;
	char e = a<<1;
	std::cout << e << std::endl;
	char c = a<<2;
	std::cout << c << std::endl;
	char b = a<<4;
	std::cout << b << std::endl;
	char d = a << 2;
	std::cout << d << std::endl;
}

/*
 * http://www.86duino.com/?p=1413&lang=TW
 * 这个测试理解了位移的时候,右位移会需要判断首位是否是符号位
 * */

TEST(hex_unsignedchar_first_is_1,move_right_a)
{
	unsigned char a = 129;
	std::cout << a << std::endl;
	char e = a>>2;
	std::cout << e << std::endl;
	char c = a>>2;
	std::cout << c << std::endl;
	char b = a>>4;
	std::cout << b << std::endl;
	char d = a << 2;
	std::cout << d << std::endl;
}