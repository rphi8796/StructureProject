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
    GraphTester test;
    test.testGraphs();
}

void Controller :: readFromFile()
{
    LinkedList<CrimeData> crime = FileController :: crimeDataToList("/Users/rphi8796/Documents/C++/StructureProject/StructureProject/Resources/crime.csv");
    
    for (int i = 234; i < 256; i++)
    {
        cout << crime.getFromIndex(i) << endl;
    }
}


