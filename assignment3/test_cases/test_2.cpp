#include<iostream>
#include<string>
#include "SpecialBinaryTree.h"

using namespace std;

int main() {

    string truth_table[2] = {"false", "true"};

    SpecialBinaryTree t;
    
    t.preorder_traversal();  /* Since currently there are no nodes in the tree, it should print: There is no node in the tree.*/
    cout<<endl;
    t.postorder_traversal(); /* Since currently there are no nodes in the tree, it should print: There is no node in the tree.*/
    cout<<endl;
    t.inorder_traversal();   /* Since currently there are no nodes in the tree, it should print: There is no node in the tree.*/
    cout<<endl;

    cout<<truth_table[t.add_node( 3, -1, false, false, true)]<<endl; // we are adding the root node
    cout<<truth_table[t.add_node( 5, -1, false, false, true)]<<endl; /* we can't add a second root while there is a current root */
    cout<<truth_table[t.add_node( 5, 3, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 7, 3, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 9, 7, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 10, 7, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 1, 5, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 8, 1, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 4, 1, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 11, 7, true, false, false)]<<endl; /* operation should not be allowed since the node with value 7 already has a left child */
    cout<<truth_table[t.add_node( 12, 7, false, true, false)]<<endl; /* operation should not be allowed since the node with value 7 already has a right child */
    cout<<truth_table[t.add_node( 3, 5, true, false, false)]<<endl;  /* operation should not be allowed since there is already a node with value 3 */ 
    cout<<endl;

    t.preorder_traversal();
    cout<<endl;
    t.postorder_traversal();
    cout<<endl;
    t.inorder_traversal();
    cout<<endl;

    cout<<t.is_leaf_node( 1 )<<endl;  /* Since the node with value 1 is not a leaf node, return value should be 0 */
    cout<<t.is_leaf_node( 2 )<<endl;  /* Since there is no node with value 2, return value shoud be -1 */
    cout<<t.is_leaf_node( 3 )<<endl;  /* Since the node with value 1 is not a leaf node, return value should be 0 */
    cout<<t.is_leaf_node( 4 )<<endl;  /* Since the node with value 4 is a leaf node, return value shoud be 1 */
    cout<<t.is_leaf_node( 5 )<<endl;  /* Since the node with value 5 is not a leaf node, return value should be 0 */
    cout<<t.is_leaf_node( 6 )<<endl;  /* Since there is no node with value 6, return value shoud be -1 */
    cout<<t.is_leaf_node( 7 )<<endl;  /* Since the node with value 7 is not a leaf node, return value should be 0 */
    cout<<t.is_leaf_node( 8 )<<endl;  /* Since the node with value 8 is a leaf node, return value shoud be 1 */
    cout<<t.is_leaf_node( 9 )<<endl;  /* Since the node with value 9 is a leaf node, return value shoud be 1 */
    cout<<t.is_leaf_node( 10 )<<endl; /* Since the node with value 10 is a leaf node, return value shoud be 1 */
    cout<<t.is_leaf_node( 11 )<<endl; /* Since there is no node with value 11, return value shoud be -1 */
    cout<<endl;

    return 0;
}