#include <iostream>
#include <fstream>
using namespace std;

#include "BlueThunder.h"

// Implementation of BlueThunder's firing mechanism
void BlueThunder::fire(){
    static int directionIndex = 0;    // Static to remember the firing direction across calls
    field->updatePosition(x, y, x, y, 'B');

    // Array of direction offsets (8 cardinal and diagonal directions)
    int directions[8][2] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},  
                           {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

    fireX = x + directions[directionIndex][0];
    fireY = y + directions[directionIndex][1];
    directionIndex = (directionIndex + 1) % 8;  // Cycle through directions

    if(field->isInBounds(fireX, fireY) && field->isOccupied(fireX, fireY)){
        takeDamage(fireX, fireY);    // Call a function (from the Robot base class) to handle damage to the target
        field->getField()[fireX][fireY] = '.';
        kills++;
    }
}

// Prints BlueThunder's status to an output file stream
void BlueThunder::PrintStatusFile(ofstream& out) const{
    out << "Robot Name: " << name << endl;
    out << "Robot Type: BlueThunder" << endl;
    out << "Position: (" << x << ", " << y << ")" << endl;
    out << "Kills: " << kills << endl;
    out << "Lives: " << lives << endl;
    out << "Fire Location: " << "(" << fireX << ", " << fireY << ")" << endl;
    out << "------------------------" << endl;
}
