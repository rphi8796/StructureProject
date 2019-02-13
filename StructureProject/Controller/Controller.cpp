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
    cout << ":)" << endl;
//    usingNodes();
    testFiles();
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

void Controller :: testFiles()
{
    Array<int> hey(4);
    hey[0] = 0;
    hey[1] = 1;
    hey[2] = 2;
    hey[3] = 3;
    
    cout << hey[3] << endl;
}
