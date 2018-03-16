# Elevator Simulator

## About
This program simulates up to 16 elevators (running as mutliple threads). It takes requests (call or drop-off) from the user and shows the status of elevators on the screen. 

## Build instructions and usage
1. Clone repository
```
git clone https://github.com/khannajai/elevator.git
cd elevator
```
2. Inside repository (install CMake first)
```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```
3. Run executable
```
./elevator-simulator
```

## Code Description
`/include`
  `controller.h`: Controller class header. Represents a controller object. A controller acts as an interface that simulates multiple elevators, takes requests from the user and shows the status of the elevators.
  `elevator.h`: Elevator class header. Represents an elevator object, along with its scheduling and request handling methods.

`/src`
  `controller.cpp`: Implementation of the controller class
  `elevator.cpp`: Implementation of the elevator class
  `elevator-simulator.cpp`: Contains the `main()` function

## Scheduling algorithm
Keep moving in one direction until there are no more requests in that direction. Then reverse the direction. 

Requests made to an elevator are handled in `Elevator::requestHandler(int floor)`, which places the requested floor in sets `upList` or `downList`.

`Elevator::run()` continuously checks if there are pending requests in `upList` or `downList`. It continues moving the elevator in one direction until the request list for that direction is empty, then changes direction.


## Further improvements
The algorithm was designed in a short time period and can be improved and optimized. To see if it performs better than FCFS, some analysis must be performed. For example, we can compare the runtime of both algorithms on a set of requests, or compare the average time taken to complete a request (ie. the average waiting time for a passenger).
The object oriented design and general functionality can be improved. At the moment, a pick-up request must be specifically directed to one elevator without specifying direction. It would be better if the user could request an elevator in the specified direction and the "best" elevator in the building stops at that floor to complete the pickup request.
