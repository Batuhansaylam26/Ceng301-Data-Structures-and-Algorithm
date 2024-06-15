#include <iostream>
using namespace std;

#include "SocialMediaPlatform.h"

int main() {

    string truth_table[2] = {"false", "true"};

    SocialMediaPlatform SMP;
    
    SMP.showAllUsers();
    cout<<endl;

    cout<<truth_table[SMP.addUser( 3, "Lonely Artist" )]<<endl;
    cout<<truth_table[SMP.addUser( 2, "Eater Man" )]<<endl;
    cout<<truth_table[SMP.addUser( 4, "Pet Lover" )]<<endl;
    cout<<truth_table[SMP.addUser( 4, "Musician Guy" )]<<endl;
    cout<<truth_table[SMP.removeUser( 4 )]<<endl;
    cout<<truth_table[SMP.addUser( 4, "Cyborg" )]<<endl;
    cout<<truth_table[SMP.addUser( 1, "Gamer" )]<<endl;
    cout<<truth_table[SMP.addUser( 1, "Ali" )]<<endl;
    cout<<truth_table[SMP.removeUser( 7 )]<<endl;
    cout<<truth_table[SMP.addUser( 6, "Sportsman" )]<<endl;
    cout << endl;
    SMP.showAllUsers();
    cout<<endl;

    cout<<truth_table[SMP.followUser(1,6)]<<endl;
    cout<<truth_table[SMP.followUser(1,2)]<<endl;
    cout<<truth_table[SMP.followUser(4,3)]<<endl;
    cout<<truth_table[SMP.followUser(4,6)]<<endl;
    cout<<truth_table[SMP.followUser(4,6)]<<endl;
    cout<<truth_table[SMP.followUser(2,4)]<<endl;
    cout<<truth_table[SMP.followUser(4,2)]<<endl;
    cout<<truth_table[SMP.followUser(2,6)]<<endl;
    cout<<truth_table[SMP.followUser(6,2)]<<endl;
    cout<<truth_table[SMP.followUser(4,7)]<<endl;
    cout<<truth_table[SMP.unfollowUser(1,4)]<<endl;
    cout<<truth_table[SMP.unfollowUser(1, 6)]<<endl;
    cout<<truth_table[SMP.unfollowUser(6, 2)]<<endl;
    cout<<truth_table[SMP.unfollowUser(10, 20)]<<endl;
    cout << endl;

    cout<<truth_table[SMP.removeUser( 5 )]<<endl;
    cout<<truth_table[SMP.removeUser( 3 )]<<endl;
    cout<<truth_table[SMP.removeUser( 1 )]<<endl;
    cout<<endl;

    SMP.showAllUsers();
    cout << endl;
    SMP.showFollowersOf(1);
    cout << endl;
    SMP.showFollowersOf(2);
    cout << endl;
    SMP.showFollowersOf(3);
    cout << endl;
    SMP.showFollowersOf(4);
    cout << endl;
     SMP.showFollowersOf(5);
    cout << endl;    
    SMP.showFollowersOf(6);
    cout << endl;
    SMP.showFollowersOf(10);
    cout << endl;

    return 0;
}
