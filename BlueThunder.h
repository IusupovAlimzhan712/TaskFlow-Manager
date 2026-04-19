#ifndef BlueThunder_h
#define BlueThunder_h

#include "Robot.h"

// BlueThunder Class Inherits from Robot
class BlueThunder : public Robot{
    protected:
    int fireX = 0, fireY = 0;   // Coordinates where BlueThunder fires
    public:
    using Robot::Robot;    // Inherit the constructor from the Robot base class

    // Override
    void look(){}
    void move(){}
    void step(){}
    void fire();
    void PrintStatusFile(ofstream& out) const;

    void taketurn(){
        fire();
    }
};


#endif