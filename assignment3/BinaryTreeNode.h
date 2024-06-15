// BinaryTreeNode.h
// DO NOT MODIFY THIS FILE
#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H
class BinaryTreeNode
{
private:
int value;
BinaryTreeNode *left;
BinaryTreeNode *right;
public:
BinaryTreeNode();
~BinaryTreeNode();
int get_value();
void set_value(int value);
BinaryTreeNode* get_left();
void set_left(BinaryTreeNode* left);
BinaryTreeNode* get_right();
void set_right(BinaryTreeNode* right);
};
#endif