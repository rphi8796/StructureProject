//
//  AVLTree.hpp
//  StructureProject
//
//  Created by Phillips, Ryan on 4/30/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include "BinarySearchTree.hpp"

template <class Type>
class AVLTree : public BinarySearchTree<Type>
{
private:
    
    BinaryTreeNode<Type> * leftRotation (BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * rightRotation(BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * leftRightRotation(BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * rightLeftRotation(BinaryTreeNode<Type> * parent);
    
    BinaryTreeNode<Type> * balanceSubTree (BinaryTreeNode<Type> * parent);
    
    BinaryTreeNode<Type> * insertNode(BinaryTreeNode<Type> * parent, Type value);
    BinaryTreeNode<Type> * removeNode(BinaryTreeNode<Type> * parent, Type value);
    
    int heightDifference(BinaryTreeNode<Type> * parent);
    
public:
    AVLTree();
    
    void insert(Type itemToInsert);
    void remove(Type value);
};


/*
 it starts with a parent node and a value to insert and it checks to make sure the parent exists
 and if it doesn't it inserts there but if it does, it inserts it based on comparison by recursion
 and eventually it call the place where it is suppose to be and that place will be empty and it will
 be placed by the if statement.
 */
template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: insertNode(BinaryTreeNode<Type> * parent, Type inserted)
{
    if(parent == nullptr)//if the parent does not exist
    {
        parent = new BinaryTreeNode<Type>(inserted);
        this->setRoot(parent);
        return parent;
    }
    else if(inserted < parent->getData())//node is greater than parent
    {
        parent->setLeft(insertNode(parent->getLeft(), inserted));
        parent = balanceSubTree(parent);
    }
    else if(inserted > parent->getData())//node is less than parent
    {
        parent->setRight(insertNode(parent->getRight(), inserted));
        parent = balanceSubTree(parent);
    }
    return parent;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: removeNode(BinaryTreeNode<Type> * parent, Type inserted)
{
    if(parent == nullptr)
    {
        return parent;
    }
    if(inserted < parent->getData())
    {
        parent->setLeft(removeNode(parent->getLeft(), inserted));
    }
    else if(inserted > parent->getNodeData())
    {
        parent->setRight(removeNode(parent->getRight(), inserted));
    }
    else
    {
        BinaryTreeNode<Type> * temp;
        if(parent->getLeftNode() == nullptr && parent->getRight() == nullptr)//no kids
        {
            temp = parent;
            delete temp;
        }
        else if(parent->getLeft() == nullptr)//right kid
        {
            *parent = *parent->getRight();
        }
        else if(parent->getRight == nullptr)//left kid
        {
            *parent = *parent->getLeft();
        }
        else//both kids
        {
            BinaryTreeNode<Type> * leftMost = this->getLeftMostChild(parent->getRight());
            parent->setData(leftMost->getData());
            parent->setRight(removeNode(parent->getRight(), leftMost->getData()));
        }
    }
    
    if(parent == nullptr)
    {
        return parent;
    }
    
    return balanceSubTree(parent);
}

template <class Type>
void AVLTree<Type> :: insert(Type item)
{
    insertNode(this->getRoot(), item);
}

template <class Type>
void AVLTree<Type> :: remove(Type item)
{
    removeNode(this->getRoot(), item);
}

#endif /* AVLTree_hpp */
