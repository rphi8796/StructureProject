//
//  LinkedList.hpp
//  StructureProject
//
//  Created by Phillips, Ryan on 2/7/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#include "List.hpp"

using namespace std;

#ifndef LinkedList_hpp
#define LinkedList_hpp

template <class Type>
class LinkedList : public List<Type>
{
protected:
    LinearNode<Type> * front;
    LinearNode<Type> * end;
    
public:
    //Constructors
    LinkedList();
    //Destructor
    Virtual ~LinkedList();
    //Helper methods
    int getSize() const;
    LinearNode<Type> * getFront();
    LinearNode<Type> * getEnd();
    
    //Structure Methods
    void add(Type item);
    void addAtIndex(int index, Type item);
    Type getFromIndex(int index);
    Type remove(int index);
//    Type setAtIndex(int index, Type item);
//    bool contains(Type item);
};

//Constructor
template <class Type>
LinkedList<Type> :: linkedList()
{
    this->front = nullptr;
    this->end = nullptr;
    this->size = 0;
}

//Destructor
template <class Type>
LinkedList<Type> :: ~LinkedList()
{
    LinearNode<Type> * destroyStructure = front;
    while (front != nullptr)
    {
        front = destroyStructure->getNextNode();
        delete destroyStructure;
        destroyStructure = front;
    }
}

//Helper methods
template <class Type>
void LinkedList<Type> :: add(Type item)
{
    LinearNode<Type> * newData = new LinearNode<Type>(item);
    
    if(this->size= 0)
    {
        this->front = newData;
    }
    else
    {
        this->end->setNextNode(newData);
    }
    
    this->end = newData;
    
    this->size += 1;
}


#endif /* LinkedList_hpp */
