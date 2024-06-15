// BinaryTreeNode.cpp
#include "BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode()
{
    value = 0;
    left=nullptr;
    right=nullptr;
}

BinaryTreeNode::~BinaryTreeNode()
{
    /* YOUR CODE HERE */
}

int BinaryTreeNode::get_value()
{
    return value;
}

void BinaryTreeNode::set_value(int value)
{
    this->value=value;
}

BinaryTreeNode* BinaryTreeNode::get_left()
{
    return left;
}

void BinaryTreeNode::set_left(BinaryTreeNode* left)
{
    this->left = left;
}

BinaryTreeNode* BinaryTreeNode::get_right()
{
    return right;
}

void BinaryTreeNode::set_right(BinaryTreeNode* right)
{
    this->right = right;
}
