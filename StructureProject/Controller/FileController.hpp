//
//  FileController.hpp
//  StructureProject
//
//  Created by Phillips, Ryan on 2/11/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include "../Resources/CrimeData.hpp"
#include "../Resources/Music.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "../Model/Linear/LinkedList.hpp"

using namespace std;

class FileController
{
public:
    static vector<CrimeData> readCrimeDataToVector(string filename);
    static vector<Music> musicDataToVector(string fileName);
    static LlinkedList<CrimeData> readDataToList(string filename);
};

#endif /* FileController_hpp */
