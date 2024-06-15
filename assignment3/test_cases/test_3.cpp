#include<iostream>
#include<string>
#include "SpecialBinaryTree.h"

using namespace std;

int main() {

    string truth_table[2] = {"false", "true"};

    SpecialBinaryTree t;

    cout<<truth_table[t.add_node( 1, -1, false, false, true)]<<endl; // we are adding the root node
    cout<<truth_table[t.add_node( 2, 1, true, false, false)]<<endl; 
    cout<<truth_table[t.add_node( 3, 1, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 4, 2, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 5, 2, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 6, 3, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 7, 3, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 8, 4, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 9, 4, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 10, 5, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 11, 5, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 12, 7, false, true, false)]<<endl;
    cout<<endl;

    cout<<truth_table[t.update_value(7, 2)]<<endl; /* operation should not be allowed since there is already a node with value 2, therefore 2 cannot be the new value of a node */
    cout<<truth_table[t.update_value(40, 20)]<<endl; /* operation should not be allowed since there is no node with value 40 */
    cout<<truth_table[t.update_value(7, 13)]<<endl;
    cout<<endl;

    t.preorder_traversal();
    cout<<endl;
    t.postorder_traversal();
    cout<<endl;
    t.inorder_traversal();
    cout<<endl;

    cout << t.find_sum_of_values_in_subtree(1)<<endl;
    cout << t.find_minimum_value_in_subtree(1)<<endl;
    cout << t.find_maximum_value_in_subtree(1)<<endl;
    cout<<endl;

    cout << t.find_sum_of_values_in_subtree(2)<<endl;
    cout << t.find_minimum_value_in_subtree(2)<<endl;
    cout << t.find_maximum_value_in_subtree(2)<<endl;
    cout<<endl;

    cout << t.find_sum_of_values_in_subtree(3)<<endl;
    cout << t.find_minimum_value_in_subtree(3)<<endl;
    cout << t.find_maximum_value_in_subtree(3)<<endl;
    cout<<endl;

    cout << t.find_sum_of_values_in_subtree(4)<<endl;
    cout << t.find_minimum_value_in_subtree(4)<<endl;
    cout << t.find_maximum_value_in_subtree(4)<<endl;
    cout<<endl;

    cout << t.find_sum_of_values_in_subtree(5)<<endl;
    cout << t.find_minimum_value_in_subtree(5)<<endl;
    cout << t.find_maximum_value_in_subtree(5)<<endl;
    cout<<endl;

    cout << t.find_sum_of_values_in_subtree(6)<<endl;
    cout << t.find_minimum_value_in_subtree(6)<<endl;
    cout << t.find_maximum_value_in_subtree(6)<<endl;
    cout<<endl;

    cout << t.find_sum_of_values_in_subtree(7)<<endl; /* Will return -1 since there is no node with value 7, (value 7 is previously updated to 13)*/
    cout << t.find_minimum_value_in_subtree(7)<<endl; /* Will return -1 since there is no node with value 7, (value 7 is previously updated to 13)*/
    cout << t.find_maximum_value_in_subtree(7)<<endl; /* Will return -1 since there is no node with value 7, (value 7 is previously updated to 13)*/
    cout<<endl;

    cout << t.find_sum_of_values_in_subtree(8)<<endl;
    cout << t.find_minimum_value_in_subtree(8)<<endl;
    cout << t.find_maximum_value_in_subtree(8)<<endl;
    cout<<endl;

    cout << t.find_sum_of_values_in_subtree(9)<<endl;
    cout << t.find_minimum_value_in_subtree(9)<<endl;
    cout << t.find_maximum_value_in_subtree(9)<<endl;
    cout<<endl;

    cout << t.find_sum_of_values_in_subtree(10)<<endl;
    cout << t.find_minimum_value_in_subtree(10)<<endl;
    cout << t.find_maximum_value_in_subtree(10)<<endl;
    cout<<endl;

    cout << t.find_sum_of_values_in_subtree(11)<<endl;
    cout << t.find_minimum_value_in_subtree(11)<<endl;
    cout << t.find_maximum_value_in_subtree(11)<<endl;
    cout<<endl;

    cout << t.find_sum_of_values_in_subtree(12)<<endl;
    cout << t.find_minimum_value_in_subtree(12)<<endl;
    cout << t.find_maximum_value_in_subtree(12)<<endl;
    cout<<endl;

    cout << t.find_sum_of_values_in_subtree(13)<<endl;
    cout << t.find_minimum_value_in_subtree(13)<<endl;
    cout << t.find_maximum_value_in_subtree(13)<<endl;
    cout<<endl;

    return 0;
}