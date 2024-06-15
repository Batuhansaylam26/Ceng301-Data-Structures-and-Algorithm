//SortedLinkedList.h
//You can modify this file if needed, do not change the name of the class
#ifndef SORTED_LINKED_LIST_H
#define SORTED_LINKED_LIST_H

#include<iostream>
#include<string>

class LinkedListNode;
class User;

class SortedLinkedList {


public:
    LinkedListNode *head;

    // define new functions if needed
    // remove existing functions if needed
    SortedLinkedList();
    ~SortedLinkedList();
    bool isEmpty() const;
    bool add(User *u); // you can change the return type if needed
    bool remove(int userId); // you can change the return type if needed
    bool checkIfExist(int userId);  // you may erase this function if needed
    LinkedListNode *getPointerTo(int userId); // you may erase this function if needed
    void print();
    // add more functions if needed
};

#endif
