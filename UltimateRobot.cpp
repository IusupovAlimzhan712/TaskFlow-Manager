#include "UltimateRobot.h"
#include <fstream>
using namespace std;

// UltimateRobot's firing logic: Combines targeted firing with random firing
void UltimateRobot::fire(){
    TerminatorRoboCop::fire();   // Call the parent's fire() (RoboCop's targeted firing)

     // Perform additional random firing (3 shots)
    for(int i = 0; i < 3; i++){
        int fireX, fireY;
        do{
            fireX = rand() % field->getRows();
            fireY = rand() % field->getCols();
        }while(fireX == x && fireY == y);

        randomFireAtField[i][0] = fireX; randomFireAtField[i][1] = fireY;

        if(field->isOccupied(fireX, fireY)){
            takeDamage(fireX, fireY);
            field->getField()[fireX][fireY] = '.';
            kills++;
        }
    } 
}

// Prints UltimateRobot's status to an output file stream
void UltimateRobot::PrintStatusFile(ofstream& out) const{
    out << "Robot Name: " << name << endl;
    out << "Robot Type: UltimateRobot" << endl;
    out << "Position: (" << x << ", " << y << ")" << endl;
    out << "Kills: " << kills << endl;
    out << "Lives: " << lives << endl;
    out << "Fire Locations: ";
    for (auto fire : fireLocations) {
        out << "(" << fire[0] << ", " << fire[1] << "), ";
    }
    out << endl;
    out << "random Fire Locations At The Field: ";
    for (auto fire : randomFireAtField) {
        out << "(" << fire[0] << ", " << fire[1] << "), ";
    }
    out << endl;
    out << "------------------------" << endl;
}

void UltimateRobot::taketurn(){
    look();
    move();
    fire();
}