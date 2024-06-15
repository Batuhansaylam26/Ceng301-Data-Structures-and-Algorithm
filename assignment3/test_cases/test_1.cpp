#include<iostream>
#include<string>
#include "SpecialBinaryTree.h"

using namespace std;

int main() {

    string truth_table[2] = {"false", "true"};

    SpecialBinaryTree t;

    cout<<truth_table[t.add_node( 8, -1, false, false, true)]<<endl; // we are adding the root node
    cout<<truth_table[t.add_node( 5, -1, false, false, true)]<<endl; /* we can't add a second root while there is a current root */
    cout<<truth_table[t.add_node( 3, 8, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 5, 8, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 1, 5, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 2, 5, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 4, 3, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 5, 3, false, true, false)]<<endl; /* operation should not be allowed since there is already a node with value 5 */
    cout<<truth_table[t.add_node( 6, 3, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 11, 5, false, true, false)]<<endl; /* operation should not be allowed since the node with value 5 already has a right child */
    cout<<endl;

    cout<<truth_table[t.remove_node( 5 )]<<endl;
    cout<<truth_table[t.remove_node( 11 )]<<endl; /* operation should not be allowed since there is no node with value 11 */
    cout<<truth_table[t.update_value(8, 6)]<<endl; /* operation should not be allowed since there is already a node with value 6, therefore 6 cannot be the new value of a node */
    cout<<truth_table[t.update_value(8, 9)]<<endl;
    cout<<endl;

    t.preorder_traversal();
    cout<<endl;
    t.postorder_traversal();
    cout<<endl;
    t.inorder_traversal();
    cout<<endl;

    cout<<t.is_leaf_node( 5 )<<endl; /* Since there is no node with value 5 (node with value 5 is removed in one of the previous operations), return value shoud be -1 */

    cout<<t.is_leaf_node( 3 )<<endl; /* Since the node with value 3 is not a leaf node, return value should be 0 */

    cout<<t.is_leaf_node( 2 )<<endl; /* Since the node with value 2 is a leaf node, return value shoud be 1 */
    cout<<endl;

    cout<<truth_table[t.does_exist_in_subtree(1,1)]<<endl;
    cout<<truth_table[t.does_exist_in_subtree(1,2)]<<endl;
    cout<<truth_table[t.does_exist_in_subtree(1,9)]<<endl; /* Since the node with value 9, is not in the subtree rooted at the node with value 1, return value should be false */
    cout<<truth_table[t.does_exist_in_subtree(1,10)]<<endl; /* Since there is no node with value 10, return value should be false */
    cout<<endl;

    cout<<"Depth of node with value 6: " << t.find_depth(6)<<endl;
    cout<<"Height of node with value 6: " << t.find_height(6)<<endl;
    cout<<endl;

    cout<<"Sum of values: " << t.find_sum_of_values_in_subtree(9)<<endl;
    cout<<"Minimum value: " << t.find_minimum_value_in_subtree(9)<<endl;
    cout<<"Maximum value: " << t.find_maximum_value_in_subtree(9)<<endl;

    return 0;
}