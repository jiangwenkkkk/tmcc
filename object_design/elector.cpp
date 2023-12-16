//
// Created by top on 2023/12/13.
//
#include "vector"
#include <iostream>

class elevator {
public:
    enum {
        stoped = 0,
        running,
        broken,
    };
private:
    int iFloor;
    int iState;
    int iMaxFloor;
    int iDestFloor;
public:
    elevator(int max_floor) : iMaxFloor(max_floor), iState(stoped), iFloor(0), iDestFloor(0){
    }
    bool toDest(int dest){
        if(iState==running)
            return false;
        iState = running;
        iDestFloor = dest;
        while(iDestFloor != iFloor)
        {
            std::cout << ">>>>>" << iFloor << std::endl;
            if(iDestFloor < iFloor)
                iFloor--;
            else if(iDestFloor > iFloor)
                iFloor++;
        }
        iState = stoped;
    }

    int getState(){
        return iState;
    }
};

class Center{
private:
    std::vector<elevator> electors;
public:
    void toDest(int floor, int dest){
        int i = 0;
        for(; i < electors.size(); i++)
        {
            if(electors[i].getState() == elevator::stoped){
                break;
            }
        }
        electors[i].toDest(floor);
        std::cout << "您好" << std::endl;
        electors[i].toDest(dest);
        std::cout << floor << " to " << dest<< "thanks \n" << std::endl;
    }

    Center(){
        elevator ele(10);
        electors.push_back(ele);
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