#ifndef Terminator_H
#define Terminator_H

#include "Robot.h"

// Terminator class inherits from Robot class
class Terminator : virtual public Robot{
    // Terminator attributes
    int lookX;
    int lookY;
    bool robotPos;
    public:
    using Robot::Robot;   // Inherits the constructor from the Robot base class

    // Override
    void look();
    void move();
    void fire(){}
    void step();
    void PrintStatusFile(ofstream& out) const;
    void taketurn();
};



#endif

