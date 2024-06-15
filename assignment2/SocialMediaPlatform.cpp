#include "SocialMediaPlatform.h"
#include "User.h"
#include "SortedLinkedList.h"
#include "LinkedListNode.h"

using namespace std;


SocialMediaPlatform::SocialMediaPlatform() {
    users = new SortedLinkedList(); 
}

SocialMediaPlatform::~SocialMediaPlatform() {
    delete users;
}

bool SocialMediaPlatform::addUser(const int userId, const std::string name) {
    if (users->checkIfExist(userId)) {
        return false;
    }
    User *newUser = new User() ; 
    newUser->setId(userId);
    newUser->setName(name);
    users->add(newUser); 
    return true;
}

bool SocialMediaPlatform::removeUser(const int userId) {
    if (!users->checkIfExist(userId)) {
        return false;
    }
    users->remove(userId); 
    LinkedListNode* curr=users->head;
    while(curr!=nullptr){
        if(curr->u->getFollowers()->checkIfExist(userId)){
            curr->u->removeFollower(userId);
        }
        curr=curr->next;
    }
    return true;
}

bool SocialMediaPlatform::followUser(const int firstUserId, const int secondUserId) {
    LinkedListNode *firstUserNode = users->getPointerTo(firstUserId);
    LinkedListNode *secondUserNode = users->getPointerTo(secondUserId);

    if (firstUserNode == nullptr || secondUserNode == nullptr  ) {
        return false;
    }
    else if(secondUserNode->u->getFollowers()->checkIfExist(firstUserId)){
        return false;
    }else{
        secondUserNode->u->addFollower(firstUserNode->u);
        firstUserNode->u->addFollowed(secondUserNode->u);
        return true;
    }

}

bool SocialMediaPlatform::unfollowUser(const int firstUserId, const int secondUserId) {
    LinkedListNode *firstUserNode = users->getPointerTo(firstUserId);
    LinkedListNode *secondUserNode = users->getPointerTo(secondUserId);

    if (firstUserNode == nullptr || secondUserNode == nullptr) {
        return false;
    }else if(!secondUserNode->u->getFollowers()->checkIfExist(firstUserId)){
        return false;
    }else{
        secondUserNode->u->removeFollower(firstUserId);
        firstUserNode->u->removeFollowed(secondUserId);
        return true;
    }
}

void SocialMediaPlatform::showFollowersOf(const int userId) const {
    LinkedListNode *userNode = users->getPointerTo(userId);
    if (userNode == nullptr) {
        cout << "Cannot show. There is no user with ID " << userId <<"." << endl;
    }
    else{
        LinkedListNode *currentFollowersNode = userNode->u->getFollowers()->head;
        cout<<"Users following the user with ID " <<userId<<":"<<endl;
        if(currentFollowersNode==nullptr) {
            cout<<"None"<<endl;
        }else{
            while(currentFollowersNode!=nullptr){
                cout << currentFollowersNode->u->getId() << ", " << currentFollowersNode->u->getName() << endl;
                currentFollowersNode = currentFollowersNode->next;
            }
        }

    }

}

void SocialMediaPlatform::showAllUsers() const {
    cout << "Users in the social media platform:" << endl;
    if(!users->isEmpty()) {
        LinkedListNode *current = users->head;
        while (current != nullptr) {
            cout << current->u->getId() << ", " << current->u->getName() << endl;
            current = current->next;
        } 
    }else{
        cout<<"None"<<endl;
    }
}
