#include "User.h"
#include "SortedLinkedList.h"
#include "LinkedListNode.h"

using namespace std;

// Implement the functions in the "User.h"


User::User() : id(0), name(""), followers(new SortedLinkedList()), followeds(new SortedLinkedList()) {}

User::~User() {
    delete followers;
    delete followeds;
}

int User::getId() {
    return id;
}

void User::setId(int userId) {
    this->id = userId;
}

std::string User::getName() {
    return name;
}

void User::setName(std::string userName) {
    this->name = userName;
}


bool User::addFollower(User *u) {
    // Add the follower to the list of followers
    return followers->add(u);
}

bool User::removeFollower(int userId) {
    // Remove the follower from the list of followers
    return followers->remove(userId);
}

bool User::addFollowed(User *u) {
    // Add the user to the list of followed users
    return followeds->add(u);
}

bool User::removeFollowed(int userId) {
    // Remove the user from the list of followed users
    return followeds->remove(userId);
}

SortedLinkedList* User::getFollowers() {
    // Return the list of followers
    return followers;
}
