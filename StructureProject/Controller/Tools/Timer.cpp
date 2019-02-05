//
//  Timer.cpp
//  StructureProject
//
//  Created by Phillips, Ryan on 2/5/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#include "Timer.hpp"
#include <time.h>
#include <assert.h>
#include <iostream>

class Timer
{
private:
    clock_t executionTime;
public:
    Timer();
    void startTimer();
    void stopTimer();
    void resetTimer();
    void displayInformatio();
    long getTimeInMicroseconds();
};
