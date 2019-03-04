//
//  LinkedListTester.hpp
//  StructureProject
//
//  Created by Phillips, Ryan on 2/13/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef LinearTester_hpp
#define LinearTester_hpp

#include "../Controller/FileController.hpp"
#include "../Controller/Tools/Timer.hpp"

#include "../Model/Linear/LinkedList.hpp"
#include "../Model/Linear/Stack.hpp"
#include "../Model/Linear/Queue.hpp"
#include "../Model/Linear/Array.hpp"
#include "../Model/Linear/CircularList.hpp"

#include <iostream>
using namespace std;

class LinearTester
{
public:
    void testVsSTL();
    void testVsStack();
    void testVsQueue();
    void testVsDouble();
};

#endif /* LinkedListTester_hpp */
