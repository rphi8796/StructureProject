//
//  LinkedListTester.cpp
//  StructureProject
//
//  Created by Phillips, Ryan on 2/13/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#include "LinearTester.hpp"

void LinearTester :: testVsSTL()
{
    Timer crimeTimerSTL, crimeTimerOOP, musicSTL, musicOOP;
    
    crimeTimerSTL.startTimer();
    vector<CrimeData> crimes = FileController :: crimeDataToVector("/Users/rphi8796/Documents/C++/StructureProject/StructureProject/Resources/crime.csv");
    crimeTimerSTL.stopTimer();
    
    crimeTimerOOP.startTimer();
    LinkedList<CrimeData> moreCrimes = FileController :: crimeDataToList("/Users/rphi8796/Documents/C++/StructureProject/StructureProject/Resources/crime.csv");
    crimeTimerOOP.stopTimer();
    
    cout << "this is the STL Read time :" << endl;
    crimeTimerSTL.displayInformation();
    cout << "This is the OOP Node read time: " << endl;
    crimeTimerOOP.displayInformation();
    cout << "Crime: A difference of: " << crimeTimerOOP.getTimeInMicroseconds() - crimeTimerSTL.getTimeInMicroseconds() << " microseconds" << endl;
    
    musicSTL.startTimer();
    vector<Music> music = FileController :: musicDataToVector("/Users/rphi8796/Documents/C++/StructureProject/StructureProject/Resources/music.csv");
    musicSTL.stopTimer();
    
    musicOOP.startTimer();
    LinkedList<Music> moreMusic = FileController :: musicDataToList("/Users/rphi8796/Documents/C++/StructureProject/StructureProject/Resources/music.csv");
    musicOOP.stopTimer();
    
    cout << "This is the STL read time :" << endl;
    musicSTL.displayInformation();
    cout << "This is the OOP Node read time: " << endl;
    musicOOP.displayInformation();
    cout << "Music: A difference of: " << musicOOP.getTimeInMicroseconds() - musicSTL.getTimeInMicroseconds() << " microseconds" << endl;
    
    crimeTimerOOP.resetTimer();
    crimeTimerSTL.resetTimer();
    musicOOP.resetTimer();
    musicSTL.resetTimer();
    
    
    int randomIndex = rand() % moreCrimes.getSize();
    
    crimeTimerSTL.startTimer();
    crimes[randomIndex];
    crimeTimerSTL.stopTimer();
    
    crimeTimerOOP.startTimer();
    moreCrimes.getFromIndex(randomIndex);
    crimeTimerOOP.stopTimer();
    
    cout << "This is the STl random retrieval: " << endl;
    crimeTimerSTL.displayInformation();
    cout << "This is the OOP Node random retrieval: " << endl;
    crimeTimerOOP.displayInformation();
    cout << "A difference of: " << crimeTimerOOP.getTimeInMicroseconds() - crimeTimerSTL.getTimeInMicroseconds() << " microseconds" << endl;
    
    randomIndex = rand() % moreMusic.getSize();
    
    musicSTL.startTimer();
    music[randomIndex];
    musicSTL.stopTimer();
    
    musicOOP.startTimer();
    moreMusic.getFromIndex(randomIndex);
    musicOOP.stopTimer();
    
    cout << "This is the STL random retrieval: " << endl;
    musicSTL.displayInformation();
    cout << "This is the OOP Node random retrieval: " << endl;
    musicOOP.displayInformation();
    cout << "A difference of: " << musicOOP.getTimeInMicroseconds() - musicSTL.getTimeInMicroseconds() << " microseconds" << endl;
    
}

void LinearTester :: testVsStack()
{
    vector<CrimeData> crimeVector = FileController :: crimeDataToVector("/Users/rphi8796/Documents/C++/StructureProject/StructureProject/Resources/crime.csv");
    LinkedList<CrimeData> crimeList = FileController :: crimeDataToList("/Users/rphi8796/Documents/C++/StructureProject/StructureProject/Resources/crime.csv");
    Stack<CrimeData> crimeStack;
    for (int i = 0; i < 10; i++)
    {
        CrimeData value = crimeVector[i];
        crimeStack.push(value);
    }
}

void LinearTester :: testVsQueue()
{
    vector<Music> musicVector = FileController :: musicDataToVector("/Users/rphi8796/Documents/C++/StructureProject/StructureProject/Resources/music.csv");
    LinkedList<Music> musicList = FileController :: musicDataToList("/Users/rphi8796/Documents/C++/StructureProject/StructureProject/Resources/music.csv");
    Queue<Music> musicQueue;
    for (int i = 0; i < 10; i++)
    {
        Music value = musicVector[i];
        musicQueue.enqueue(value);
    }
    for (int i = 0; i < 10; i++)
    {
        musicQueue.dequeue();
    }
}

void LinearTester :: testVsDouble()
{
    Timer listTimer, circleTimer;
    
    listTimer.startTimer();
    LinkedList<CrimeData> crimeList = FileController :: crimeDataToList("/Users/rphi8796/Documents/C++/StructureProject/StructureProject/Resources/crime.csv");
    listTimer.stopTimer();
    
    circleTimer.startTimer();
    CircularList<CrimeData> crimeCircle;
    for (int i = 0; i < 30; i++)
    {
        CrimeData value = crimeList.getFromIndex(i);
        crimeCircle.add(value);
    }
    circleTimer.stopTimer();
    
    cout << " " << endl << " " << endl;
    cout << "Linked List time" << endl;
    listTimer.displayInformation();
    cout << "Circular List time" << endl;
    circleTimer.displayInformation();
    cout << "A difference of " << listTimer.getTimeInMicroseconds() - circleTimer.getTimeInMicroseconds() << " microseconds" << endl;
    
    listTimer.resetTimer();
    circleTimer.resetTimer();
    
    int randomIndex = rand() % 30;
    
    listTimer.startTimer();
    crimeList.getFromIndex(randomIndex);
    listTimer.stopTimer();
    
    circleTimer.startTimer();
    crimeCircle.getFromIndex(randomIndex);
    circleTimer.stopTimer();
    
    cout << "This is the Linked List's random retrieval time: " << endl;
    listTimer.displayInformation();
    cout << "This is the Circular List's random retrieval time: " << endl;
    circleTimer.displayInformation();
    cout << "A difference of: " << listTimer.getTimeInMicroseconds() - circleTimer.getTimeInMicroseconds() << " microseconds" << endl;
}

