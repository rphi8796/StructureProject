//
//  Controller.cpp
//  StructureProject
//
//  Created by Phillips, Ryan on 1/28/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#include "Controller.hpp"


void Controller :: start()
{
    cout << 5 << endl;
    test();
}

void Controller :: testLinear()
{
    LinearTester test;
    test.testVsSTL();
    test.testVsStack();
    test.testVsQueue();
    test.testVsDouble();
}

void Controller :: test()
{
    Graph<int> myGraph;
    myGraph.addVertex(1);
    myGraph.addVertex(2);
    myGraph.addVertex(5);
    myGraph.addEdge(1, 2);
    myGraph.addEdgeUndirected(1, 0);
    cout << "LOL" << endl;
    
}
