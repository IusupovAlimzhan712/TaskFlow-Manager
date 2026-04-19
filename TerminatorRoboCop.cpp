#include <iostream>
#include <fstream>

#include "TerminatorRoboCop.h"
using namespace std;

// Prints TerminatorRoboCop's status to an output file stream
void TerminatorRoboCop::PrintStatusFile(ofstream& out) const {
    out << "Robot Name: " << name << endl;
    out << "Robot Type: TerminatorRoboCop" << endl;
    out << "Position: (" << x << ", " << y << ")" << endl;
    out << "Kills: " << kills << endl;
    out << "Lives: " << lives << endl;
    out << "Fire Locations: ";
    for (auto fire : fireLocations) {
        out << "(" << fire[0] << ", " << fire[1] << "), ";
    }
    out << endl;
    out << "------------------------" << endl;
}

void TerminatorRoboCop::taketurn(){
    look();
    move();
    fire();
}

