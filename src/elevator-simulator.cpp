/**
 * @brief This program simulates up to 16 elevators (running as mutliple threads). 
 * It takes requests (call or drop-off) from the user 
 * and shows the status of elevators on the screen. 
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
    int numElevators;
    do
    {
        cout<<"Enter the number of elevators you want to simulate (up to 16): ";
        cin>>numElevators;
        if(numElevators>16 || numElevators<1)
        {
            cout<<"Enter 1-16 elevators"<<endl;
        }
    }
    while(numElevators>16 || numElevators<1);

    //started controller
    Controller myController(numElevators);
    
    //starting simulation
    myController.simulate();
    return 0;
}