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
    testTree.insert(4);
    testTree.insert(2);
    testTree.insert(6);
    testTree.insert(1);
    testTree.insert(3);
    testTree.insert(5);
    testTree.insert(7);
    testTree.insert(223);
    testTree.remove(223);
    cout << "in order" << endl;
    testTree.inOrderTraversal();
    cout << endl << "pre order" << endl;
    testTree.preOrderTraversal();
    cout << endl << "post order" << endl;
    testTree.postOrderTraversal();

//    words.insert("bb");
//    words.insert("ab");
//    words.insert("cb");
//    words.insert("aa");
//    words.insert("ac");
//    words.insert("ca");
//    words.insert("cb");
//
//    cout << endl << "in order" << endl;
//    words.inOrderTraversal();
//    cout << endl << "pre order" << endl;
//    words.preOrderTraversal();
//    cout << endl << "post order" << endl;
//    words.postOrderTraversal();
}
