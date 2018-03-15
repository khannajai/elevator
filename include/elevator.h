/**
 * @brief 
 * 
 * @file elevator.h
 * @author Jai Khanna
 * @date 2018-03-07
 */

#ifndef ELEVATOR
#define ELEVATOR

#include <vector>
#include <set>
#include <cassert>

/**
 * @brief 
 * 
 */
class Elevator
{
public:
    static int generateID;
    /**
     * @brief Construct a new Elevator object at floor 0 with 20 maximum floors
     */
    Elevator();

    enum ElevatorState
    {
        STOPPED_OPEN,
        STOPPED_CLOSED,
        MOVING_UP,
        MOVING_DOWN,
    };

    int getState();
    int getCurrent();
    int getNext();
    int getElevatorID();
    void run();
    std::set<int> getUpList();
    std::set<int> getDownList();
    void printAll();
    bool operator< (const Elevator &other) const
    {
        return elevatorID < other.elevatorID;
    }

private:
    int elevatorID;
    int noOfFloors;
    int current;
    int next;
    std::set<int> upList;
    std::set<int> downList;
    ElevatorState state;
};



#endif