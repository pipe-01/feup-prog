#ifndef TXTREAD_H
#define TXTREAD_H
#include <iostream>
#include <fstream>
#include "constants.h"

using namespace std;

class Txtread
{
private:
    string fileName;
public:
    Txtread(string name){
        fileName = name;
    }
    void clearScreen();
    void printFile();    
};
#endif