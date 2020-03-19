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


static Poco::FastMutex   _mutex;

class SimpleTask :public Poco::Task
{
public:
	SimpleTask(Poco::SharedPtr<sql::Connection > connection, int id):_connection(connection),_id(id), Task("simple"){}
	void runTask()
	{
while(!isCancelled())
		std::cout << __FUNCTION__ << std::endl;
//		sleep(2000);
//		Poco::SharedPtr<sql::PreparedStatement> stmt;// = _connection->prepareStatement("SELECT id FROM test ORDER BY id ASC");
//
//		stmt = _connection->prepareStatement("SELECT id FROM test ORDER BY id ASC");
//		int count = 0;
//		while(!isCancelled())
//		{
//
//			Poco::SharedPtr<sql::ResultSet>res = stmt->executeQuery();
//
//			res->afterLast();
//			while (res->previous())
//			{
////				Poco::FastMutex::ScopedLock lock(::_mutex);
//				std::cout << "\t... bMySQL counts: " << res->getInt("id") << std::endl;
//				std::cout << _id << std::endl;
//
//
//			}
//			if (count == 20)
//			{
//				cancel();
//			}
//			count++;
//
//		}
//		std::cout << "hello" << std::endl;
//




	}

private:
	Poco::SharedPtr<sql::Connection > _connection;
	int _id;
};
using namespace std;




int main() {



	cout << endl;
	cout << "Let's have MySQL count from 10 to 1..." << endl;

	try {
		sql::Driver *driver;
		Poco::SharedPtr<sql::Connection > con;
		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "55668899");
		/* Connect to the MySQL test database */
		con->setSchema("bill_test");





		stmt = con->createStatement();
		stmt->execute("DROP TABLE IF EXISTS test");
		stmt->execute("CREATE TABLE test(id INT)");

		delete stmt;



		/* '?' is the supported placeholder syntax */
		pstmt = con->prepareStatement("INSERT INTO test(id) VALUES (?)");
		for (int i = 1; i <= 10; i++) {
			pstmt->setInt(1, i);
			pstmt->executeUpdate();
		}
		delete pstmt;

//		Poco::Thread b;
//		Poco::AutoPtr<SimpleTask> a(new SimpleTask(con));
//		SimpleTask c(con);
//		b.start(c);
//		b.join();

		Poco::TaskManager tm;
		tm.start(new SimpleTask(con,1));
//		tm.start(new SimpleTask(con,2));


		/* Select in ascending order */
		pstmt = con->prepareStatement("SELECT id FROM test ORDER BY id ASC");
		res = pstmt->executeQuery();

		/* Fetch in reverse = descending order! */
		res->afterLast();
		while (res->previous())
		{
//			Poco::FastMutex::ScopedLock lock(::_mutex);
			cout << "\t... aMySQL counts: " << res->getInt("id") << endl;
		}

		delete res;

		delete pstmt;

		tm.cancelAll();
		sleep(1);
		tm.joinAll();
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
