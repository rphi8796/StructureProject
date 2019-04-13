//
//  Controller.hpp
//  StructureProject
//
//  Created by Phillips, Ryan on 1/28/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "FileController.hpp"
#include "../Model/Nodes/Node.hpp"
#include "../Model/Nodes/LinearNode.hpp"
#include "../Model/Nodes/DoubleNode.hpp"
#include "../Model/Nodes/BinaryTreeNode.hpp"
#include "../Model/Linear/Array.hpp"
#include "../Model/Linear/List.hpp"
#include "../Model/Linear/LinkedList.hpp"
#include "../Model/Linear/Stack.hpp"
#include "../Model/Linear/Queue.hpp"
#include "../Model/Linear/CircularList.hpp"
#include "../Testers/LinearTester.hpp"
#include "../Testers/GraphTester.hpp"
#include "../Testers/BinaryTreeTester.hpp"
#include "../Model/NonLinear/Graph.hpp"




using namespace std;

class Controller
{
public:
    void start();
    
};

#endif /* Controller_hpp */
