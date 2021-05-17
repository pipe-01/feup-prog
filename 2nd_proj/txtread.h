#ifndef TXTREAD_H
#define TXTREAD_H
#include <iostream>
#include <fstream>

using namespace std;

class Txtread
{
private:
    string fileName;
public:
    Txtread(string name){
        fileName = name;
    }
    void printFile();    
};
#endif