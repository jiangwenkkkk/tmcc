//
// Created by james on 2019-11-17.
//

//
// Created by james on 2019-10-28.
//


#include <iostream>
#include "Poco/Task.h"
#include "Poco/Thread.h"
#include "Poco/AutoPtr.h"
#include "Poco/TaskManager.h"



#include <stdlib.h>
#include <iostream>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <Poco/Mutex.h>
#include "../gtest_poco/iconv.hpp"


static Poco::FastMutex   _mutex;

using namespace std;




int main() {

	cout << "Let's have MySQL count from 10 to 1..." << endl;

	try {
		sql::Driver *driver;
		Poco::SharedPtr<sql::Connection > con;
		sql::Statement *stmt;
//		sql::Statement *stmta;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;
		sql::PreparedStatement *stmta;
		sql::PreparedStatement *stmtb;

		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "55668899");
		/* Connect to the MySQL test database */
		con->setSchema("bill_test");
//		con->setSchema("test_sql");


		stmta = con->prepareStatement("set names utf8");
//		stmta = con->prepareStatement("set names gbk");
//		stmta = con->prepareStatement("set names utf8");
//		stmta = con->prepareStatement("set names latin1");
		stmta->execute();
		delete stmta;


//		stmt = con->createStatement();
//		stmt->execute("DROP TABLE IF EXISTS test");
////		stmt->execute("CREATE TABLE test(id INT, name varchar(20) null  CHARSET=utf8)ENGINE=InnoDB DEFAULT CHARSET=utf8");
////		stmt->execute("CREATE TABLE test(id INT, name varchar(20) null)");
//		stmt->execute("CREATE TABLE test(id INT, name varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci)");
////		stmt->execute("CREATE TABLE test(id INT, name varchar(20) CHARACTER SET GBK COLLATE gbk_chinese_ci)CHARACTER SET utf8 COLLATE utf8_general_ci");
//
//		delete stmt;



//		stmtb = con->prepareStatement("show variables like '%char%'");
////		stmta = con->prepareStatement("set names gbk");
////		stmta = con->prepareStatement("set names utf8");
//		res = stmtb->executeQuery();
//		while (res->previous())
//		{
////			Poco::FastMutex::ScopedLock lock(::_mutex);
//			cout << "\t... aMySQL counts: " << res->getString("Varibale_name") <<": " <<  res->getString("Value") << endl;
////			tmp = res->getString("name");
////			togbk.convert(tmp,out);
////			std::cout << out << std::endl;
//		}

//		delete stmtb;
//		delete res;


		/* '?' is the supported placeholder syntax */
//		string in = "的";
//		pstmt = con->prepareStatement("INSERT INTO test(id,name) VALUES (?,?)");
//		for (int i = 1; i <= 10; i++) {
//			std::cout << in << std::endl;
//			pstmt->setInt(1, i);
//			pstmt->setString(2,in);
//			pstmt->executeUpdate();
//		}
//		delete pstmt;

//		Poco::Thread b;
//		Poco::AutoPtr<SimpleTask> a(new SimpleTask(con));
//		SimpleTask c(con);
//		b.start(c);
//		b.join();

		/* Select in ascending order */
		pstmt = con->prepareStatement("SELECT id, name FROM test ORDER BY id ASC");
		res = pstmt->executeQuery();

		/* Fetch in reverse = descending order! */
		res->afterLast();
		string tmp;
//		iconvpp::converter togbk("UTF-8", "GBK");
		string out;


		while (res->previous())
		{
//			Poco::FastMutex::ScopedLock lock(::_mutex);
			cout << "\t... aMySQL counts: " << res->getInt("id") <<": " <<  res->getString("name") << endl;
			tmp = res->getString("name");
//			togbk.convert(tmp,out);
			std::cout << out << std::endl;
		}


		delete res;

		delete pstmt;

//		delete con;

	} catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line "
			 << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() <<
			 " )" << endl;
	}

	cout << endl;


	return EXIT_SUCCESS;

}
