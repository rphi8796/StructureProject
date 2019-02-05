//
//  Header.h
//  StructureProject
//
//  Created by Phillips, Ryan on 2/5/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef List.hpp
#define List.hpp

#include <assert.h>
#include "../../Nodes/LinearNode.hpp"

using namespace std;

template <class Type>
class List
{
protected:
    int size;
public:
    //structure
    virtual void add(Type item) = 0;
    virtual void addAtIndex(int index, Type item) = 0;
    virtual Type remove(int index) = 0;
    virtual Type getFromIndex(int index) = 0;
    
    //Helper
    virtual int getSize() const = 0;
    virtual LinearNode<Type> * getFront() = 0;
    virtual LinearNode<Type> * getEnd() = 0;
};

#endif /* List.hpp */
