#ifndef RoboCop_H
#define RoboCop_H

#include "Robot.h"

// RoboCop inherits from the Robot class using virtual inheritance
class RoboCop : virtual public Robot{
    protected:
    int fireLocations[3][2] = {0};
    public:
    using Robot::Robot;  // Inherit the constructor from the base Robot class

    // Override
    void look(){}
    void move();
    void fire();
    void step(){}
    void taketurn();
    void PrintStatusFile(ofstream& out) const;
};

#endif