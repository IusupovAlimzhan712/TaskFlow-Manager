#include <fstream>
#include "RoboTank.h"
using namespace std;


void RoboTank::fire(){
    field->updatePosition(x, y, x, y, 'R');
    
    // Find a random target position to fire at (excluding its own position)
    do{
        fireX = rand() % field->getRows();
        fireY = rand() % field->getCols();
    }while(fireX == x && fireY == y);

    // Check if the chosen firing position is occupied by another robot
    if(field->isOccupied(fireX, fireY)){
        takeDamage(fireX, fireY);   // Call a function (from the Robot base class) to handle damage to the target
        field->getField()[fireX][fireY] = '.';
        kills++;
    }
}

// Prints RoboTank's current status to the given output file stream
void RoboTank::PrintStatusFile(ofstream& out) const{
    out << "Robot Name: " << name << endl;
    out << "Robot Type: RoboTank" << endl;
    out << "Position: (" << x << ", " << y << ")" << endl;
    out << "Kills: " << kills << endl;
    out << "Lives: " << lives << endl;
    out << "Fire Location: " << "(" << fireX << ", " << fireY << ")" << endl;
    out << "------------------------" << endl;
}

void RoboTank::taketurn(){
    fire();
}