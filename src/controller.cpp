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
#include <functional>
#include <regex>

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
    std::vector<std::thread> runningLift;
    for (auto it=lift.begin();it!=lift.end();++it)
    {
        std::thread th(std::bind(&Elevator::run, it));
        runningLift.push_back(std::move(th));
    }

    std::regex elevReq("(\\+|-)?[[:digit:]]+");
    std::regex floorReq("");

    while(1)
    {
        std::string userCommand;
        std::cout<<"Enter a command: ";
        std::cin>>userCommand;
        if (userCommand=="status")
        {
            printStatus();
        }
        if(userCommand=="exit")
        {
            exit(1);
        }
    }

    for (unsigned int i=0; i<runningLift.size(); ++i)
    {
        if (runningLift[i].joinable())
        {
            runningLift.at(i).join();
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

void Controller::floorRequest(int id, int atFloor)
{

}

void Controller::elevatorRequest(int id, int toFloor)
{

}