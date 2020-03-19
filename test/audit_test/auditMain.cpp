#include "auditMain.h"

namespace audit {

#define HandleError(result, str) \
    if (!(result)) { \
        FLOG << str << ENDL; \
        if (auditLogAlert != NULL) \
            auditLogAlert->insertAlert(2, str); \
        throw Poco::Exception(str); \
	}

using Poco::Timestamp;
using Poco::DateTime;
using Poco::LocalDateTime;
using Poco::DateTimeFormatter;
using Poco::NumberFormatter;
using Poco::File;

std::string fromEpochTime(std::time_t t)
{
	DateTime dt(Timestamp::fromEpochTime(t)); // Timestamp > DateTime
	LocalDateTime ldt(dt); // DateTime > LocalDateTime
	string fmt = "%Y%m%d%H%M%S"; // YYYYMMDDHH24MISS
	return DateTimeFormatter::format(ldt, fmt); // 目标格式
}

AuditMain::AuditMain(Task* owner)
{
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
	memset(fileArea, -1, sizeof(fileArea));
}

AuditMain::~AuditMain()
{
	// 释放vector内存
	if (tmpFileName.size()) {
		tmpFileName.clear();
		vector<string>(tmpFileName).swap(tmpFileName);
	}
	// 释放Filebuf以及vector
	if (tmpFile.size()) {
		for (auto it = tmpFile.begin(); it != tmpFile.end(); it++) {
			(*it)->close();
			delete *it;
		}
		tmpFile.clear();
		vector<FileStream*>(tmpFile).swap(tmpFile);
	}
	if (fileRecCnt.size()) {
		fileRecCnt.clear();
		vector<int>(fileRecCnt).swap(fileRecCnt);
	}
    if (commitFileName.size()) {
        commitFileName.clear();
        vector<string>(commitFileName).swap(commitFileName);
    }
    if (fileindex.size()) {
        fileindex.clear();
        vector<int>(fileindex).swap(fileindex);
    }
    if (filesplit.size()) {
        filesplit.clear();
        vector<int>(filesplit).swap(filesplit);
    }
//    if (_partiOffset.size()) {
//        _partiOffset.clear();
//        vector<audit::partitionOffset>(_partiOffset).swap(_partiOffset);
//    }
	if (createTime.size()) {
		createTime.clear();
		vector<std::time_t>(createTime).swap(createTime);
	}
	if (openTime.size()) {
		openTime.clear();
		vector<std::time_t>(openTime).swap(openTime);
	}
//	if (fileManage != NULL) {
//		delete fileManage;
//		fileManage = NULL;
//	}
//    if (auditLogAlert != NULL) {
//        delete auditLogAlert;
//        auditLogAlert = NULL;
//    }
//	// 释放comsumer对象
//	if (mpConsumer != NULL)
//		mpConsumer = NULL;
}

void AuditMain::start()
{
	// 获取配置
//	auto& app = Poco::Util::Application::instance();
//    const auto& config = app.config();
	string str = "load dependent components error. ";
//	if(!loadDependent(config)) {
//		if (fileManage == NULL)
//			str = str + "filemange is null";
//		else if (mpConsumer == NULL)
//			str = str + "mpConsumer is null";
//		FLOG << str << ENDL;
//		if (auditLogAlert != NULL)
//			auditLogAlert->insertAlert(2, str);
//		throw Poco::Exception(str);
//   	}
//	// 根据归属省代码创建临时文件
//    const auto& strHomeAreaCode = config.getString(audit_conf::HOME_AREA_CODE);
//	string tempDir = config.getString(audit_conf::TEMP_DIR);
//	str = "create temp file fail. tmpdir:";
//    if(!createTempFile(tempDir, strHomeAreaCode)) {
//		str = str + _tempDir;
//		FLOG << str << ENDL;
//		if (auditLogAlert != NULL)
//			auditLogAlert->insertAlert(2, str);
//		throw Poco::Exception(str);
//   	}
//
//    // 默认10次消费后开始判断超时
    int cnt = 9;
	Timestamp now;
//    timeInterval = config.getInt(audit_conf::SUBMISSION_TIME_INTERVAL);
	/// timeInterval不能为0, 后对它有取模
	timeInterval = timeInterval % 60;
	timeInterval = (timeInterval == 0)? 60 : timeInterval;
	timeInterval = 60;

//	DLOG << "Time interval: " << timeInterval << ENDL;

    while(true) {
		str = "open temp file fail. tmpdir:" + _tempDir;
//        HandleError(reOpenTempFile(), str);
		while (true) {
//			if (!writeOneRecord()) {
////				FLOG << "write temp file fail" << ENDL;
//                //auditLogAlert->insertAlert(2, "write temp file fail");
//				//throw Poco::Exception("write temp file fail");
//			}
			if(expired(cnt, now)) {
                for (int i = 0; i < tmpFile.size(); i++) {
                    if (fileRecCnt[i] > 0) {
                        //*tmpFile[i] << "]"; //before submit, need to add tail
                        str = "create formal file fail. Files:";
						if (!(createFormalFile(_tempDir, i, true))) {
							for (int i = 0; i < commitFileName.size(); i++) {
								str = str + commitFileName[i];
								str = str + ",";
							}
//							FLOG << str << ENDL;
//							if (auditLogAlert != NULL)
//								auditLogAlert->insertAlert(2, str);
							throw Poco::Exception(str);
						}
                    }
                }
				str = "submit temp file fail. tmpdir:" + _tempDir;
//				HandleError((0 == Submit()), str);
		    	break;
    		}
		}
    }
	if (true) {
		///正常停进程, 将未提交的部分提交
		for (int i = 0; i < tmpFile.size(); i++) {
            if (fileRecCnt[i] > 0) {
                //*tmpFile[i] << "]"; //before submit, need to add tail
                str = "create formal file fail. Files:";
				if (!(createFormalFile(_tempDir, i, true))) {
					for (int i = 0; i < commitFileName.size(); i++) {
						str = str + commitFileName[i];
						str = str + ",";
					}
//					FLOG << str << ENDL;
//					if (auditLogAlert != NULL)
//						auditLogAlert->insertAlert(2, str);
					throw Poco::Exception(str);
				}
            }
        }
		str = "submit temp file fail. tmpdir:" + _tempDir;
//		HandleError((0 == Submit()), str);
	}
}

bool AuditMain::loadDependent(const Poco::Util::AbstractConfiguration& config)
{
//    int flowId, programId, instanceId;
//    string bolName, broker, topic, idepDir, redis, passwd, bpDir;
//    try {
//        bolName = config.getString( audit_conf::BOLNAME );
//        flowId = config.getInt( audit_conf::FLOW_ID );
//        programId = config.getInt( audit_conf::PROGRAM_ID );
//        instanceId = config.getInt( audit_conf::INSTANCE_ID );
//
//        ILOG << "get info from bol. bolName:" << bolName << ", flowId:" <<
//            flowId << ", programId:" << programId << ", instanceId" << ENDL;
//
//        _instId = Poco::format("%d_%d_%d",flowId, programId, instanceId);
//        auditLogAlert = new AuditLogAlert(_instId, bolName);
//        if (!auditLogAlert->init()) {
//            ELOG << "cannot init LogAlert module" << ENDL;
//            return false;
//        }
//
//        broker = config.getString(audit_conf::TASK_MQDESC);
//        topic = config.getString(audit_conf::TASK_TOPIC);
//        idepDir = config.getString(audit_conf::IDEP_DIR);
//        redis = config.getString(audit_conf::REDIS_ADDRS);
//        passwd = config.getString(audit_conf::REDIS_PASS);
//        bpDir = config.getString(audit_conf::BP_DIR);
//    } catch (Poco::Exception& pe) {
//        ELOG << "config get failed: " << pe.displayText() << ENDL;
//        return false;
//    }
//	fileManage = new CFileManage(AUDITMOD, const_cast<char*>(idepDir.c_str()), const_cast<char*>(broker.c_str()),
//		const_cast<char*>(topic.c_str()), const_cast<char*>(_instId.c_str()),
//		const_cast<char*>(redis.c_str()), const_cast<char*>(passwd.c_str()), const_cast<char*>(bpDir.c_str()));
//
//    TopicPartitionOffsetVec topicPartitionOffsets;
//	Poco::StringTokenizer partiTok(config.getString(audit_conf::PARTITION_IN),
//		"#", Poco::StringTokenizer::TOK_IGNORE_EMPTY );
//    for ( auto it = partiTok.begin(); it != partiTok.end(); ++ it ) {
//        TopicPartitionOffset of;
//        audit::partitionOffset parOf;
//        of.topic = topic;
//        std::stringstream( *it ) >> of.partition;
//
//        // 获取消费断点
//        if ( fileManage->GetTopicOffSet( topic.c_str(), of.partition, of.offset ) == 0 ) {
//            of.offset += 1;
//        } else {
//        	// 找不到从头开始
//            of.offset = RdKafka::Topic::OFFSET_BEGINNING;
//        }
//		DLOG << "consumed topic: " << topic
//             << ", partition: " << of.partition
//             << ", offset: " << of.offset << ENDL;
//        parOf.partition = of.partition;
//        parOf.beginOffset = of.offset;
//        parOf.endOffset = RdKafka::Topic::OFFSET_END;
//        _partiOffset.push_back(parOf);
//        topicPartitionOffsets.push_back(of);
//    }
//    mpConsumer = BolKafkaFactory<>(topicPartitionOffsets).createConsumer();
//    if (mpConsumer == nullptr) {
//        return false;
//    }

	return true;
}

bool AuditMain::createTempFile(const string& tempDir, const string& strHomeAreaCode)
{
//    File dir(tempDir);
//    if (!dir.exists())
//        dir.createDirectory();
//    _tempDir = Poco::format("%s/%s", tempDir, _instId);
//    File tmpdir(_tempDir);
//    if (!tmpdir.exists())
//        tmpdir.createDirectory();
//
//	Poco::StringTokenizer homeAreaCodeTokenizer( strHomeAreaCode, "#",
//            Poco::StringTokenizer::TOK_IGNORE_EMPTY );
//    for (auto it = homeAreaCodeTokenizer.begin();
//    		it != homeAreaCodeTokenizer.end(); it++) {
//    	int areaCode;
//    	stringstream(*it) >> areaCode;
//		DLOG << "Area Code:" << areaCode << ENDL;
//    	areaMap[areaCode] = tmpFileName.size();
//		fileArea[tmpFileName.size()] = areaCode;
//    	string filename = Poco::format(
//                               audit_default::TEMP_FILE_FORMAT,
//                               NumberFormatter::format0(areaCode,3));
//		DLOG << "tmpFileName:" << filename << ENDL;
//		string canonicalPath = Poco::format("%s/%s", _tempDir, filename);
//        tmpFileName.push_back(canonicalPath);
//        FileStream* file = new FileStream;
//        tmpFile.push_back(file);    //after new push into tmpfile immediately，in case of throwing exception
//        try {
//            file->open(canonicalPath, ios::trunc);
//        } catch (Poco::Exception& pe) {
//            ELOG << "TempFile open failed: " << pe.displayText() << ENDL;
//            return false;
//        }
//        fileRecCnt.push_back(0);
//        fileindex.push_back(-1);
//        filesplit.push_back(0);
//		createTime.push_back(0);
//		openTime.push_back(0);
//    }
    // AreaCode使用场景介绍:
    // 1. 在创建文件时，建立文件与省份的对应关系
    // 2. 在写文件时，根据areaMap找到省份对应文件
    // 3. 在提交文件时，根据fileArea找到文件对应省份
    // 由此可知，同一个省的只会写到一个文件中去，而且因为没有空文件提交，所以不会因为配错而有相同省份文件产生。
    return true;
}

bool AuditMain::reOpenTempFile()
{
//	for (int i = 0; i != tmpFile.size(); i++) {
//		tmpFile[i]->close();
//        try {
//            tmpFile[i]->open(tmpFileName[i], ios::trunc);
//        } catch (Poco::Exception& pe) {
//            ELOG << "TempFile open failed: " << pe.displayText() << ENDL;
//            return false;
//        }
//		fileRecCnt[i] = 0;
//        fileindex[i] = -1;
//        filesplit[i] = 0;
//		createTime[i] = 0;
//		Timestamp now;
//		openTime[i] = now.epochTime();
//        commitFileName.clear();
//	}
	return true;
}

bool AuditMain::expired(int& cnt, Timestamp& now)
{
	if (cnt) {
		cnt--;
		return false;
	}
	else {
		Timestamp last;
		now.swap(last);
		DateTime dt(now);
		int min = dt.minute();
		if (lastMinute != min && timeInterval != 0 && min % timeInterval == 5) {
			lastMinute = min;
			return true;
		}
		else {
			Timestamp::TimeDiff td = now - last; //micro seconds
			if (td > 30000000 || td <= 0)
				cnt = 0;
			else if (td < 300000)
				cnt = 100;
			else
				cnt = 30000000 / td - 1;
//			ILOG << "Last minute: " << lastMinute << ", now: " << min << ENDL;
			if (lastMinute != -1 && lastMinute != min && (lastMinute + 1) % 60 != min) {
				int itermin = (lastMinute + 1) % 60;
				while(itermin != min) {
					if (timeInterval != 0 && itermin % timeInterval == 5) {
						lastMinute = min;
//						ELOG << "Something wrong may happen, Last minute: " << lastMinute << ", now: " << min << ENDL;
						return true;
					}
					itermin = (itermin+1) % 60;
				}
				lastMinute = min;
			}
			else {
				lastMinute = min;
			}
			return false;
		}
	}
}

bool AuditMain::writeOneRecord()
{
//	std::string topic;
//    int32_t partition = 0;
//    int64_t offset = 0;
//    std::string data;
//	std::shared_ptr<RdKafka::Message> msgptr;
//	if (!mpConsumer->consume(msgptr)) {
//		ELOG << "failed to consumer data" << ENDL;
//		return false;
//	}
//	if (msgptr && msgptr->len() != 0) {
//		data.assign( static_cast<char*>( msgptr->payload() ),
//		     msgptr->len() );
//        topic = msgptr->topic_name();
//        partition = msgptr->partition();
//        offset = msgptr->offset();
//		fileManage->Settopic(topic.c_str(), partition, offset);
//        int par;
//        for (par = 0; par < _partiOffset.size(); par++) {
//            if (_partiOffset[par].partition == partition) {
//                _partiOffset[par].endOffset = offset;
//                break;
//            }
//        }
//		DLOG << "update topic: " << topic << ", partition: "
//			<< partition << "offset: " << offset << ENDL;
//		AuditInfo auditInfo;
//		if (!parseString2AuditInfo(data, auditInfo)) {
//			ELOG << "failed to parse audit info" << ENDL;
//			return false;
//		}
//		std::string info;
//		int index = 0;
//		if (!formatString4AuditInfo(auditInfo, info, index)){
//			ELOG << "failed to compound audit info" << ENDL;
//			return false;
//		}
//        if ((tmpFile[index]->tellp()+info.size()+2) > 10485760) {
//            //*tmpFile[index] << "]"; //before submit, need to add tail
//            HandleError(createFormalFile(_tempDir, index, false), "create formal file fail");
//            try {
//                tmpFile[index]->open(tmpFileName[index], ios::trunc);
//            } catch (Poco::Exception& pe) {
//                ELOG << "TempFile open failed: " << pe.displayText() << ENDL;
//                return false;
//            }
//        }
//        if (0 == fileRecCnt[index]) {
//            *tmpFile[index] << info << audit_default::LINE_SEPARATOR;
//			Timestamp now;
//			createTime[index] = now.epochTime();
//            if (par < _partiOffset.size())
//                _partiOffset[par].beginOffset = _partiOffset[par].endOffset; //开始消费的第一条数据
//        } else {
//            *tmpFile[index] << info << audit_default::LINE_SEPARATOR;
//        }
//		fileRecCnt[index]++;
//	}
//
//	return true;
//}
//
//bool AuditMain::parseString2AuditInfo(string& data, AuditInfo& info)
//{
//	dispatchpb::Audit audit;
//	if (!audit.ParseFromString(data)) {
//		ELOG << "failed to parse audit info from proto Audit" << ENDL;
//		// 遇到非标准proto, 选择忽略还是选择报错？
//		return true;
//	}
//	info.fileNameRecv = audit.has_filenamedistribute()? audit.filenamedistribute() : "";
//	info.fileNameTrans = audit.has_filenamedispatch()? audit.filenamedispatch() : "";
//	info.fileTimeSend = audit.has_dispatchtime()? fromEpochTime(audit.dispatchtime()) : "";
//	info.recCntSend = audit.has_dispatchcount()? audit.dispatchcount() : 0;
//	info.errCntRecv = audit.has_errcount()? audit.errcount() : 0;
//	info.fileTimeRecv = audit.has_distributetime()? fromEpochTime(audit.distributetime()) : "";
//	info.recCntRecv = audit.has_distributecount()? audit.distributecount() : 0;
	return true;
}

bool AuditMain::formatString4AuditInfo(AuditInfo& info, string& output, int& index)
{
//	if (info.fileNameTrans.length() == 0) {
//		ELOG << "fileNameTrans is null, cannot use it to find province code." << ENDL;
//		return false;
//	}
//	string strArea = info.fileNameTrans.substr(15,3);
//	try {
//		int areaCode = std::stoi(strArea);
//		if ((index = areaMap[areaCode]) == -1) {
//			ELOG << "areaCode: " << areaCode << " cannot be found." << ENDL;
//			return false;
//		}
//		else {
//            char temp[1024];
//        	snprintf(temp, sizeof(temp), audit_default::TEMP_FILE_DETAIL_FORMAT,
//                audit_default::NODE_ID, areaCode, info.fileNameRecv.c_str(),
//        		info.fileTimeRecv.c_str(), info.recCntRecv, info.errCntRecv, info.fileNameTrans.c_str(),
//        		info.fileTimeSend.c_str(), info.recCntSend);
//            output = string(temp);
//			ILOG << "Formatted output: " << output << ", corresponding file index: " << index << ENDL;
			return true;
//		}
//	} catch(const std::invalid_argument& ia) {
//		FLOG << "Invalid argument: " << ia.what() << ENDL;
//		return false;
//	}
}

int AuditMain::Submit()
{
//    if (-1 == fileManage->Move(_tempDir.c_str(), commitFileName)) {
//        ELOG << "Move file to formal folder fail." << ENDL;
//        return -1;
//    }
	return 0;
}

string AuditMain::acquireNewFileName(int index, bool isExpired)
{
//    bool isfirst = false;
//    if (fileindex[index] == -1) {
//        int64_t FileNum;
//        if (-1 == fileManage->GetFileNum(FileNum)) {
//            ELOG << "fileManage get file seqNum failed" << ENDL;
//            return "";
//        }
//        fileindex[index] = (int)FileNum;
//        isfirst = true;
//    }
//    char name[1024];
//    Timestamp now;
//    DateTime dt(now); // Timestamp > DateTime
//    LocalDateTime ldt(dt); // DateTime > LocalDateTime
//    string fmt = "%Y%m%d"; // YYYYMMDD
//    string dateStr = DateTimeFormatter::format(ldt, fmt); // 目标格式
//    filesplit[index] = (isfirst && isExpired)? 0:filesplit[index]+1;
//    snprintf(name, sizeof(name), audit_default::FORMAL_FILE_FORMAT, dateStr.c_str(),
//        fileArea[index], fileindex[index], filesplit[index]);
//    return string(name);
}

bool AuditMain::createFormalFile(const string& tempDir, int index, bool isExpired)
{
//    if (tempDir == "") {
//        ELOG << "Formal file rename fail: tempDir invalid: " << tempDir << ENDL;
//        return false;
//    }
//
//    if (index < 0 || index >= tmpFile.size()) {
//        ELOG << "Formal file rename fail: index invalid: " << index << ENDL;
//        return false;
//    }
//
//    if (fileRecCnt[index] > 0) {
//        string fileName = acquireNewFileName(index, isExpired);
//        if (fileName == "") {
//            ELOG << "Formal file rename fail: fileName is null" << ENDL;
//            return false;
//        }
//		int filesize = tmpFile[index]->tellp();
//        tmpFile[index]->close();
//        string canonicalPath;
//		if (tmpFile[index]->fail() == false) {
//            try {
//                File tFile(tmpFileName[index]);
//                canonicalPath = Poco::format("%s/%s", tempDir, fileName);
//                tFile.renameTo(canonicalPath);
//                auditLogAlert->insertLog(3, fileName, filesize,openTime[index], createTime[index], fileRecCnt[index], _partiOffset);
//                fileRecCnt[index] = 0;
//                commitFileName.push_back(fileName);
//            } catch(Poco::Exception& pe) {
//                ELOG << "Formal file rename fail: cannot rename to: " << canonicalPath << ENDL;
//                return false;
//            }
//		}
//		else {
//			ELOG << "tmpFile[" << tmpFileName[index] << "] close fail" << ENDL;
//			return false;
//		}
//    }
//    else {
//        ELOG << "Error: fileRecCnt invalid: " << fileRecCnt[index] << ENDL;
//        return false;
//    }
    return true;
}
}
