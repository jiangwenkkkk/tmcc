//
// Created by top on 2023/12/13.
//

#include "elector.h"

void Center::toDest(int floor, int dest) {
    int i = 0;
    for(; i < elevators.size(); i++)
    {
        if(elevators[i]->getState() == elevator::stoped){
//                std::cout << i << " elevator is idle" << std::endl;
            LOG_INFO("[%d] elevator is idle [%d]", i, elevators[i]->getState());
            elevators[i]->setState(elevator::running);
            elevators[i]->start_to_end(floor, dest);
            return;
        }
    }

//        std::cout << "error no elevator" << std::endl;
    LOG_INFO("add request to list");

    requests.push_back({floor, dest});
}

Center::Center() {
    elevator* ele1 = new elevator(10, 1);
    elevators.push_back(ele1);
    ele1->setCenter(this);
    elevator* ele2 = new elevator(10,2);
    elevators.push_back(ele2);
    ele2->setCenter(this);
}




int main()
{
    Logger& root = Logger::root();
    AutoPtr<ConsoleChannel> pConsoleChannel = new ConsoleChannel();
    root.setChannel(pConsoleChannel);
    pConsoleChannel->open();
    root.setLevel(Message::PRIO_DEBUG);

    LOG_INFO("start  elevator system");

    Center cen;
    cen.toDest(0, 10);
    cen.toDest(1, 10);
    cen.toDest(3, 10);
    Poco::Thread::sleep(1000000);
    return 1;
}

