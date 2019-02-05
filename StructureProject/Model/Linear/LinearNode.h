//
//  LinearNode.h
//  StructureProject
//
//  Created by Phillips, Ryan on 1/30/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef LinearNode_hpp
#define LinearNode_hpp

#include <assert.h>

template <class Type>
class LinearNode : public Node<Type>
{
//This section is available to the subclass of linearNode
protected:
    LinearNode<Type> * next;
public:
    //Constructor
    LinearNode();
    LinearNode(Type data);
    LinearNode(Type data, LinearNode<Type> * next);
    //Methods
    void setNext(LinearNode<Type> * next);
    LinearNode<Type> * getNext();
};

//Constructors

/**
 This constructor is used for building the outline structure before values are known
 */
template <class Type>
LinearNode<Type> :: LinearNode() : Node<Type>()
{
    this->next = nullptr;
}

/**
 This constructor is used to create a reference to a instance with data
 (ex: assigning a linear node to an already created linear node
 */
template <class Type>
LinearNode<Type> :: LinearNode(Type data) : Node<Type>(data)
{
    this->next = nullptr;
}

/**
 This constructor is used for creating a reference to an instance with data and a known link
 (i.e. a node with a value and knowledge of the next value)
 */
template <class Type>
LinearNode<Type> :: LinearNode(Type data, LinearNode<Type> * next) : Node<Type>(data)
{
    this->next = next;
}

//Accessor methods

template <class Type>
LinearNode<Type> * LinearNode<Type> :: getNext()
{
    return this->next;
}

template <class Type>
void LinearNode<Type> :: setNext(LinearNode<Type> * next)
{
    this->next = next;
}

#endif /* LinearNode_h */
