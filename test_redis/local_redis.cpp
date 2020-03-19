//
// Created by james on 2019-04-28.
//

//
// Created by james on 2019-04-28.
//

#include<stdio.h>
#include<hircluster.h>
#include <hiredis.h>

int main()
{
//	redisClusterContext *cc = redisClusterConnect("127.0.0.1:7000,127.0.0.1:7001",HIRCLUSTER_FLAG_NULL);

	redisContext * a = redisConnect("127.0.0.1",6379);

	int i;
	redisReply* reply = NULL;

	for(i=0; i<10000; i++)
	{
		//set
		reply = reinterpret_cast<redisReply*>(redisCommand(a, "set key%d value%d", i, i));
		if(reply == NULL)
		{
			printf("set key%d, reply is NULL, error info: %s\n", i, a->errstr);
			redisFree(a);
			return -1;
		}
		printf("set key%d, reply:%s\n", i, reply->str);
		//get
		reply =  reinterpret_cast<redisReply*>(redisCommand(a, "get key%d", i));
		if(reply == NULL)
		{
			printf("get key%d, reply is NULL, error info: %s\n", i, a->errstr);
			redisFree(a);
			return -1;
		}
		printf("get key%d, reply:%s\n", i, reply->str);

	}

	return 0;
}