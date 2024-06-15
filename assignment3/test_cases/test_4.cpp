#include<iostream>
#include<string>
#include "SpecialBinaryTree.h"

using namespace std;

int main() {

    string truth_table[2] = {"false", "true"};

    SpecialBinaryTree t;

    cout<<truth_table[t.add_node( 4, -1, false, false, true)]<<endl; // we are adding the root node
    cout<<truth_table[t.add_node( 8, 4, true, false, false)]<<endl; 
    cout<<truth_table[t.add_node( 2, 4, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 16, 8, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 1, 8, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 7, 1, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 3, 2, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 9, 3, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 5, 2, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 10, 3, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 6, 10, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 11, 6, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 13, 11, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 12, 11, true, false, false)]<<endl;
    cout<<endl;

    t.preorder_traversal();
    cout<<endl;
    t.postorder_traversal();
    cout<<endl;
    t.inorder_traversal();
    cout<<endl;

    cout<<truth_table[t.does_exist_in_subtree(4,13)]<<endl;
    cout<<truth_table[t.does_exist_in_subtree(4,14)]<<endl;
    cout<<truth_table[t.does_exist_in_subtree(10,12)]<<endl;
    cout<<truth_table[t.does_exist_in_subtree(10,5)]<<endl;
    cout<<truth_table[t.does_exist_in_subtree(7,7)]<<endl;
    cout<<truth_table[t.does_exist_in_subtree(7,8)]<<endl;
    cout<<truth_table[t.does_exist_in_subtree(20,40)]<<endl;
    cout<<endl;
    
    cout << t.find_depth(1) <<  endl;
    cout << t.find_height(1) << endl;
    cout << endl;
    
    cout << t.find_depth(2) <<  endl;
    cout << t.find_height(2) << endl;
    cout << endl;
    
    cout << t.find_depth(3) <<  endl;
    cout << t.find_height(3) << endl;
    cout << endl;
    
    cout << t.find_depth(4) <<  endl;
    cout << t.find_height(4) << endl;
    cout << endl;
    
    cout << t.find_depth(5) <<  endl;
    cout << t.find_height(5) << endl;
    cout << endl;
    
    cout << t.find_depth(6) <<  endl;
    cout << t.find_height(6) << endl;
    cout << endl;
    
    cout << t.find_depth(7) <<  endl;
    cout << t.find_height(7) << endl;
    cout << endl;
    
    cout << t.find_depth(8) <<  endl;
    cout << t.find_height(8) << endl;
    cout << endl;
    
    cout << t.find_depth(9) <<  endl;
    cout << t.find_height(9) << endl;
    cout << endl;
    
    cout << t.find_depth(10) <<  endl;
    cout << t.find_height(10) << endl;
    cout << endl;
    
    cout << t.find_depth(11) <<  endl;
    cout << t.find_height(11) << endl;
    cout << endl;
    
    cout << t.find_depth(12) <<  endl;
    cout << t.find_height(12) << endl;
    cout << endl;
    
    cout << t.find_depth(13) <<  endl;
    cout << t.find_height(13) << endl;
    cout << endl;
    
    cout << t.find_depth(14) <<  endl; /* It should return -1 since there is no node with value 14 */
    cout << t.find_height(14) << endl; /* It should return -1 since there is no node with value 14 */
    cout << endl;
    
    cout << t.find_depth(15) <<  endl; /* It should return -1 since there is no node with value 15 */
    cout << t.find_height(15) << endl; /* It should return -1 since there is no node with value 15 */
    cout << endl;
    
    cout << t.find_depth(16) <<  endl;
    cout << t.find_height(16) << endl;
    cout << endl;

    return 0;
}