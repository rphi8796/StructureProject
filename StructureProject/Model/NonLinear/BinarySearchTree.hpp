//
//  BinarySearchTree.hpp
//  StructureProject
//
//  Created by Phillips, Ryan on 4/12/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "Tree.hpp"
#include <iostream>

using namespace std;

template <class Type>
class BinarySearchTree : public Tree<Type>
{
protected:
    //Recursive Information Helpers
    int calculateSize(BinaryTreeNode<Type> * startNode);
    int calculateHeight(BinaryTreeNode<Type> * startNode);
    bool isBalanced(BinaryTreeNode<Type> * startNode);
    bool isComplete(BinaryTreeNode<Type> * startNode, int index, int size);
    
    //Recursive Traversal Helpers
    void inOrderTraversal(BinaryTreeNode<Type> * inStart);
    void preOrderTraversal(BinaryTreeNode<Type> * preStart);
    void postOrderTraversal(BinaryTreeNode<Type> * postStart);
    BinaryTreeNode<Type> * getRightMostChild(BinaryTreeNode<Type> * current);
    BinaryTreeNode<Type> * getLeftMostChild(BinaryTreeNode<Type> * current);
    
    //Structure
    void destroyTree(BinaryTreeNode<Type> * node);

    //Recursive Data Helpers
    void removeNode(BinaryTreeNode<Type> * removeMe);
    
public:
    //(De)Constructors
    BinarySearchTree();
    ~BinarySearchTree();
    
    //Traversals
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    void demoTraversalSteps(BinaryTreeNode<Type> * node);
    
    //Informational Methods
    int getSize();
    int getHeight();
    bool isComplete();
    bool isBalanced();
    BinaryTreeNode<Type> * getRoot();
    Type findMinimum();
    Type findMaximum();
    
    //Data Methods
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
};


//
//
//Constructor/de------------------------------------------------------------------------------
//
//
template <class Type>
BinarySearchTree<Type> :: BinarySearchTree()
{
    this->root = nullptr;
}

template <class Type>
BinarySearchTree<Type> :: ~BinarySearchTree()
{
    destroyTree(this->root);
}

//
//
//Informational Methods------------------------------------------------------------------------------
//
//
template <class Type>
int BinarySearchTree<Type> :: getSize()
{
    int size = 0;
    
    size += calculateSize(this->root);
    
    return size;
}

template <class Type>
int BinarySearchTree<Type> :: getHeight()
{
    return calculateHeight(this->root);
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete()
{
    int index = 0;
    int size = getSize();
    
    return isComplete(this->root, index, size);
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced()
{
    return isBalanced(this->root);
}



template <class Type>
Type BinarySearchTree<Type> :: findMaximum()
{
    assert(this->root != nullptr);
    return getRightMostChild(this->root)->getData();
}

template <class Type>
Type BinarySearchTree<Type>  :: findMinimum()
{
    assert(this->root != nullptr);
    return getLeftMostChild(this->root)->getData();
}


//
//
//Recursive Information Helpers------------------------------------------------------------------------------
//
//
template <class Type>
int BinarySearchTree<Type> :: calculateSize(BinaryTreeNode<Type> * current)
{
    if (current != nullptr)
    {
        return calculateSize(current->getLeft() + calculateSize(current->getRight()) + 1);
    }
    return 0;
}

template <class Type>
int BinarySearchTree<Type> :: calculateHeight(BinaryTreeNode<Type> * current)
{
    if (current != nullptr)
    {
        return max(calculateHeight(current->getLeft()), calculateHeight(current->getRight())) + 1;
    }
    return 0;
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced(BinaryTreeNode<Type> * current)
{
    int leftHeight = 0;
    int rightHeight = 0;
    
    if (current == nullptr)
    {
        return true;
    }
    
    leftHeight = calculateHeight(current->getLeft());
    rightHeight = calculateHeight(current->getRight());
    
    int heightDifference = abs(leftHeight - rightHeight);
    bool leftBalanced = isBalanced(current->getLeft());
    bool rightBalanced = isBalanced(current->getRight());
    
    if (heightDifference <= 1 && leftBalanced && rightBalanced)
    {
        return true;
    }
    
    return false;
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete(BinaryTreeNode<Type> * startNode, int index, int size)
{
    if (startNode == nullptr)
    {
        return true;
    }
    
    if (index >= size)
    {
        return false;
    }
    
    return (isComplete(startNode->getLeft(), 2 * index + 1, size) && isComplete(startNode->getRight(), 2 * index + 2, size));
}

//
//
//Data methods------------------------------------------------------------------------------
//
//
template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
    BinaryTreeNode<Type> * insertMe = new BinaryTreeNode<Type>(itemToInsert);
    BinaryTreeNode<Type> * previous = nullptr;
    BinaryTreeNode<Type> * current = this->root;
    
    if (current == nullptr)
    {
        this->root = insertMe;
    }
    else
    {
        while (current != nullptr)
        {
            previous = current;
            if (itemToInsert < current->getData())
            {
                current = current->getLeft();
            }
            else if(itemToInsert > current->getData())
            {
                current = current->getRight();
            }
            else
            {
                delete insertMe;
                return;
            }
        }
        
        if (previous->getData() > itemToInsert)
        {
            previous->setLeft(insertMe);
        }
        else
        {
            previous->setRight(insertMe);
        }
        insertMe->setRoot(previous);
    }
}

template <class Type>
bool BinarySearchTree<Type> :: contains(Type itemToFind)
{
    BinaryTreeNode<Type> * current = this->root;
    if (current == nullptr)
    {
        return false;
    }
    else
    {
        while (current != nullptr)
        {
            if (itemToFind == current->getData())
            {
                return true;
            }
            else if (itemToFind < current -> getData())
            {
                current = current->getLeft();
            }
            else
            {
                current = current->getRight();
            }
        }
        return false;
    }
}

template <class Type>
void BinarySearchTree<Type> :: remove(Type getRidOfMe)
{
    if (this->root == nullptr)
    {
        cout << "Empty tree so removal is not possible" << endl;
    }
    else
    {
        BinaryTreeNode<Type> * current = this->root;
        BinaryTreeNode<Type> * previous = nullptr;
        bool hasBeenFound = false;
        
        while (current != nullptr && !hasBeenFound)
        {
            if (current->getData() == getRidOfMe)
            {
                hasBeenFound = true;
            }
            else
            {
                previous = current;
                if (getRidOfMe < current->getData())
                {
                    current = current->getLeft();
                }
                else
                {
                    current = current->getRight();
                }
            }
        }
        if (current == nullptr)
        {
            cerr << "Item not found, removal unsuccessful" << endl;
        }
        else if (hasBeenFound)
        {
            if (current == this->root)
            {
                removeNode(this->root);
            }
            else if (getRidOfMe < previous->getData())
            {
                removeNode(previous->getLeft());
            }
            else
            {
                removeNode(previous->getRight());
            }
        }
    }
}




//
//
//Structure------------------------------------------------------------------------------
//
//
template <class Type>
void BinarySearchTree<Type> :: destroyTree(BinaryTreeNode<Type> * node)
{
    if (node != nullptr)
    {
        destroyTree(node->getLeft());
        destroyTree(node->getRight());
        delete node;
    }
}


//
//
//Recursive Data Helpers------------------------------------------------------------------------------
//
//
template <class Type>
void BinarySearchTree<Type> :: removeNode(BinaryTreeNode<Type> * removeMe)
{
    BinaryTreeNode<Type> * current;
    BinaryTreeNode<Type> * previous;
    BinaryTreeNode<Type> * temp;
    
    previous = removeMe->getRoot();
    
    if (removeMe->getRight() == nullptr && removeMe->getLeft() == nullptr)
    {
        temp = removeMe;
        removeMe = nullptr;
        
        if (previous != nullptr && temp->getData() < previous->getData())
        {
            previous->setLeft(removeMe);
        }
        else if (previous != nullptr && temp->getData() > previous->getData())
        {
            previous->setRight(removeMe);
        }
        
        delete temp;
    }
    
    else if (removeMe->getRight() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getLeft();
        
        if (previous != nullptr && temp->getData() < previous->getData())
        {
            previous->setLeft(removeMe);
        }
        else if (previous != nullptr && temp->getData() > previous->getData())
        {
            previous->setRight(removeMe);
        }
        
        removeMe->setRoot(previous);
        
        delete temp;
    }
    
    else if(removeMe->getLeft() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getRight();
        if (previous != nullptr && removeMe->getData() < previous->getData())
        {
            previous->setLeft(removeMe);
        }
        else if(previous != nullptr && removeMe->getData() > previous->getData())
        {
            previous->setRight(removeMe);
        }
        removeMe->setRoot(previous);
        delete temp;
    }
    
    else
    {
        current = getRightMostChild(removeMe->getLeft());
        
        previous = current->getRoot();
        removeMe->setData(current->getData());
        
        if (previous == nullptr)
        {
            removeMe->setLeft(current->getLeft());
        }
        else
        {
            previous->setRight(current->getLeft());
        }
        if (current->getLeft() != nullptr)
        {
            current->getLeft()->setRoot(removeMe);
        }
        delete current;
    }
    
    if (removeMe == nullptr || removeMe->getRoot() == nullptr)
    {
        this->root = removeMe;
    }
}

//
//
//Traversals ------------------------------------------------------------------------------
//
//
template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{
    inOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal()
{
    preOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
    postOrderTraversal(this->root);
}

//
//
//Recursive Traversal Helpers------------------------------------------------------------------------------
//
//
template <class Type>
//Order for this is Left, Root, Right
void BinarySearchTree<Type> :: inOrderTraversal(BinaryTreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        inOrderTraversal(currentNode->getLeft());
        cout << currentNode->getData() << endl;
        inOrderTraversal(currentNode->getRight());
    }
}

//Order for this is Root, Left, Right
template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal(BinaryTreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        cout << currentNode->getData() << endl;
        preOrderTraversal(currentNode->getLeft());
        preOrderTraversal(currentNode->getRight());
    }
}

//Order for this is Left, Right, Root
template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal(BinaryTreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        postOrderTraversal(currentNode->getLeft());
        postOrderTraversal(currentNode->getRight());
        cout << currentNode->getData() << endl;
    }
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getLeftMostChild(BinaryTreeNode<Type> * startingNode)
{
    BinaryTreeNode<Type> * currentNode = startingNode;
    BinaryTreeNode<Type> * previous = nullptr;
    while (currentNode != nullptr)
    {
        previous = currentNode;
        currentNode = currentNode->getLeft();
    }
    
    return previous;
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getRightMostChild(BinaryTreeNode<Type> * startingNode)
{
    BinaryTreeNode<Type> * currentNode = startingNode;
    BinaryTreeNode<Type> * previous = nullptr;
    while (currentNode != nullptr)
    {
        previous = currentNode;
        currentNode = currentNode->getRight();
    }
    
    return previous;
}


//Data operation
template <class Type>
void BinarySearchTree<Type> :: insert(Type item)
{
    
}

template <class Type>
bool BinarySearchTree<Type> :: contains(Type value)
{
    return false;
}

template <class Type>
void BinarySearchTree<Type> :: remove(Type item)
{
    
}





#endif /* BinarySearchTree_h */
