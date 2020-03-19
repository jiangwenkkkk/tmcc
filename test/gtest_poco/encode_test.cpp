//
// Created by james on 2019-11-14.
//

#include <iconv.h>
#include "gtest/gtest.h"
#include "Poco/UTF8String.h"

#include "iconv.hpp"
#include <iconv.h>

TEST(encode, list_all)
{
//	std::
;
}

//
// UTF8StringTest.cpp
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//





using Poco::UTF8;
using namespace iconvpp;
using std::string;

char sUTF8[16]; // utf8字符集
char sGBK[16]; // GBK字符集

string translateUTFtoGBK(const string &m_value)
{

	memset(sUTF8, 0, sizeof(sUTF8));
	memset(sGBK, 0, sizeof(sGBK));
	strcpy(sUTF8, "UTF-8"); // 拆用默认的
	strcpy(sGBK, "GBK"); // 拆用默认的

	int m_iValuLen = strlen(m_value.c_str());
	unsigned char *sInput = new unsigned char[m_iValuLen+1];
	unsigned char *sOutput = new unsigned char[m_iValuLen*2+1];
	memset(sInput, 0x00, m_iValuLen+1);
	memset(sOutput, 0x00, m_iValuLen*2+1);

	unsigned char *pIn = sInput;
	memcpy(sInput, m_value.c_str(), m_iValuLen);
	size_t inLen = m_iValuLen;

	unsigned char *pOut = sOutput;
	size_t outLen = m_iValuLen*2;

//		iconv_t cd = iconv_open(sUTF8,sGBK);
	iconv_t cd = iconv_open(sGBK,sUTF8);
	int* result = (int*)cd;
	if (*result <= 0)
	{
//		ERROR_LOG("创建转换描述符失败，可能是编码的名称不对。通过 iconv -l查看下所支持字符集的名称。");
	}
	// 要记住 都要换成 unsigned char *pIn作为入参传入，不要直接把数组名传入
	iconv(cd, (char**)&pIn, (size_t*)&inLen, (char**)&pOut, (size_t*)&outLen);//
	iconv_close(cd);

	string strValue((char*)sOutput);
	delete[] sInput;
	delete[] sOutput;
	return strValue;
}


string translateGBKtoUTF(const string &m_value)
{

	memset(sUTF8, 0, sizeof(sUTF8));
	memset(sGBK, 0, sizeof(sGBK));
	strcpy(sUTF8, "UTF-8"); // 拆用默认的
	strcpy(sGBK, "GBK"); // 拆用默认的

	int m_iValuLen = strlen(m_value.c_str());
	unsigned char *sInput = new unsigned char[m_iValuLen+1];
	unsigned char *sOutput = new unsigned char[m_iValuLen*2+1];
	memset(sInput, 0x00, m_iValuLen+1);
	memset(sOutput, 0x00, m_iValuLen*2+1);

	unsigned char *pIn = sInput;
	memcpy(sInput, m_value.c_str(), m_iValuLen);
	size_t inLen = m_iValuLen;

	unsigned char *pOut = sOutput;
	size_t outLen = m_iValuLen*2;

//		iconv_t cd = iconv_open(sUTF8,sGBK);
	iconv_t cd = iconv_open(sUTF8,sGBK);
	int* result = (int*)cd;
	if (*result <= 0)
	{
//		ERROR_LOG("创建转换描述符失败，可能是编码的名称不对。通过 iconv -l查看下所支持字符集的名称。");
	}
	// 要记住 都要换成 unsigned char *pIn作为入参传入，不要直接把数组名传入
	iconv(cd, (char**)&pIn, (size_t*)&inLen, (char**)&pOut, (size_t*)&outLen);//
	iconv_close(cd);

	string strValue((char*)sOutput);
	delete[] sInput;
	delete[] sOutput;
	return strValue;
}

TEST(UTF8StringTest, testCompare)
{
	std::string a1("aaaaa");
	std::string b1("bbbbb");

	assert (UTF8::icompare(a1, b1) < 0);

	std::string a2("aaaaa");
	std::string b2("BBBBB");

	assert (UTF8::icompare(a2, b2) < 0);

	std::string a3("AAAAA");
	std::string b3("bbbbb");

	assert (UTF8::icompare(a3, b3) < 0);

	std::string a4("aaaaa");
	std::string b4("AAAAA");

	assert (UTF8::icompare(a4, b4) == 0);

	std::string a5("AAAAA");
	std::string b5("bbbbb");

	assert (UTF8::icompare(a5, b5) < 0);

	std::string a6("\303\274\303\266\303\244"); // "u"o"a
	std::string b6("\303\234\303\226\303\204"); // "U"O"A

	assert (UTF8::icompare(a6, b6) == 0);
}


TEST( UTF8StringTest,testTransform)
{
	std::string s1("abcde");
	UTF8::toUpperInPlace(s1);
	assert (s1 == "ABCDE");

	std::string s2("aBcDe123");
	UTF8::toUpperInPlace(s2);
	assert (s2 == "ABCDE123");

	std::string s3("\303\274\303\266\303\244"); // "u"o"a
	UTF8::toUpperInPlace(s3);
	assert (s3 == "\303\234\303\226\303\204"); // "U"O"A
	UTF8::toLowerInPlace(s3);
	assert (s3 == "\303\274\303\266\303\244"); // "u"o"a

	// a mix of invalid sequences
	std::string str = "\xC2\xE5\xF0\xF8\xE8\xED\xFB+-++";
	assert ("???+-++" == UTF8::toLower(str));
}


TEST( UTF8StringTest,testEscape)
{
	std::string s1("A \t, a \v, and an \a walk into a |, and the barman says \xD0\x82");

	assert (UTF8::escape(s1) == "A \\t, a \\v, and an \\a walk into a |, and the barman says \\u0402");
	assert (UTF8::escape(s1, true) == "A \\t, a \\u000B, and an \\u0007 walk into a |, and the barman says \\u0402");
}


TEST (UTF8StringTest,testUnescape)
{
	std::string s1("A \\t, a \\u000B, and an \\u0007 walk into a |, and the barman says \\u0402");
	std::string s2("A \\t, a \\v, and an \\a walk into a |, and the barman says \\u0402");

	assert (UTF8::unescape(s1) == "A \t, a \v, and an \a walk into a |, and the barman says \xD0\x82");
	assert (UTF8::unescape(s2) == "A \t, a \v, and an \a walk into a |, and the barman says \xD0\x82");
}


TEST(UTF8StringTest, test_cout)
{
	std::string a1("aaaaa");
	std::string b1("bbbbb");

	assert (UTF8::icompare(a1, b1) < 0);

	std::string a2("aaaaa");
	std::string b2("BBBBB");

	assert (UTF8::icompare(a2, b2) < 0);

	std::string a3("AAAAA");
	std::string b3("bbbbb");

	assert (UTF8::icompare(a3, b3) < 0);

	std::string a4("aaaaa");
	std::string b4("AAAAA");

	assert (UTF8::icompare(a4, b4) == 0);

	std::string a5("AAAAA");
	std::string b5("bbbbb");

	assert (UTF8::icompare(a5, b5) < 0);

	std::string a6("\303\274\303\266\303\244"); // "u"o"a
	std::string b6("\303\234\303\226\303\204"); // "U"O"A
	std::string c6("\u7684\u4e00\u4e86\u662f\u6211\u4e0d\u5728\u4eba\u4eec\u6709\u6765\u4ed6\u8fd9\u4e0a\u7740\u4e2a\u5730\u5230\u5927\u91cc\u8bf4");
	assert (UTF8::icompare(a6, b6) == 0);

	std::cout << Poco::UTF8::unescape("\u7684") << std::endl;
	std::cout << Poco::UTF8::unescape("\u5927;\u5E08;\u5085;") << std::endl;
	std::string d6 = Poco::UTF8::unescape("\u7684");
	std::string ch = "的";
	std::cout << ch << std::endl;
	char b[20] = {0};
	int* a = (int*)d6.c_str();
	memcpy(b, d6.c_str(), d6.size());
	memcpy(b, ch.c_str(), ch.size());


	std::cout<< "0X" << *a << std::endl;

}

TEST(iconv, trivial) {
	converter conv("EUC-JP", "UTF-8");
	string in = "hello iconv";
	string out;
	conv.convert(in, out);
	EXPECT_EQ(in, out);

	in = "今日は天?だ";
	converter reconv("UTF-8", "EUC-JP");
	conv.convert(in, out);
	string out2;
	reconv.convert(out, out2);
	EXPECT_EQ(in, out2);

	in = "你好";
	converter togbk("UTF-8", "GBK");
	togbk.convert(in,out);


}
TEST(iconv, trivial_with_hpp) {
//	converter conv("EUC-JP", "UTF-8");
//	string in = "hello iconv";
//	string out;
//	conv.convert(in, out);
//	EXPECT_EQ(in, out);
//
//	in = "今日は天?だ";
//	converter reconv("UTF-8", "EUC-JP");
//	conv.convert(in, out);
//	string out2;
//	reconv.convert(out, out2);
//	EXPECT_EQ(in, out2);

	string in = "测试";
//	string in = "的";
//	string out = translateUTFtoGBK(in);

//	converter togbk("UTF-8", "GBK");
	converter togbk("GBK", "UTF-8");
	string out;
	togbk.convert(in,out);

	std::cout << out << std::endl;
	std::cout << in << std::endl;

	char b[20] = {0};
	memcpy(b, out.c_str(), out.size());
	char f[20] = {0};
	memcpy(f, in.c_str(), in.size());

	int c = 0xc4b5;
	char e[20]={0};
	memcpy(e, &c, 4);

	std::cout << e << std::endl;

}

TEST(iconv, trivial2) {
//	converter conv("EUC-JP", "UTF-8");
//	string in = "hello iconv";
//	string out;
//	conv.convert(in, out);
//	EXPECT_EQ(in, out);
//
//	in = "今日は天?だ";
//	converter reconv("UTF-8", "EUC-JP");
//	conv.convert(in, out);
//	string out2;
//	reconv.convert(out, out2);
//	EXPECT_EQ(in, out2);

	string in = "的";
	string out = translateUTFtoGBK(in);

//	converter togbk("UTF-8", "GBK");
//	string out;
//	togbk.convert(in,out);

	std::cout << out << std::endl;
	std::cout << in << std::endl;

	char b[20] = {0};
	memcpy(b, out.c_str(), out.size());
	char f[20] = {0};
	memcpy(f, in.c_str(), in.size());

	int c = 0xc4b5;
	char e[20]={0};
	memcpy(e, &c, 4);

	std::cout << e << std::endl;

}



TEST(iconv, large) {
	converter conv("EUC-JP", "UTF-8");
	string in = string(2048, 'a');
	string out;
	conv.convert(in, out);
	EXPECT_EQ(in, out);
}

TEST(iconv, unsupported) {
	EXPECT_THROW(converter("unknown", "UTF-8"), std::runtime_error);
	EXPECT_THROW(converter("UTF-8", "unknown"), std::runtime_error);
}

TEST(iconv, invalid) {
	converter conv("UTF-8", "EUC-JP");
	string out;
	EXPECT_THROW(conv.convert("あ", out), std::runtime_error);
}

TEST(iconv, ignore_error) {
	converter conv("UTF-8", "EUC-JP", true);
	string out;
	EXPECT_NO_THROW(conv.convert("あ", out));
}

TEST(iconv, zero_buffer) {
	EXPECT_THROW(converter("UTF-8", "EUC-JP", false, 0), std::runtime_error);
}

TEST(sprintf_gbk, t)
{

}



