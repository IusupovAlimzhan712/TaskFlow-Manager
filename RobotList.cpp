#include "RobotList.h"

// Adds a new robot to the end of the list
void RobotList::add(Robot* robot){
    Node* newNode = new Node(robot);
    if(!head)
        head = tail = newNode;
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

// Deletes a specific node from the list
void RobotList::deleteNode(Node* node){
    if(node == head){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = head;
    while(prev && prev->next != node){
        prev = prev->next;
    }

    if(!prev || !prev->next){
        cout << "Node not found" << endl; 
        exit(-1);
    }

    Node* toDelete = prev->next;
    prev->next = toDelete->next;
    if(toDelete == tail){
        tail = prev;
    }

    delete toDelete;
}

// Destructor: Deallocates memory for all nodes and robots in the list
RobotList::~RobotList() {
    Node* curr = head;
    while (curr) {
        delete curr->robot;
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}
