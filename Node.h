#ifndef Node_h
#define Node_h

#include "Robot.h"

struct Node{
    Robot* robot;
    Node* next;
    Node(Robot* r){
        robot = r;
        next = nullptr;
    }
};

#endif