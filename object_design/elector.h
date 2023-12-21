//
// Created by james on 2023/12/21.
//

#ifndef TESTPOCO_ELECTOR_H
#define TESTPOCO_ELECTOR_H

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

class elevator;

struct request{
    int _start;
    int _end;
};
class Center{
private:
    std::vector<elevator*> elevators;
    std::list<request> requests;
    Poco::Mutex _mutex;
public:
    void toDest(int floor, int dest);
    void doWork(){
        Poco::ScopedLock<Poco::Mutex> lock(_mutex);
        if(!requests.empty()){
            LOG_INFO("get a work");
            request aa =requests.front();
            toDest(aa._start, aa._end);
            requests.pop_front();
        }
    }

    Center();
};

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
    Center * _pCenter;
    int count = 0;
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
        LOG_INFO("###############################%d arrive [%d] floor state[%d]", iIndex, dest, iState);
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

    void setCenter(Center* pCenter){
        _pCenter = pCenter;
    }

    void reportWork(){
        _pCenter->doWork();
    }

protected:

    void setState(int state){
        Poco::ScopedLock<Poco::Mutex>a(_mutex);
        iState = state;
    }

    void run(){

        while(getState()!=finished){
            if(!lisDest.empty()){
                toDest(lisDest.front());
//                std::cout << "go to " <<  lisDest.front() << std::endl;
                LOG_INFO("go to [%d] ", lisDest.front());
                lisDest.pop_front();
                reportWork();
            }

            Poco::Thread::sleep(1000);
            if(++count%10 == 0)
                LOG_INFO("%d is running %d state[%d]", iIndex, count, iState);
    //            std::cout <<iIndex << " is running " << count << std::endl;

        }
    }

    ~elevator(){
        setState(finished);
        _thread.join();
    }
    friend class Center;
};




#endif //TESTPOCO_ELECTOR_H
