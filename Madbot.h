#ifndef Madbot_h
#define Madbot_h

#include "BlueThunder.h"

/* Madbot inherits from BlueThunder using virtual inheritance. 
This establishes a relationship where Madbot is a specialized type of BlueThunder robot. */
class Madbot : virtual public BlueThunder{
    public:
    using BlueThunder::BlueThunder;    // Inherit the constructor from BlueThunder
    
    // Override
    void move(){}
    void look(){}
    void step(){}
    void fire();
    void taketurn();
    void PrintStatusFile(ofstream& out) const;
};

#endif