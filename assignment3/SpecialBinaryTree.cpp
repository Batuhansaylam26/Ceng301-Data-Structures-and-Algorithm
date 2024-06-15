// SpecialBinaryTree.cpp
#include "SpecialBinaryTree.h"
#include "BinaryTreeNode.h"
#include <climits>
#include <iostream>

using namespace std;

SpecialBinaryTree::SpecialBinaryTree()
{
    root=new BinaryTreeNode();
}

SpecialBinaryTree::~SpecialBinaryTree()
{

    BinaryTreeNode* current = root;
    while (current) {
        if (!current->get_left()) {
            BinaryTreeNode* temp = current;
            current = current->get_right();
            delete temp;
        } else {
            BinaryTreeNode* pre = current->get_left();
            while (pre->get_right() && pre->get_right() != current) {
                pre = pre->get_right();
            }

            if (!pre->get_right()) {
                pre->set_right(current);
                current = current->get_left();
            } else {
                pre->set_right(nullptr);
                BinaryTreeNode* temp = current;
                current = current->get_right();
                delete temp;
            }
        }
    }
}

bool SpecialBinaryTree::add_node(int new_value, int parent_value, bool is_left_child, bool is_right_child, bool is_root)
{
    if(find_node(root,new_value)){
        return false;
    }
    if(is_root){
        if(root->get_value()){
            return false;
        } else if(parent_value==-1){
            root=new BinaryTreeNode();
            root->set_value(new_value);
            return true;
        }
    }

    BinaryTreeNode * tmpptr=find_node(root,parent_value);
    if(is_left_child && tmpptr->get_left() == nullptr){
        BinaryTreeNode* new_node = new BinaryTreeNode();
        new_node->set_value(new_value);
        tmpptr->set_left(new_node);
        return true;
    }
    if(is_right_child && tmpptr->get_right() == nullptr){
        BinaryTreeNode* new_node = new BinaryTreeNode();
        new_node->set_value(new_value);
        tmpptr->set_right(new_node);
        return true;
    }

    return false;
        
    
}

bool SpecialBinaryTree::update_value(int previous_value, int new_value)
{   
    if(find_node(root, new_value)){
        return false;
    }
    BinaryTreeNode* node = find_node(root, previous_value);
    if (!node){
        return false;
    }
    node->set_value( new_value);
    return true;
}


bool SpecialBinaryTree::remove_node(int value) {
    BinaryTreeNode* node = find_node(root, value);
    if (!node) {
        return false;
    }

    if (!node->get_left() && !node->get_right()) {
        delete node;
        node = nullptr;
        return true;
    }

    if (node->get_left()) {
        node->set_value(node->get_left()->get_value());
        remove_node2(node, node->get_left());
        return true;
    }

    if (node->get_right()) {
        node->set_value(node->get_right()->get_value());
        remove_node2(node, node->get_right());
        return true;
    }

    return false;
}

void SpecialBinaryTree::remove_node2(BinaryTreeNode* parent, BinaryTreeNode* node) {
    if (!node) {
        return;
    }

    if (!node->get_left() && !node->get_right()) {
        if (parent->get_left() == node) {
            parent->set_left(nullptr);
        } else if (parent->get_right() == node) {
            parent->set_right(nullptr);
        }
        delete node;
        node = nullptr;
        return;
    }

    if (node->get_left()) {
        node->set_value(node->get_left()->get_value());
        remove_node2(node, node->get_left());
        return;
    }

    if (node->get_right()) {
        node->set_value(node->get_right()->get_value());
        remove_node2(node, node->get_right());
        return;
    }
}

int SpecialBinaryTree::is_leaf_node(int value)
{
    BinaryTreeNode* node = find_node(root, value);
    if (!node){
        return -1;
    }
    return (node->get_left() == nullptr && node->get_right() == nullptr) ? 1 : 0;       
}

bool SpecialBinaryTree::does_exist_in_subtree(int subtree_root_value, int value_to_search) {
    BinaryTreeNode* tmpptr = find_node(root, subtree_root_value);
    if (tmpptr==nullptr) {
        return false;
    }
    if (tmpptr->get_value() == value_to_search) {
        return true;
    }
    if (find_node(tmpptr, value_to_search) != nullptr) {
        return true;
    }
    return false;
}


int SpecialBinaryTree::find_depth2(BinaryTreeNode* node, int value, int depth) {
    if (!node) {
        return -1; 
    }
    if (node->get_value() == value) {
        return depth; 
    }
    
    int left_depth = find_depth2(node->get_left(), value, depth + 1);
    if (left_depth != -1) {
        return left_depth; 
    }

    return find_depth2(node->get_right(), value, depth + 1);
}

int SpecialBinaryTree::find_depth(int value) {
    return find_depth2(root, value, 0); 
}

int SpecialBinaryTree::find_height(int value) {
    BinaryTreeNode* node = find_node(root, value);
    if (!node) {
        return -1; 
    }

    if (node->get_left() == nullptr && node->get_right() == nullptr) {
        return 0;
    }

    int left_height = node->get_left()!=nullptr ? find_height(node->get_left()->get_value()) : -1;
    int right_height = node->get_right()!=nullptr ? find_height(node->get_right()->get_value()) : -1;

    return 1 + std::max(left_height, right_height);
}

void SpecialBinaryTree::preorder_traversal(){
    if (root->get_value()==0) {
        cout<<"There is no node in the tree." << endl;
        return;
    }
    BinaryTreeNode* tmpptr = root;
    while (tmpptr != nullptr) {
        if (tmpptr->get_left() == nullptr) {
            cout << tmpptr->get_value() << " ";
            tmpptr = tmpptr->get_right();
        } else {
            BinaryTreeNode* pre = tmpptr->get_left();
            while (pre->get_right() != nullptr && pre->get_right() != tmpptr) {
                pre = pre->get_right();
            }

            if (pre->get_right() == nullptr) {
                cout << tmpptr->get_value() << " ";
                pre->set_right(tmpptr);
                tmpptr = tmpptr->get_left();
            } else {
                pre->set_right(nullptr);
                tmpptr = tmpptr->get_right();
            }
        }
    }
    cout << endl;
}


void SpecialBinaryTree::postorder_traversal2(BinaryTreeNode* node) {
    if (node == nullptr) {
        return;
    }

    postorder_traversal2(node->get_left());
    postorder_traversal2(node->get_right());

    cout << node->get_value() << " ";
}

void SpecialBinaryTree::postorder_traversal() {
    if (root->get_value()==0) {
        cout<<"There is no node in the tree." << endl;
        return;
    }

    postorder_traversal2(root);

    cout << endl;
}




void SpecialBinaryTree::inorder_traversal()
{
    if (root->get_value()==0) {
        cout<<"There is no node in the tree." << endl;

        return ;
    }
    BinaryTreeNode* current = root;
    while (current != nullptr) {
        if (current->get_left() == nullptr) {
            cout << current->get_value() << " ";
            current = current->get_right();
        } else {
            BinaryTreeNode* pre = current->get_left();
            while (pre->get_right() != nullptr && pre->get_right() != current) {
                pre = pre->get_right();
            }

            if (pre->get_right() == nullptr) {
                pre->set_right(current);
                current = current->get_left();
            } else {
                pre->set_right(nullptr);
                cout << current->get_value() << " ";
                current = current->get_right();
            }
        }
    }
    cout << endl;
}

int SpecialBinaryTree::find_sum_of_values_in_subtree(int subtree_root_val) {
    BinaryTreeNode* node = find_node(root, subtree_root_val);
    if (!node) {
        return -1; 
    }

    if (node->get_value() == 0) {
        return 0; 
    }

    int sum = node->get_value();
    if (node->get_left()) {
        sum += find_sum_of_values_in_subtree(node->get_left()->get_value());
    }
    if (node->get_right()) {
        sum += find_sum_of_values_in_subtree(node->get_right()->get_value());
    }

    return sum;
}



int SpecialBinaryTree::find_minimum_value_in_subtree(int subtree_root_val) {
    BinaryTreeNode* node = find_node(root, subtree_root_val);
    if (node == nullptr) {
        return -1; 
    }

    int min = subtree_root_val;

    if (node->get_left() != nullptr) {
        int lfind_min = find_minimum_value_in_subtree(node->get_left()->get_value());
        if (lfind_min != -1 && lfind_min < min) {
            min = lfind_min;
        }
    }

    if (node->get_right() != nullptr) {
        int rfind_min = find_minimum_value_in_subtree(node->get_right()->get_value());
        if (rfind_min != -1 && rfind_min < min) {
            min = rfind_min;
        }
    }

    return min;
}

int SpecialBinaryTree::find_maximum_value_in_subtree(int subtree_root_val) {
    BinaryTreeNode* node = find_node(root, subtree_root_val);
    if (node == nullptr) {
        return -1; 
    }

    int max = subtree_root_val;

    if (node->get_left() != nullptr) {
        int lfind_max = find_maximum_value_in_subtree(node->get_left()->get_value());
        if (lfind_max != -1 && lfind_max > max) {
            max = lfind_max;
        }
    }

    if (node->get_right() != nullptr) {
        int rfind_max = find_maximum_value_in_subtree(node->get_right()->get_value());
        if (rfind_max != -1 && rfind_max > max) {
            max = rfind_max;
        }
    }

    return max;
}


BinaryTreeNode * SpecialBinaryTree::find_node(BinaryTreeNode * node,int value, BinaryTreeNode** parent){
    if(!node){
        return nullptr;
    }
    if(node->get_value() == value){
        return node;
    }
    if(node->get_left()){
        *parent = node;
        BinaryTreeNode * leftNode=find_node(node->get_left(),value,parent);
        if(leftNode){
            return leftNode;
        }
    }
    if(node->get_right()){
        *parent = node;
        BinaryTreeNode * rightNode=find_node(node->get_right(),value,parent);
        if(rightNode){
            return rightNode;
        }
    }

    return nullptr;
}

BinaryTreeNode* SpecialBinaryTree::find_node(BinaryTreeNode* node, int value)
{
    if(!node){
        return nullptr;
    }
    if(node->get_value() == value){
        return node;
    }
    if(node->get_left()){
        BinaryTreeNode * leftNode=find_node(node->get_left(),value);
        if(leftNode){
            return leftNode;
        }
    }
    if(node->get_right()){
        BinaryTreeNode * rightNode=find_node(node->get_right(),value);
        if(rightNode){
            return rightNode;
        }
    }

    return nullptr;
}

BinaryTreeNode* SpecialBinaryTree::find_parent(BinaryTreeNode* node, int value)
{
    if (!node || node->get_value() == value){
        return nullptr;
    }
    if ((node->get_left() && node->get_left()->get_value() == value) || (node->get_right() && node->get_right()->get_value() == value)) {
        return node;
    }
    BinaryTreeNode* left_search = find_parent(node->get_left(), value);
    if (left_search){
        return left_search;
    }
    BinaryTreeNode* right_search = find_parent(node->get_right(), value);
    if(right_search){
        return right_search;
    }
    return nullptr;
}




/*
    IF YOU ADDED NEW FUNCTIONS TO SpecialBinaryTree.h IMPLEMENT THEM HERE.
    NOTE THAT, ADDING GLOBAL VARIABLES OR FUNCTIONS IS FORBIDDEN.
*/