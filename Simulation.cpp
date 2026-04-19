#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>


#include "Simulation.h"
#include "RoboCop.h"
#include "Terminator.h"
#include "TerminatorRoboCop.h"
#include "BlueThunder.h"
#include "Madbot.h"
#include "RoboTank.h"
#include "UltimateRobot.h"
using namespace std;

// Initialize static members
Battlefield* Simulation::field;
RobotList Simulation::rLst;
RobotQueue Simulation::respawnQueue;

// Constructor: Sets up and runs the simulation
Simulation::Simulation(const string& fileName){
    int steps;
    configFile(fileName, steps);
    run(steps);
}

// Destructor: Cleans up the simulation resources
Simulation::~Simulation(){
    Node* curr = rLst.getHead();
    while(curr){  // Iterate through the robot list, deleting each robot
        if(curr->robot == nullptr){
            delete curr->robot;
        }
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    delete field;
}

// Reads the configuration file and sets up the simulation parameters
void Simulation::configFile(const string& fileName, int& steps){
    ifstream input(fileName);
    if(!input){
        cout << "The file didnt open" << endl;
        exit(-1);
    }

    string line;
    int rows, cols, numOfRobots, posX, posY;
    string type, name, stringX, stringY;

    for(int i = 0; i < 3; i++){
        if(!getline(input, line) || line == ""){
            cout << "Error in the file format.\n" << "Pls refer to the user manual, "
            << "to find out more about the format of the file.\n";
            exit(-1);
        }

        istringstream iss(line);
        string garbage = "";
        getline(iss, garbage, ':');

        if (i == 0){
           if(!(iss >> rows >> cols)){
            cout << "Error in Battlefield dimensions.\n";
            exit(-1);
           } 
        }    
        else if(i == 1){
            if(!(iss >> steps)){
                cout << "Error in steps format.\n";
                exit(-1);
            }
        }
        else if(i == 2){
            if(!(iss >> numOfRobots)){
                cout << "Invalid number of robots.\n";
                exit(-1);
            }
        }
            
    }
    field = new Battlefield(rows, cols);

    for(int i = 0; getline(input, line); i++){
        istringstream iss(line);
        iss >> type >> name >> stringX >> stringY;
        
        if(stringX == "random")
            posX = rand() % field->getRows();
        else
            posX = stoi(stringX);

        if(stringY == "random")
            posY = rand() % field->getCols();
        else
            posY = stoi(stringY);
        
        // Adding robots to rLst according to the type of the robot
        if(type == "RoboCop")
            rLst.add(new RoboCop(field, posX, posY, 'r', name));
        else if(type == "Terminator")
            rLst.add(new Terminator(field, posX, posY, 't', name));
        else if(type == "TerminatorRoboCop")
            rLst.add(new TerminatorRoboCop(field, posX, posY, 'T', name));
        else if(type == "BlueThunder")
            rLst.add(new BlueThunder(field, posX, posY, 'B', name));
        else if(type == "Madbot")
            rLst.add(new Madbot(field, posX, posY, 'M', name));
        else if(type == "RoboTank")
            rLst.add(new RoboTank(field, posX, posY, 'R', name));
        else if(type == "UltimateRobot")
            rLst.add(new UltimateRobot(field, posX, posY, 'U', name));
        else{
            cout << "Error: Enter a valid robot type." << endl;
            exit(-1);
        }
            
    }
}

// Runs the simulation for the specified number of steps
void Simulation::run(int steps){
    srand(time(0));

    ofstream outputFile("robots_info.txt");
    if (!outputFile) {
        cout << "Failed to open output file" << endl;
        return;
    }

    // Print initial status of all robots
    Node* curr = rLst.getHead();
    while(curr != nullptr){
            curr->robot->PrintStatusFile(outputFile);
            curr = curr->next;
    }
    
    field->displayToFile(outputFile);

    // Main simulation loop
    for(int i = 0; i < steps; i++){
        outputFile << "step: " << i+1 << endl;

        // Iterate through each robot and have them take their turn
        Node* curr = rLst.getHead();
        while(curr != nullptr){
            curr->robot->taketurn();
            curr->robot->PrintStatusFile(outputFile);
            curr = curr->next;
        }
        
        // Respawn robots if there are any in the respawn queue
        if(!respawnQueue.isEmpty()){
            Robot* robotToRespawn = respawnQueue.dequeue();
            robotToRespawn->respawn();
            rLst.add(robotToRespawn);
        }

        // Check for and perform robot upgrades based on their kill count
        Node* upgradeRobot = rLst.getHead();
        while(upgradeRobot != nullptr){
            updateRobot(upgradeRobot);
            upgradeRobot = upgradeRobot->next;
        }

        // Display the updated battlefield state
        field->displayToFile(outputFile);
    }
}

// Upgrades robots based on their kill count
void Simulation::updateRobot(Node* curr){
    if(curr->robot->getKills() >= 3){
        if(curr->robot->getType() == 'r' || curr->robot->getType() == 't'){
            rLst.add(new TerminatorRoboCop(field, curr->robot->getX(), curr->robot->getY(), 'T', curr->robot->getName()));
            rLst.deleteNode(curr);
        }
        else if(curr->robot->getType() == 'B'){
            rLst.add(new Madbot(field, curr->robot->getX(), curr->robot->getY(), 'M', curr->robot->getName()));
            rLst.deleteNode(curr);
        }
        else if(curr->robot->getType() == 'M'){
            rLst.add(new RoboTank(field, curr->robot->getX(), curr->robot->getY(), 'R', curr->robot->getName()));
            rLst.deleteNode(curr);
        }
        else if(curr->robot->getType() == 'R' || curr->robot->getType() == 'T'){
            rLst.add(new UltimateRobot(field, curr->robot->getX(), curr->robot->getY(), 'U', curr->robot->getName()));
            rLst.deleteNode(curr);
        }
    }
}