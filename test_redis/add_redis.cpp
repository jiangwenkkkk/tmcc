//
// Created by james on 2019-04-28.
//

#include<stdio.h>
#include<hircluster.h>

int main()
{
//	redisClusterContext *cc = redisClusterConnect("127.0.0.1:7000,127.0.0.1:7001",HIRCLUSTER_FLAG_NULL);

	redisClusterContext *cc;
	cc = redisClusterContextInit();
	redisClusterSetOptionAddNodes(cc, "127.0.0.1:6379");
	redisClusterConnect2(cc);

	if(cc == NULL || cc->err)
	{
		printf("connect error : %s\n", cc == NULL ? "NULL" : cc->errstr);
		return -1;
	}

	int i;
	redisReply* reply = NULL;

	for(i=0; i<10000; i++)
	{
		//set
		reply = (redisReply*)(redisClusterCommand(cc, "set key%d value%d", i, i));
		if(reply == NULL)
		{
			printf("set key%d, reply is NULL, error info: %s\n", i, cc->errstr);
			redisClusterFree(cc);
			return -1;
		}
		printf("set key%d, reply:%s\n", i, reply->str);
		freeReplyObject(reply);

		//get
		reply = reinterpret_cast<redisReply*>( redisClusterCommand(cc, "get key%d", i));
		if(reply == NULL)
		{
			printf("get key%d, reply is NULL, error info: %s\n", i, cc->errstr);
			redisClusterFree(cc);
			return -1;
		}
		printf("get key%d, reply:%s\n", i, reply->str);
		freeReplyObject(reply);
	}

	redisClusterFree(cc);
	return 0;
}