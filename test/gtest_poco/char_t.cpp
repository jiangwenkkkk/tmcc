//
// Created by james on 2019-04-18.
//

#include <gtest.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

TEST(show_char, behind)
{
	char* p = "hello";
	char* z = p+4;
	std::cout << *z << std::endl;
	std::cout << z[-1] << std::endl;
}

TEST(show_char,can_not_see)
{
	std::string a= "898\tLNIG898\tLNIGid571\t531 5";
	std::cout << a;
}

TEST(enum_t,print_val)
{
	enum a{B,C};
	std::cout << B << std::endl;
	std::cout << C << std::endl;
}

TEST(sql_concat, t)
{
	vector <string> m_TableCheckName = {};
	vector <string> m_TableColumnName = {"BSID"           ,
										 "CIBER_CTRY_CD"  ,
										 "PROV"           ,
										 "CARRIER_CD"     ,
										 "EFF_DATE"       ,
										 "EXP_DATE"       ,
										 "OPEN_MODE"      ,
										 "UPDATE_TIME"    ,
										 "MODIFIER"       ,
										 "AUDIT_TIME"     ,
										 "AUDITOR"        , };
	vector <int>    m_iFlag ={0,
							  0,
							  0,
							  0,
							  1,
							  1,
							  0,
							  1,
							  0,
							  1,
							  0};

	std::string sql = "select sum(get_hash_value_md5(";
	for (int i = 0; i < m_TableColumnName.size(); ++i) {
		if (m_iFlag[i])
			sql += "to_char(" + m_TableColumnName[i] + ", 'yyyymmddhh24miss')";
		else
			sql += m_TableColumnName[i];
		if (i < m_TableColumnName.size() - 1) sql += "||'#'||";
	}
	sql += " )) from bsid";
	std::cout << sql << std::endl;
//	sql += " )) from " + m_TableName[i];
}

TEST(sql_concat_b_code, t)
{
	vector <string> m_TableCheckName = {};
	vector <string> m_TableColumnName = {"HCODE_ID",
"TSP_ID",
"AREA_CODE",
"VALID_TIME",
"ELAPSE_TIME",
"UPDATE_TIME",
"MODIFIER",
"AUDIT_TIME",
"AUDITOR"
 };
	vector <int>    m_iFlag ={0,
							  0,
							  0,
							  1,
							  1,
							  1,
							  0,
							  1,
							  0};

	std::string sql = "select sum(get_hash_value_md5(";
	for (int i = 0; i < m_TableColumnName.size(); ++i) {
		if (m_iFlag[i])
			sql += "to_char(" + m_TableColumnName[i] + ", 'yyyymmddhh24miss')";
		else
			sql += m_TableColumnName[i];
		if (i < m_TableColumnName.size() - 1) sql += "||'#'||";
	}
	sql += " )) from tp_hcode";
	std::cout << sql << std::endl;
//	sql += " )) from " + m_TableName[i];
}

TEST(filecheck, 281_t)
{
//	string checkFileRecord::checkF281(string& TimeofRepot) {
//	return "0";
//		static int count = 0;
//		static int current_month = _divide_month;
//
//		if (count < 10000)
//		{
//			count++;
//		} else
//		{
//			Poco::DateTime a;
//			current_month = a.month();
//			count = 0;
//		}
//
//		int month =  std::stoi(TimeofRepot.substr(4,2));
//
//		if (month == current_month||month == (current_month+1)%12)
////			return "0";
//
//		if (month == _divide_month)
////			return "0";
//
////		return F281;
////	}
}