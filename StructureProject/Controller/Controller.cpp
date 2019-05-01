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
    BinaryTreeTester test;
}
    test.treeStuff();
    BinaryTreeNode<int> number;
    BinaryTreeNode<int> * pointerToNumber;

    number = 7;
    pointerToNumber = &number;
    int value = pointerToNumber->getData();
    pointerToNumber = nullptr;
    bool valueTwo = (pointerToNumber->getData() < 8);


    cout << number.getData() << ", " << value << ", " << valueTwo << endl;
}



