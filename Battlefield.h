#ifndef Battlefield_H
#define Battlefield_H
#include <iostream>
#include <fstream>
using namespace std;

class Battlefield{
    int rows;
    int cols;
    char **field;    // 2D array to represent the battlefield grid
    public:
    Battlefield(int m, int n);
    ~Battlefield();
    void display() const;
    void updatePosition(int oldX, int oldY,
         int newX, int newY, char symbol);   // Update the position of the robot on the battlefield
    bool isOccupied(int x, int y) const;     // Check if a position is occupied
    bool isInBounds(int x, int y) const;     // Check if a position is within the battlefield's boundaries
    char** getField() {return field;}
    int getRows() {return rows;}
    int getCols() {return cols;}
    void displayToFile(ofstream& out) const;  // Display the battlefield to a file
};


#endif