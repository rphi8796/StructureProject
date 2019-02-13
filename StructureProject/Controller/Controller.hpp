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
#include "../Model/Nodes/Node.hpp"
#include "../Model/Nodes/LinearNode.hpp"
#include "../Model/Linear/Array.hpp"
#include "../Model/Linear/List.hpp"
#include "../Model/Linear/LinkedList.hpp"
#include "../Model/Linear/Stack.hpp"
#include "../Model/Linear/Queue.hpp"
#include "FileController.hpp"
#include "../Testers/LinearTester.hpp"


using namespace std;

class Controller
{
private:
//    void usingNodes();
    void testFiles();
public:
    void start();
    
};

#endif /* Controller_hpp */
