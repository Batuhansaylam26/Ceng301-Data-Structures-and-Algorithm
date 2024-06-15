//SocialMediaPlatform.h
//DO NOT MODIFY THIS FILE
#ifndef SOCIAL_MEDIA_PLATFORM_H
#define SOCIAL_MEDIA_PLATFORM_H

#include<iostream>
#include<string>

#include "SortedLinkedList.h"

class SocialMediaPlatform {

private:
    SortedLinkedList *users;

public:
    SocialMediaPlatform();
    ~SocialMediaPlatform();

    bool addUser( const int userId, const std::string name );
    bool removeUser( const int userId );

    bool followUser( const int firstUserId, const int secondUserId );
    bool unfollowUser( const int firstUserId, const int secondUserId );

    void showFollowersOf( const int userId ) const;

    void showAllUsers( ) const;
};
#endif
