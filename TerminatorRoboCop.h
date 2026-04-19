#ifndef TerminatorRoboCop_h
#define TerminatorRoboCop_h


#include "RoboCop.h"
#include "Terminator.h"

class TerminatorRoboCop : virtual public RoboCop , virtual public Terminator {
    public:

    // Constructor: Initializes the TerminatorRoboCop object using the Robot base class 
    // constructor and the constructors of the parent classes (RoboCop and Terminator)
     TerminatorRoboCop(Battlefield* _field, int _x, int _y, char _symbol, string _name)
        : Robot(_field, _x, _y, _symbol, _name), RoboCop(_field, _x, _y, _symbol, _name), Terminator(_field, _x, _y, _symbol, _name) {}
    
    // Override
    void look() override { Terminator::look(); }  // Use Terminator's look behavior
    void fire() override { RoboCop::fire(); }     // Use RoboCop's fire behavior
    void move() override { Terminator::move(); }  // Use Terminator's move behavior
    void step() override { Terminator::step(); }  // Use Terminator's step behavior
    void PrintStatusFile(ofstream& out) const;
    void taketurn();
};


#endif