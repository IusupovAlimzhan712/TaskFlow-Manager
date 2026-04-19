#include <iostream>
#include <fstream>

#include "RoboCop.h"
using namespace std;

// Implementation of RoboCop moving mechanism
void RoboCop::move(){
    int newX, newY;
    // Loop to find a valid new position (within bounds and not occupied)
    do{
        newX = rand() % 3 + (x-1);
        if(newX == x){
            int temp = rand() % 2 == 0 ? -1 : 1;
            newY = y + temp;
        } else{
            newY = rand() % 3 + (y -1);
        }
    }while(!field->isInBounds(newX,newY) || (field->isOccupied(newX,newY)));
    field->updatePosition(x, y, newX, newY, symbol);  // Update the battlefield with the move
    x = newX; y = newY;  // Update RoboCop's current position
}

// Implementation of RoboCop firing mechanism
void RoboCop::fire(){
    for(int i = 0; i < 3; i++){
       int fireX, fireY;
       // Find a valid firing location within a 20x20 square centered on RoboCop
       do{
           fireX = x + (rand() % 21 - 10);
           fireY = y + (rand() % 21 - 10);
        } while (!field->isInBounds(fireX,fireY) || (fireX == x && fireY == y)  // Don't fire on itself
                || (abs(fireX - x) + abs(fireY - y) > 10));  // Limit range to 10 city block distance
        fireLocations[i][0] = fireX; fireLocations[i][1] = fireY; // Store firing location
        
        // If the firing location is occupied, inflict damage and clear the cell
        if(field->isOccupied(fireX, fireY)){
        takeDamage(fireX, fireY);
        field->getField()[fireX][fireY] = '.';
        kills++;
        }   
    }
}

// Prints RoboCop's status to an output file stream
void RoboCop::PrintStatusFile(ofstream& out) const {
    out << "Robot Name: " << name << endl;
    out << "Robot Type: RoboCop" << endl;
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

void RoboCop::taketurn(){
    move();
    fire();
}
