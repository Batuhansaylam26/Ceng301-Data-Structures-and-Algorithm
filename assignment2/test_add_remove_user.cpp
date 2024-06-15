#include<iostream>
#include<string>
#include "SocialMediaPlatform.h"

using namespace std;

int main() {

    string truth_table[2] = {"false", "true"};

    SocialMediaPlatform SMP;

    cout<<truth_table[SMP.addUser( -4, "Mert" )]<<endl;
    cout<<truth_table[SMP.addUser( 5, "Ferhat" )]<<endl;
    cout<<truth_table[SMP.addUser( 8, "Selin" )]<<endl;
    cout<<truth_table[SMP.addUser( 3, "Hatice" )]<<endl;

    SMP.showAllUsers();
    cout<<endl;
    
    cout<<truth_table[SMP.removeUser(3)]<<endl;
 
    SMP.showAllUsers();
    cout<<endl;
    
    cout<<truth_table[SMP.removeUser(-4)]<<endl;
    
    SMP.showAllUsers();
    cout<<endl;
    
    cout<<truth_table[SMP.removeUser(8)]<<endl;
    
    SMP.showAllUsers();
    cout<<endl;
    
    cout<<truth_table[SMP.removeUser(5)]<<endl;

    SMP.showAllUsers();
    cout<<endl;

    return 0;
}
