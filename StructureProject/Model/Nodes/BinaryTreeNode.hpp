//
//  BinaryTreeNode.hpp
//  StructureProject
//
//  Created by Phillips, Ryan on 4/12/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

include "Node.hpp"

#ifndef BinaryTreeNode_hpp
#define BinaryTreeNode_hpp

template <class Type>
class BinaryTreeNode : public Node<Type>
{
protected:
    BinaryTreeNode<Type> * root;
    BinaryTreeNode<Type> * leftChild;
    BinaryTreeNode<Type> * rightChild;
public:
    BinaryTreeNode();
    BinaryTreeNode(Type data);
    BinaryTreeNode(Type data,
                   BinaryTreeNode<Type> * root,
                   BinaryTreeNode<Type> * leftChild,
                   BinaryTreeNode<Type> * rightChild);
    
    BinaryTreeNode<Type> * getRoot();
    BinaryTreeNode<Type> * getRightChild();
    BinaryTreeNode<Type> * getLeftChild();
    
    void setRoot(BinaryTreeNode<Type> * root);
    void setLeftChild(BinaryTreeNode<Type> * leftChild);
    void setRightChild(BinaryTreeNode<Type> * rightChild);
};

template <class Type>
BinaryTreeNode<Type> :: BinaryTreeNode() : Node<Type>()
{
    this->root = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

template <class Type>
BinaryTreeNode<Type> : BinaryTreeNode(Type data) : Node<Type>(data)
{
    this->root = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

template <class Type>
BinaryTreeNode<Type> :: BinaryTreeNode(Type data, BinaryTreeNode<Type> * root, BinaryTreeNode<Type> * leftChild, BinaryTreeNode<Type> * rightChild) : Node<Type>(data)
{
    this->root = root;
    this->leftChild = leftChild;
    this->rightChild = rightChild;
}

template <class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getRoot()
{
    return root;
}

template <class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getLeftChild()
{
    return leftChild;
}

template <class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getRightChild()
{
    return rightChild;
}

template <class Type>
void BinaryTreeNode<Type> :: setRoot(BinaryTreeNode * root)
{
    this->root = root;
}

template <class Type>
void BinaryTreeNode<Type> :: setLeftChild(BinaryTreeNode * leftChild)
{
    this->leftChild = leftChild;
}

template <class Type>
void BinaryTreeNode<Type> :: setRightChild(BinaryTreeNode * rightChild)
{
    this->rightChild = rightChild;
}

#endif /* BinaryTreeNode_hpp */
