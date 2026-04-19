#ifndef Robot_h
#define Robot_h

#include "Battlefield.h"

class Robot{
    // Robot's Attributes
    protected:
    string name;
    char symbol;
    Battlefield* field;
    int x, y;
    int lives = 3;
    int kills = 0;
    public:
    Robot(Battlefield* _field, int _x, int _y, char _symbol, string _name);

    // Pure virtual functions (must be implemented by derived classes)
    virtual void look() = 0;
    virtual void move() = 0;
    virtual void fire() = 0;
    virtual void step() = 0;
    virtual void taketurn() = 0;
    virtual void PrintStatusFile(ofstream& out) const = 0; 

    // Getter methods
    char getType() {return symbol;}
    int getX() {return x;}
    int getY() {return y;}
    string getName() { return name; }
    int getKills() { return kills; }
    int getLives() {return lives;}

    // Setter method
    void setLives(int x) { lives -= x;}

    void respawn();    // Respawns the robot after losing a life
    void takeDamage(int x, int y);    // Handles the robot taking damage at the given position
};


#endif