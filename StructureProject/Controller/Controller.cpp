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
    usingNodes();
    testFiles();
}

void Controller :: usingNodes()
{
    Node<int> num(6);
    Node<string> wordHolder("words can be stored too");
    cout << num.getData() << endl;
    cout << wordHolder.getData() << endl;
    wordHolder.setData("replaced text");
    cout << wordHolder.getData() << endl;
}

void Controller :: testFiles()
{
    vector<CrimeData> contents = FileController :: readCrimeDataToVector("../Resources/crime.csv");
    for (int index = 234; index < 256; index++)
    {
        cout << index << ": contents are: " << contents[index] << endl;
    }
}
