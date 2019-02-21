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
    testCircular();
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
    CircularList<int> * okay = new CircularList<int>();
    okay->add(8);
    okay->add(7);
    okay->add(6);
    cout << okay->getSize() << endl;
}

void Controller :: testCircular()
{
    CircularList<int> okay;
    okay.add(8);
    okay.add(7);
    okay.add(6);
//    cout << okay.getSize() << endl;
}
