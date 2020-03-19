//
// Created by james on 2018-12-31.
//

#include <thread>
#include <iostream>
#include <mhash.h>

void* p(void*)
{
	std::cout <<"hello" << std::endl;
	sleep(100);
}
class runnable{
public:
	virtual void run()=0;
};

class pp_thread{
public:
	pp_thread(runnable* a):_runable(a){

	}

	void start()
	{
		pthread_create(&_pt, NULL, run, this);

	}

	void join()
	{
		pthread_join(_pt, NULL);
	}

private:
	runnable* _runable;
	pthread_t _pt;
private:
	static void* run(void* tm)
	{
		reinterpret_cast<pp_thread*>(tm)->_runable->run();
	}
};
class he:public runnable{
public:
	void run()
	{
		std::cout << "hello" << std::endl;
	}
};
int main()
{
//	he a;
//	pp_thread z(&a);
//	z.start();
//	z.join();


	pthread_t a;

	pthread_create(&a, NULL, &p, NULL);
	std::cout << "hello";
	pthread_join(a, NULL);
	std::cout << "ok";

}