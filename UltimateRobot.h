#ifndef UltimateRobot_h
#define UltimateRobot_h

#include "TerminatorRoboCop.h"

class UltimateRobot : virtual public TerminatorRoboCop{
    int randomFireAtField[3][2] = {0};
    public:

    // Constructor: Initializes the UltimateRobot using base class and parent class constructors
    UltimateRobot(Battlefield* _field, int _x, int _y, char _symbol, string _name)
        : Robot(_field, _x, _y, _symbol, _name), RoboCop(_field, _x, _y, _symbol, _name), Terminator(_field, _x, _y, _symbol, _name), TerminatorRoboCop(_field, _x, _y, _symbol, _name){}
    
    // Override
    void look(){ TerminatorRoboCop::look(); }   // Use TerminatorRoboCop's look behavior
    void move(){ TerminatorRoboCop::move(); }   // Use TerminatorRoboCop's move behavior
    void step(){ TerminatorRoboCop::step(); }   // Use TerminatorRoboCop's step behavior
    void fire();
    void PrintStatusFile(ofstream& out) const;
    void taketurn();
};


#endif