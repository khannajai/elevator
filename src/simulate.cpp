/**
 * @brief 
 * 
 * @file simulate.cpp
 * @author Jai Khanna
 * @date 2018-03-07
 */

#include <iostream>
#include "elevator.h"
#include "controller.h"
using namespace std;

int main(int argc, char* argv[])
{
    Controller myController(16);
    myController.simulate();
    return 0;
}
