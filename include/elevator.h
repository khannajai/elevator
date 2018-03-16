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
#include <chrono>
#include <ctime>
#include <set>

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

    void run();
    bool requestHandler(int floor);

    void goUp();
    void goDown();
    void openDoor();
    void closeDoor();


    int getState();
    int getCurrent();
    int getNext();
    int getElevatorID();
    int getNoOfFloors();

    void printAll();    

    enum ElevatorState
    {
        STOPPED_OPEN,
        STOPPED_CLOSED,
        MOVING_UP,
        MOVING_DOWN,
    };

    enum ElevatorDirection
    {
        UP,
        DOWN,
    };

private:
    int elevatorID;
    int noOfFloors;

    int current;
    int next;

    std::set<int> upList;
    std::set<int> downList;
    
    int timeBetweenFloors;
    int timeDoorOpen;
    int timeDoorClose;

    ElevatorState state;
    ElevatorDirection direction;
};

#endif