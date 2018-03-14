/**
 * @brief 
 * 
 * @file elevator.cpp
 * @author Jai Khanna
 * @date 2018-03-07
 */

#include <iostream>
#include <set>
#include "elevator.h"

int Elevator::generateID=1;

Elevator::Elevator()
{
    noOfFloors=20;
    current=0;
    next=0;
    elevatorID=generateID++;
    state=STOPPED_CLOSED;
}

int Elevator::getState()
{
    return state;
}

int Elevator::getCurrent()
{
    return current;
}

int Elevator::getNext()
{
    return next;
}

int Elevator::getElevatorID()
{
    return elevatorID;
}

std::set<int> Elevator::getUpList()
{
    return upList;
}

std::set<int> Elevator::getDownList()
{
    return downList;
}

void Elevator::printAll()
{
    std::cout<<elevatorID<<"\t"<<current<<"\t"<<next<<"\t";
    switch(state)
    {
        case 0:
            std::cout<<"STOPPED_OPEN"<<std::endl;
            break;
        case 1:
            std::cout<<"STOPPED_CLOSED"<<std::endl;
            break;
        case 2:
            std::cout<<"MOVING_UP"<<std::endl;
            break;
        case 3:
            std::cout<<"MOVING_DOWN"<<std::endl;
            
    }
}
