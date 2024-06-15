#include "User.h"
#include "SortedLinkedList.h"
#include "LinkedListNode.h"

#include<iostream>
#include<string>

using namespace std;
bool SortedLinkedList::isEmpty() const {
    return head==nullptr;
}

SortedLinkedList::SortedLinkedList():head(nullptr){}

SortedLinkedList::~SortedLinkedList(){
    LinkedListNode *curr=head;
    while (curr != nullptr){
        LinkedListNode *next=curr ->next;
        delete curr;
        curr=next;
    }
}
bool SortedLinkedList::add(User *u){
    LinkedListNode* newNode= new LinkedListNode(u);
    newNode->next=nullptr;
    if(isEmpty() || head->u->getId() >= newNode->u->getId()){
        newNode->next=head;
        head=newNode;
        return true;
    }
    else{
        LinkedListNode *curr = head;
        while (curr->next != nullptr && curr->next->u->getId() <  newNode->u->getId()) {
            curr = curr->next;

        }
        newNode->next = curr->next;
        curr->next = newNode;
        return true;
    }


}
bool SortedLinkedList::remove(int userId){
    LinkedListNode *curr= head;
    LinkedListNode *previous = nullptr;

    while (curr != nullptr && curr->u->getId() != userId) {
        previous = curr;
        curr = curr->next;
    }

    if (curr== nullptr) {
        cout << "User with ID " << userId << " not found." << endl;
    }

    if (previous == nullptr) {
        head = curr->next;
    } else {
        previous->next = curr->next;
    }

    delete curr;
    return false;
}// you can change the return type if needed
bool SortedLinkedList::checkIfExist(int userId) {
    LinkedListNode *curr = head;
    while (curr != nullptr) {
        if (curr->u->getId() == userId) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

LinkedListNode *SortedLinkedList::getPointerTo(int userId) {
    LinkedListNode *curr = head;
    while (curr != nullptr) {
        if (curr->u->getId() == userId) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

void SortedLinkedList::print() {
    LinkedListNode *curr = head;
    while (curr != nullptr) {
        cout << curr->u->getId();
        if (curr->next != nullptr) {
            cout << " -> ";
        }
        curr = curr->next;
    }
    cout << endl;
}



