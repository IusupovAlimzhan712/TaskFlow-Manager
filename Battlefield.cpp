#include <iostream>
#include <fstream>

#include "Battlefield.h"
using namespace std;

// Constructor: Initializes the battlefield
Battlefield::Battlefield(int m, int n){
    rows = m;
    cols = n;
    field = new char* [rows];
    for (int i = 0; i < rows; ++i) {
        field[i] = new char[cols];
        for (int j = 0; j < cols; ++j) {
            field[i][j] = '.';
        }
    }
}

// Destructor: Cleans up the dynamically allocated memory
Battlefield::~Battlefield(){
    for(int i = 0; i < rows; i++){
        delete[] field[i];   // Delete each row
    }
    delete[] field;     // Delete the array of rows
}

void Battlefield::display() const {
    cout << "#";
    for (int i = 0; i < cols; i++) {
        cout << "---";
    }
    cout << "#" << endl;

    for (int i = 0; i < rows; i++) {
        cout << '|';
        for (int j = 0; j < cols; j++) {
            cout << " " << field[i][j] << " ";
        }
        cout << '|' << endl;
    }

    cout << "#";
    for (int i = 0; i < cols; i++) {
        cout << "---";
    }
    cout << "#" << endl;
}

void Battlefield::updatePosition(int oldX, int oldY, 
                  int newX, int newY, char symbol){
    field[oldX][oldY] = '.';
    field[newX][newY] = symbol;
}

bool Battlefield::isOccupied(int x, int y) const{
    return field[x][y] != '.';
}

bool Battlefield::isInBounds(int x, int y) const {
    return (x >= 0 && x < rows) && (y >= 0 && y < cols);
}

// Display the battlefield to a file
void Battlefield::displayToFile(ofstream& out) const {
    out << "#";
    for (int i = 0; i < cols; i++) {
        out << "---";
    }
    out << "#" << endl;

    for (int i = 0; i < rows; i++) {
        out << '|';
        for (int j = 0; j < cols; j++) {
            out << " " << field[i][j] << " ";
        }
        out << '|' << endl;
    }

    out << "#";
    for (int i = 0; i < cols; i++) {
        out << "---";
    }
    out << "#" << endl << endl << endl;
}
