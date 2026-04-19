#include "RobotQueue.h"

// Enqueues (adds) a robot to the rear of the queue
void RobotQueue::enqueue(Robot* robot){
    QueueNode* newNode = new QueueNode(robot);
    if(!front)
        front = rear = newNode;
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeues (removes) and returns a robot from the front of the queue
Robot* RobotQueue::dequeue(){
    if(!front)
        return nullptr;
    
    QueueNode* temp = front;
    front = front->next;
    if(!front)
        rear = nullptr;
    Robot* robot = temp->robot;
    delete temp;
    return robot;
}

// Destructor: Deallocates memory for all QueueNodes in the queue
RobotQueue::~RobotQueue() {
    while (front) {
        QueueNode* temp = front;
        front = front->next;
        delete temp;
    }
}