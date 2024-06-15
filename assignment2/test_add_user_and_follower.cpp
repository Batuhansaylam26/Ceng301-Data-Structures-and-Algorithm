#include <iostream>
using namespace std;

#include "SocialMediaPlatform.h"

int main() {

    string truth_table[2] = {"false", "true"};

    SocialMediaPlatform SMP;
    
    SMP.showAllUsers();
    cout<<endl;

    cout<<truth_table[SMP.addUser( 3, "Ali" )]<<endl;
    cout<<truth_table[SMP.addUser( 2, "Ayse" )]<<endl;
    cout<<truth_table[SMP.addUser( 4, "Fatma" )]<<endl;
    cout<<truth_table[SMP.addUser( 4, "Bora" )]<<endl;
    cout<<truth_table[SMP.addUser( 1, "Pelin" )]<<endl;
    
    SMP.showAllUsers();
    cout<<endl;
    
    cout<<truth_table[SMP.followUser( 1, 2)]<<endl;
    cout<<truth_table[SMP.followUser( 1, 3)]<<endl;
    cout<<truth_table[SMP.followUser( 1, 4)]<<endl;
    cout<<endl;
    
    cout<<truth_table[SMP.followUser( 2, 1)]<<endl;
    cout<<truth_table[SMP.followUser( 2, 3)]<<endl;
    cout<<truth_table[SMP.followUser( 2, 4)]<<endl;
    cout<<endl;
    
    cout<<truth_table[SMP.followUser( 3, 1)]<<endl;
    cout<<truth_table[SMP.followUser( 3, 2)]<<endl;
    cout<<truth_table[SMP.followUser( 3, 4)]<<endl;
    cout<<endl;
    
    cout<<truth_table[SMP.followUser( 4, 1)]<<endl;
    cout<<truth_table[SMP.followUser( 4, 2)]<<endl;
    cout<<truth_table[SMP.followUser( 4, 3)]<<endl;
    cout<<endl;
    
    cout<<truth_table[SMP.followUser( 1, 2)]<<endl;
    cout<<truth_table[SMP.followUser( 1, 3)]<<endl;
    cout<<truth_table[SMP.followUser( 1, 4)]<<endl;
    cout<<endl;
    
    
    SMP.showFollowersOf(1);
    cout<<endl;
    SMP.showFollowersOf(2);
    cout<<endl;
    SMP.showFollowersOf(3);
    cout<<endl;
    SMP.showFollowersOf(4);
    cout<<endl;
    SMP.showFollowersOf(4);
    cout<<endl;
    
    

    return 0;
}
