/**
 * @brief 
 * 
 * @file elevator-simulator.cpp
 * @author Jai Khanna
 * @date 2018-03-15
 */

#include <iostream>
#include "elevator.h"
#include "controller.h"
#include <thread>

using namespace std;


int main(int argc, char* argv[])
{
    int numElevators=5;
    Controller myController(numElevators);
    cout<<"Initialized "<<numElevators<<" elevators."<<endl;
    myController.printStatus();
    myController.simulate();
    return 0;
}