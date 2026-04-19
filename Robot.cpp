#include <iostream>
#include <fstream>


#include "Robot.h"
#include "Simulation.h"
using namespace std;

// Constructor: Initializes a Robot object with given parameters
Robot::Robot(Battlefield* _field, int _x, int _y,
        char _symbol, string _name){
    field = _field;
    x = _x; y = _y;
    symbol = _symbol; name = _name;
    if(field->isInBounds(x, y) && !field->isOccupied(x, y)){
        field->getField()[x][y] = symbol;
    }
}

// Handles a robot taking damage at a specific position
void Robot::takeDamage(int x, int y){
    Node* curr = Simulation::rLst.getHead();
    while(curr){
        // Check if the current node's robot is at the position where damage occurred
        if((curr->robot->getX() == x) && (curr->robot->getY() == y)){
            curr->robot->setLives(1);
            if(curr->robot->getLives() > 0){
                Simulation::respawnQueue.enqueue(curr->robot);   // Enqueue the robot for respawn
                Simulation::rLst.deleteNode(curr);         // Remove the robot from the active list
            }   
            else
                Simulation::rLst.deleteNode(curr); // Remove the robot (out of lives)
            break;
        }
        curr = curr->next;
    }
}

// Respawns the robot at a random unoccupied position on the battlefield
void Robot::respawn(){
    do{
        x = rand() % field->getRows();
        y = rand() % field->getCols();
    }while(field->isOccupied(x, y));
}
