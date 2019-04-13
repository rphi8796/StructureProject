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
    Stack<int> quizStack;
    quizStack.push(5);
    
    quizStack.push(3);
    
    quizStack.pop();
    
    quizStack.push(15);
    
    quizStack.peek();
    
    quizStack.push(54);
    
    quizStack.pop();
    
    quizStack.push(56);
    
    cout << quizStack.pop() << endl;
    cout << quizStack.pop() << endl;
    cout << quizStack.pop() << endl;
}

void Controller :: readFromFile()
{
    
    for (int i = 234; i < 256; i++)
    {
        cout << crime.getFromIndex(i) << endl;
    }
}


