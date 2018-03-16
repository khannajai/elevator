/**
 * @brief Implementation of elevator class
 * 
 * @file elevator.cpp
 * @author Jai Khanna
 * @date 2018-03-07
 */

#include <iostream>
#include <set>
#include "elevator.h"
#include <chrono>
#include <ctime>
#include <algorithm>

int Elevator::generateID=0;

Elevator::Elevator()
{
    noOfFloors=20;
    elevatorID=generateID++;
    current=0;
    next=0;

    timeBetweenFloors=5;
    timeDoorOpen=2;
    timeDoorClose=1;

    state=STOPPED_CLOSED;
    direction=UP;
}

void Elevator::run()
{
    while(1)
    {
        //if direction set to up
        if(direction==0)
        {   //if list has floors
            if (!upList.empty())
            {   
                //destination set to lowest floor in uplist
                auto it=upList.begin();
                next=*it;
                //go up if you haven't arrived at destination
                if(current<next)
                {
                    goUp();
                }
                //if you've arrived, open the door and remove that floor from the list
                if(current==next)
                {
                    openDoor();
                    upList.erase(it);
                    closeDoor();
                }
            }
            //if list is empty, reverse direction
            else
            {
                direction=DOWN;
            }
        }      
        //if direction set to down
        else if (direction==1)
        {   
            //if list has floors
            if (!upList.empty())
            {
                //destination set to highest floor in downList
                auto it=downList.end();
                it--;
                next=*it;
                //go down if you haven't arrived at destination
                if(current>next)
                {
                    goDown();
                }
                //if arrived, open the door and remove floor from list
                if(current==next)
                {
                    openDoor();
                    downList.erase(it);
                    closeDoor();
                }
            }
            //if list is empty, reverse direction
            else
            {  
                direction=UP;
            }
        }
    }
}

bool Elevator::requestHandler(int floor)
{   
    //if requested floor is below the current floor
    if(floor<current)
    {
        downList.insert(floor);
        return true;
    }

    //if requested floor is above the current floor
    else if(floor>current)
    {
        upList.insert(floor);
        return true;
    }

    //if request is for current floor
    else
    {
        if(state==STOPPED_OPEN)
        {
            //do nothing if doors are already open
        }
        else
        {
            //if its moving or its closed, add to queue in reverse direction
            if(direction==0)
            {
                downList.insert(floor);
                return true;
            }
            else
            {
                upList.insert(floor);
                return true;
            }
        }
    }
    return false;
}


void Elevator::goUp()
{
    state=MOVING_UP;
    //std::cout<<"Elevator "<<elevatorID<<" moving up."<<std::endl;
    auto start =std::chrono::system_clock::now();
    while(1)
    {
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        if(elapsed_seconds.count()>timeBetweenFloors)
        {
            break;
        }
    }
    current++;
}

void Elevator::goDown()
{
    state=MOVING_DOWN;
    auto start =std::chrono::system_clock::now();
    while(1)
    {
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        if(elapsed_seconds.count()>timeBetweenFloors)
        {
            break;
        }
    }
    current--;
}

void Elevator::openDoor()
{
    state=STOPPED_OPEN;
    auto start =std::chrono::system_clock::now();
    while(1)
    {
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        if(elapsed_seconds.count()>timeDoorOpen)
        {
            break;
        }
    }
}

void Elevator::closeDoor()
{
    auto start =std::chrono::system_clock::now();
    while(1)
    {
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        if(elapsed_seconds.count()>timeDoorClose)
        {
            break;
        }
    }
    state=STOPPED_CLOSED;
}

int Elevator::getState() const
{
    return state;
}

int Elevator::getCurrent() const
{
    return current;
}

int Elevator::getNext() const
{
    return next;
}

int Elevator::getElevatorID() const
{
    return elevatorID;
}

int Elevator::getNoOfFloors() const
{
    return noOfFloors;
}

void Elevator::printAll() const
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


