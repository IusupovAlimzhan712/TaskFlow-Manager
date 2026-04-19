#include <iostream>
#include <fstream>

#include "Terminator.h"
using namespace std;

// Terminator's look method: Scans the surroundings for other robots
void Terminator::look(){
    robotPos = false;

    // Iterate through a 3x3 area around the Terminator
    for(int i = -1; i < 2; i++){;
        int tempX = x + i;
        if(tempX < 0 || tempX >= field->getRows()) continue;

        for(int j = -1; j < 2; j++){
            int tempY = y + j;
            if(tempY < 0 || tempY >= field->getCols()) continue;
            if(tempX == x && tempY == y) continue;
            
            // Check if a robot is found at the current position
            if(field->isOccupied(tempX, tempY)){
                lookX = tempX;    // Store the found robot's position
                lookY = tempY;
                robotPos = true;
                return;
            }
        }
    }
}

// Terminator's step method: Move to the targeted robot's position and destroy it
void Terminator::step(){
    takeDamage(lookX, lookY);
    field->updatePosition(x, y, lookX, lookY, symbol);
}

// Terminator's move method: Either step towards a found robot or move randomly
void Terminator::move(){
    if(robotPos){
        step();
        x = lookX; y = lookY;
        kills++;
    }
    else{
        int newX, newY;
    do{
        newX = rand() % 3 + (x-1);
        if(newX == x){
            int temp = rand() % 2 == 0 ? -1 : 1;
            newY = y + temp;
        } else{
            newY = rand() % 3 + (y -1);
        }
    }while(!field->isInBounds(newX,newY));
    field->updatePosition(x, y, newX, newY, symbol);
    x = newX; y = newY;
    }
}

// Prints the Terminator's status to the specified output stream
void Terminator::PrintStatusFile(ofstream& out) const{
    out << "Robot Name: " << name << endl;
    out << "Robot Type: Terminator" << endl;
    out << "Position: (" << x << ", " << y << ")" << endl;
    out << "Kills: " << kills << endl;
    out << "Lives: " << lives << endl;
    out << "Robot can't fire. " << endl;
    out << "------------------------" << endl;
}

void Terminator::taketurn(){
    look();
    move();
}