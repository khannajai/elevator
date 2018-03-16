/**
 * @brief Class declaration for Elevator Controller. The controller will handle 
 * and simulate requests made to an elevator
 * 
 * @file controller.h
 * @author Jai Khanna
 * @date 2018-03-14
 */

#ifndef CONTROLLER
#define CONTROLLER

#include <iostream>
#include <vector>
#include "elevator.h"

class Controller
{
public:
    Controller();
    Controller(int numLifts);

    void simulate();
    void printStatus();
    
private:
    std::vector<Elevator> lift;
    void cli();    
};

#endif