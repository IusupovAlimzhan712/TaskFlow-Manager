#ifndef RobotList_h
#define RobotList_h

#include "Node.h"

class RobotList{
    Node* head;   // Pointer to the first node in the list
    Node* tail;   // Pointer to the last node in the list
    public:
    RobotList(){
        head = nullptr;
        tail = nullptr;
    }
    ~RobotList();

    // Methods to manipulate the list
    void add(Robot* robot);
    void deleteNode(Node* node);
    Node* getHead() {return head;}
};


#endif