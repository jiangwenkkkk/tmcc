#ifndef MY_AUDIT_MAIN
#define MY_AUDIT_MAIN

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>


#include "Poco/Task.h"
#include "Poco/DateTime.h"
#include "Poco/Timestamp.h"
#include "Poco/Exception.h"
#include "Poco/Foundation.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/LocalDateTime.h"
#include "Poco/FileStream.h"
#include "Poco/Util/Application.h"
#include "Poco/StringTokenizer.h"
#include "Poco/NumberFormatter.h"
#include "Poco/File.h"

#define MAX_HOME_AREA_CODE 1000

namespace audit {

using namespace std;
using Poco::FileStream;
using Poco::Task;

typedef struct _AuditInfo {
	string fileNameRecv;
	string fileTimeRecv;
	int recCntRecv;
	int errCntRecv;
	string fileNameTrans;
	string fileTimeSend;
	int recCntSend;
} AuditInfo;
/// 稽核信息点信息单条记录结构

class AuditMain {
public:
	AuditMain(Task* owner);
	AuditMain(){
		tmpFileName.clear();
		tmpFile.clear();
		fileRecCnt.clear();
//    _partiOffset.clear();
		createTime.clear();
		openTime.clear();
		commitFileName.clear();
		fileindex.clear();
		filesplit.clear();
		memset(areaMap, -1, sizeof(areaMap));
		memset(fileArea, -1, sizeof(fileArea));}
	virtual ~AuditMain();

	void start();
	/// 启动流程

private:
	bool loadDependent(const Poco::Util::AbstractConfiguration& config);
	/// 加载依赖参数
	
	bool createTempFile(const string& tempDir, const string& strHomeAreaCode);
	/// 创建临时文件, 建立文件名和归属省映射关系

	bool reOpenTempFile();
	/// 重新打开临时文件，不变动文件名和归属省映射关系

	bool writeOneRecord();
	/// 从kafka里消费一条信息写入到文件中

    string acquireNewFileName(int index, bool isExpired);

    bool createFormalFile(const string& tempDir, int index, bool isExpired);
    /// 重命名正式文件

	bool expired(int& cnt, Poco::Timestamp& now);
	/// 超过提交时间

	int Submit();
	/// 关闭文件, 提交

	bool parseString2AuditInfo(string& data, AuditInfo& info);
	/// 将proto string转成结构体

	bool formatString4AuditInfo(AuditInfo& info, string& output, int& index);
	// 将AuditInfo结构转成输出字符串和文件index

private:
	Task * _pOwner;
//	CFileManage* fileManage;	//负责文件提交，获取partition偏移
//	AuditLogAlert* auditLogAlert; //负责日志提交
	vector<string> tmpFileName;	//记录所有临时文件名
	vector<FileStream*> tmpFile; //记录所有临时文件流
	vector<int> fileRecCnt; //记录每个临时文件记录数
	vector<int> fileindex; //记录每个临时文件正在处理的序号, -1表示未使用
	vector<int> filesplit; //记录每个临时文件分割序号
	vector<std::time_t> createTime; //记录每个临时文件第一条记录时间
	vector<std::time_t> openTime; //记录每个临时文件打开时间
	vector<string> commitFileName; //记录所有正式文件名
//	vector<audit::partitionOffset> _partiOffset; //记录每个分区的开始和结束偏移
	string _instId;  //记录flowId_programId_instanceId
    string _tempDir; //记录运行临时文件目录
	int areaMap[MAX_HOME_AREA_CODE]; // 根据省份码找到文件index
	int fileArea[MAX_HOME_AREA_CODE]; // 根据文件index找到省份码
	int timeInterval; //上传分钟间隔, 取值[1-60]
	int lastMinute; //上一次分钟点
//	KafkaConsumer::Ptr mpConsumer; // kafka消费者
};

}
#endif
