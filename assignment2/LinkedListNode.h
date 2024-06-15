//LinkedListNode.h
//You can modify this file if needed, do not change the name of the class
#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

class User;
class SortedLinkedList;

class LinkedListNode {
public:
    User *u;
    LinkedListNode *next;

    // define new functions if needed
    // remove existing functions if needed
    LinkedListNode(User *userPtr = nullptr, LinkedListNode *nextNode = nullptr) : u(userPtr), next(nextNode){


    };

    friend class SortedLinkedList;
};

#endif
