#ifndef RobotQueue_h
#define RobotQueue_h

#include "QueueNode.h"

class RobotQueue{
    QueueNode* front;    // Pointer to the front (first element) of the queue
    QueueNode* rear;     // Pointer to the rear (last element) of the queue
    public:
    RobotQueue(){
        front = rear = nullptr;
    }
    ~RobotQueue();

    // Methods for queue operations:
    void enqueue(Robot* robot);
    Robot* dequeue();
    bool isEmpty() {return front == nullptr;}
};


#endif