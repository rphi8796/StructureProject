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
    testLinear();
}

//void Controller :: usingNodes()
//{
//    Node<int> num(6);
//    Node<string> wordHolder("words can be stored too");
//    cout << num.getData() << endl;
//    cout << wordHolder.getData() << endl;
//    wordHolder.setData("replaced text");
//    cout << wordHolder.getData() << endl;
//}

void Controller :: testLinear()
{
    LinearTester test;
    test.testVsSTL();
    test.testVsStack();
    test.testVsQueue();
    test.testVsDouble();
}

void Controller :: testCircular()
{
//    LinkedList<int> kno;
//    kno.add(4);
//    kno.add(6);
//    kno.add(5);
//    cout << kno.getSize() << endl;
//    DoubleNode<int> * one = new DoubleNode<int>(1);
//    DoubleNode<int> * three = new DoubleNode<int>(3);
//    DoubleNode<int> * two = new DoubleNode<int>(2, nullptr, nullptr);
//    CircularList<int> okay;
//    okay.add(8);
//    okay.add(7);
//    okay.add(6);
//    cout << okay.getSize() << endl;
}
