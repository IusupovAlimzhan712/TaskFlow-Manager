#include <fstream>
#include "Madbot.h"
using namespace std;

// Implementation of Madbot firing mechanism 
void Madbot::fire(){
    field->updatePosition(x, y, x, y, 'M');

     // Loop to find a valid firing position
    do{
        fireX = rand() % 3 + (x-1);
        if(fireX == x){
            int temp = rand() % 2 == 0 ? -1 : 1;
            fireY = y + temp;
        } else{
            fireY = rand() % 3 + (y -1);
        }
    }while(!field->isInBounds(fireX,fireY));

    if(field->isOccupied(fireX, fireY)){
        takeDamage(fireX, fireY);   // Call a function (from the Robot base class) to handle damage to the target
        field->getField()[fireX][fireY] = '.';
        kills++;
    }
}

// Prints Madbot's status to an output file stream
void Madbot::PrintStatusFile(ofstream& out) const{
    out << "Robot Name: " << name << endl;
    out << "Robot Type: Madbot" << endl;
    out << "Position: (" << x << ", " << y << ")" << endl;
    out << "Kills: " << kills << endl;
    out << "Lives: " << lives << endl;
    out << "Fire Location: " << "(" << fireX << ", " << fireY << ")" << endl;
    out << "------------------------" << endl;
}

void Madbot::taketurn(){
    fire();
}