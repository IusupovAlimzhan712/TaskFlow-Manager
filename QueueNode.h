#ifndef QueueNode_h
#define QueueNode_h

#include "Robot.h"

struct QueueNode{
    Robot* robot;
    QueueNode* next;
    QueueNode(Robot* r){
        robot = r;
        next = nullptr;
    }
};

#endif