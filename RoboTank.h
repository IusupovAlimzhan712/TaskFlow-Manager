#ifndef RoboTank_h
#define RoboTank_h

#include "Madbot.h"

// RoboTank class inherits form Madbot Class
class RoboTank : public Madbot{
    public:
    using Madbot::Madbot;   // Using the Madbot constructor
    
    // Override
    void move(){}
    void look(){}
    void step(){}
    void fire();
    void taketurn();
    void PrintStatusFile(ofstream& out) const;
};


#endif