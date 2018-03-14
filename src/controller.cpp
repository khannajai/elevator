/**
 * @brief 
 * 
 * @file controller.cpp
 * @author Jai Khanna
 * @date 2018-03-14
 */

#include <iostream>
#include <set>
#include <string>
#include <thread>
#include "elevator.h"
#include "controller.h"

Controller::Controller()
{

}

Controller::Controller(int numLifts)
{
    for (int i=0;i<numLifts;i++)
    {
        Elevator temp;
        lift.push_back(temp);
    }
}

void Controller::simulate()
{
    while(1)
    {
        std::string userCommand;
        std::cin>>userCommand;
        if (userCommand=="status")
        {
            printStatus();
        }
        if(userCommand=="end")
        {
            break;
        }
    }


}

void Controller::printStatus()
{
    std::cout<<"ID\tCurrent\tNext\tStatus"<<std::endl;
    for(auto it = lift.begin();it!=lift.end();++it)
    {
        it->printAll();
    }
}

void Controller::floorRequest(int atFloor)
{

}

void Controller::elevatorRequest(int toFloor)
{

}