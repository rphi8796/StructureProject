//
//  BinaryTreeNode.hpp
//  StructureProject
//
//  Created by Phillips, Ryan on 4/12/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#include "Node.hpp"

#ifndef BinaryTreeNode_hpp
#define BinaryTreeNode_hpp

template <class Type>
class BinaryTreeNode : public Node<Type>
{
protected:
    BinaryTreeNode<Type> * root;
    BinaryTreeNode<Type> * left;
    BinaryTreeNode<Type> * right;
public:
    BinaryTreeNode();
    BinaryTreeNode(Type data);
    BinaryTreeNode(Type data,
                   BinaryTreeNode<Type> * root,
                   BinaryTreeNode<Type> * left,
                   BinaryTreeNode<Type> * right);
    
    BinaryTreeNode<Type> * getRoot();
    BinaryTreeNode<Type> * getRight();
    BinaryTreeNode<Type> * getLeft();
    
    void setRoot(BinaryTreeNode<Type> * root);
    void setLeft(BinaryTreeNode<Type> * left);
    void setRight(BinaryTreeNode<Type> * right);
};

template <class Type>
BinaryTreeNode<Type> :: BinaryTreeNode() : Node<Type>()
{
    this->root = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

template <class Type>
BinaryTreeNode<Type> :: BinaryTreeNode(Type data) : Node<Type>(data)
{
    this->root = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

template <class Type>
BinaryTreeNode<Type> :: BinaryTreeNode(Type data, BinaryTreeNode<Type> * root, BinaryTreeNode<Type> * left, BinaryTreeNode<Type> * right) : Node<Type>(data)
{
    this->root = root;
    this->left = left;
    this->right = right;
}

template <class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getRoot()
{
    return root;
}

template <class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getLeft()
{
    return left;
}

template <class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getRight()
{
    return right;
}

template <class Type>
void BinaryTreeNode<Type> :: setRoot(BinaryTreeNode * root)
{
    this->root = root;
}

template <class Type>
void BinaryTreeNode<Type> :: setLeft(BinaryTreeNode * left)
{
    this->left = left;
}

template <class Type>
void BinaryTreeNode<Type> :: setRight(BinaryTreeNode * right)
{
    this->right = right;
}

#endif /* BinaryTreeNode_hpp */
