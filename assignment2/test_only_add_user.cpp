#include<iostream>
#include<string>
#include "SocialMediaPlatform.h"

using namespace std;

int main() {

    string truth_table[2] = {"false", "true"};

    SocialMediaPlatform SMP;

    cout<<truth_table[SMP.addUser( 3, "Ali" )]<<endl;
    cout<<truth_table[SMP.addUser( 4, "Veli" )]<<endl;
    cout<<truth_table[SMP.addUser( 2, "Hasan" )]<<endl;

    SMP.showAllUsers();
    cout<<endl;

    cout<<truth_table[SMP.addUser( 1, "Huseyin" )]<<endl;
    cout<<truth_table[SMP.addUser( 6, "Burak" )]<<endl;
    cout<<truth_table[SMP.addUser( 5, "Ferit" )]<<endl;

    cout<<truth_table[SMP.addUser( 1, "Huseyin" )]<<endl;
    cout<<truth_table[SMP.addUser( 2, "Hasan" )]<<endl;
    cout<<truth_table[SMP.addUser( 3, "Ali" )]<<endl;
    cout<<truth_table[SMP.addUser( 4, "Veli" )]<<endl;
    cout<<truth_table[SMP.addUser( 5, "Ferit" )]<<endl;
    cout<<truth_table[SMP.addUser( 6, "Burak" )]<<endl;

    SMP.showAllUsers();
    cout<<endl;

    return 0;
}
