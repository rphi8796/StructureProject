//
//  BinaryTreeTester.cpp
//  StructureProject
//
//  Created by Phillips, Ryan on 4/12/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#include "BinaryTreeTester.hpp"

#include "../Model/Nodes/BinaryTreeNode.hpp"

void BinaryTreeTester :: treeStuff()
{
    testTree.insert(1);
    testTree.insert(2);
    testTree.insert(3);
    testTree.insert(4);
    testTree.insert(5);
    testTree.insert(6);
    testTree.insert(7);
    testTree.insert(8);
    testTree.insert(9);
    testTree.insert(10);
    
    testTree.inOrderTraversal();
}
