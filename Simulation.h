#ifndef Simulation_h
#define Simulation_h

#include "Battlefield.h"
#include "Robot.h"
#include "RobotList.h"
#include "RobotQueue.h"

// Manages the simulation of the robot battle
class Simulation{
    static Battlefield* field;       // Static pointer to the battlefield object
    static RobotList rLst;           // Static linked list to store active robots
    static RobotQueue respawnQueue;  // Static queue to manage respawning robots
    public:
    Simulation(const string& fileName);  // Constructor that takes a configuration file name
    ~Simulation();

    // Methods for simulation setup and execution
    void configFile(const string& fileName, int& steps);
    void run(int steps);
    void updateRobot(Node* curr);
    friend void Robot::takeDamage(int x, int y);  // Friend function allowing Robot to access private members for damage handling
};


#endif