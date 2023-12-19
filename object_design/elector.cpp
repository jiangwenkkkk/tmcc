//
// Created by top on 2023/12/13.
//
#include "vector"
#include <iostream>
#include <list>
#include "Poco/Thread.h"
#include "Poco/Mutex.h"

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
        _thread.start(this);
    }
    bool toDest(int dest){
        if(getState()==running)
            return false;
        setState(running);
        iDestFloor = dest;
        while(iDestFloor != iFloor)
        {
            std::cout << iIndex << ">>>>>" << iFloor << std::endl;
            if(iDestFloor < iFloor)
                iFloor--;
            else if(iDestFloor > iFloor)
                iFloor++;
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
                std::cout << "go to " <<  lisDest.front() << std::endl;
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
    std::vector<elevator*> electors;
public:
    void toDest(int floor, int dest){
        int i = 0;
        for(; i < electors.size(); i++)
        {
            if(electors[i]->getState() == elevator::stoped){
                break;
            }
        }


        electors[i]->start_to_end(floor, dest);

    }



    Center(){
        elevator* ele1 = new elevator(10, 1);
        electors.push_back(ele1);
        elevator* ele2 = new elevator(10,2);
        electors.push_back(ele1);
    }

};


int main()
{
    Center cen;
    cen.toDest(0, 10);
    cen.toDest(1, 10);
    cen.toDest(3, 10);

    return 1;
}