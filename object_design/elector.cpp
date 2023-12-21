//
// Created by top on 2023/12/13.
//
#include "vector"
#include <iostream>
#include <list>
#include "Poco/Thread.h"
#include "Poco/Mutex.h"
#include "Poco/Logger.h"
#include "Poco/ConsoleChannel.h"

using Poco::Logger;
using Poco::ConsoleChannel;
using Poco::Channel;
using Poco::Message;
using Poco::AutoPtr;

#define LOG_INFO(format, args...) do { \
                                       char log[4096] = {0}; \
                                       snprintf(log, 4095, format, ##args); \
                                       Logger::root().debug(log);           \
                                     } while(0)
#define LOG_ERR(format, args...) do { \
                                       char log[4096] = {0}; \
                                       snprintf(log, 4095, format, ##args); \
                                       Logger::root().error(log);           \
                                     } while(0)

class elevator: public Poco::Runnable{
public:
    enum {
        stoped = 0,
        running,
        broken,
        cancelling,
        finished,
    };
private:
    int iFloor;
    int iState;
    int iMaxFloor;
    int iDestFloor;
    int iIndex;
    Poco::Mutex _mutex;
    Poco::Mutex _mutexList;
    std::list<int> lisDest;
    Poco::Thread _thread;
public:
    elevator(int max_floor, int index) : iMaxFloor(max_floor), iState(stoped), iFloor(0), iDestFloor(0), iIndex(index), Poco::Runnable(){
        _thread.start(*this);
    }
    bool toDest(int dest){

        iDestFloor = dest;
        while(iDestFloor != iFloor)
        {
//            std::cout << iIndex << ">>>>>" << iFloor << std::endl;
            LOG_INFO("index [%d] >>>>>>> floor [%d]", iIndex, iFloor);
            if(iDestFloor < iFloor)
                iFloor--;
            else if(iDestFloor > iFloor)
                iFloor++;
            Poco::Thread::sleep(1000);
        }
        setState(stoped);
    }

    bool start_to_end(int start, int end){
        Poco::ScopedLock<Poco::Mutex>b(_mutexList);
        lisDest.push_back(start);
        lisDest.push_back(end);
    }

    int getState(){
        Poco::ScopedLock<Poco::Mutex>a(_mutex);
        return iState;
    }


protected:

    void setState(int state){
        Poco::ScopedLock<Poco::Mutex>a(_mutex);
        iState = state;
    }

    void run(){
        static int count = 0;
        while(getState()!=finished){
            if(!lisDest.empty()){
                toDest(lisDest.front());
//                std::cout << "go to " <<  lisDest.front() << std::endl;
                LOG_INFO("go to [%d] ", lisDest.front());
                lisDest.pop_front();


            }
            Poco::Thread::sleep(100);
            if(++count%10 == 0)
                std::cout <<iIndex << " is running " << count << std::endl;
        }
    }

    ~elevator(){
        setState(finished);
        _thread.join();
    }
    friend class Center;
};

class Center{
private:
    std::vector<elevator*> elevators;
public:
    void toDest(int floor, int dest){
        int i = 0;
        for(; i < elevators.size(); i++)
        {
            if(elevators[i]->getState() == elevator::stoped){
//                std::cout << i << " elevator is idle" << std::endl;
                LOG_INFO("[%d] elevator is idle ");
                elevators[i]->setState(elevator::running);
                elevators[i]->start_to_end(floor, dest);
            }
        }

//        std::cout << "error no elevator" << std::endl;
          LOG_ERR("error no elevator");

    }

    Center(){
        elevator* ele1 = new elevator(10, 1);
        elevators.push_back(ele1);
        elevator* ele2 = new elevator(10,2);
        elevators.push_back(ele2);
    }

};


int main()
{
    Logger& root = Logger::root();
    AutoPtr<ConsoleChannel> pConsoleChannel = new ConsoleChannel();
    root.setChannel(pConsoleChannel);
    pConsoleChannel->open();
    root.setLevel(Message::PRIO_DEBUG);
    root.error("hello");
    LOG_INFO("tmccefg");
    LOG_ERR("fuck %s","ttt");

    Center cen;
    cen.toDest(0, 10);
    cen.toDest(1, 10);
    cen.toDest(3, 10);
    Poco::Thread::sleep(1000000);
    return 1;
}