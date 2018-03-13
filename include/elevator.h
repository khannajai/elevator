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
#include <cassert>

namespace elevator
{
/**
 * @brief 
 * 
 */
class Elevator
{
public:
    static int generateID;
    /**
     * @brief Construct a new Elevator object at floor 0 
     * 
     * @param floors : nunmber of floors in this elevator shaft. Defaults to 20 floors
     */
    Elevator(int floors=20)
        :noOfFloors(floors)
    {
        current=0;
        elevatorID=generateID++;
        state=STOPPED_OPEN;
    }
    /**
     * @brief Request the elevator at a floor
     * 
     * @param floor : floor number
     */
    void call(int floor)
    {
        assert(floor<=noOfFloors);
        floorList.push_back(floor);
    }

    enum ElevatorState
    {
        STOPPED_OPEN,
        STOPPED_CLOSE,
        MOVING_UP,
        MOVING_DOWN,
    };

    ElevatorState getState()
    {
        return state;
    }
private:
    int elevatorID;
    const int noOfFloors;
    int current;
    int next;
    vector<int> upList;
    vector<int> downList;
    ElevatorState state;
};

int Elevator::generateID=1;

}

#endif