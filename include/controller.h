/**
 * @brief Class declaration for Elevator Controller. 
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

/**
 * @brief The controller object will take requests from the user
 * and simulate multiple elevators.
 * 
 */
class Controller
{
public:
    /**
     * @brief Construct a new Controller object
     * 
     */
    Controller();

    /**
     * @brief Construct a new Controller object for simulating multiple elevators
     * 
     * @param numLifts : The number of elevators you want
     */
    Controller(int numLifts);

    /**
     * @brief Simulates elevators with mutiple threads, 
     * along with a cli for users to make requests and query status
     * 
     */
    void simulate();

    /**
     * @brief Prints status of elevators
     * 
     */
    void printStatus();
    
private:
    /**
     * @brief Vector of elevators
     * 
     */
    std::vector<Elevator> lift;
    /**
     * @brief cli to be used in simulate()
     * 
     */
    void cli();    
};

#endif