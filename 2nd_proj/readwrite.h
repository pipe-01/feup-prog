//T09_G01

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <sys/stat.h>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include "constants.h"

using namespace std;

class Score{
private:    
    string name;
    unsigned time;
public:
    Score(string name, unsigned time){
        this->name = name;
        this->time = time;
    };
    unsigned getTime(){
        return this->time;
    }
    string getName(){
        return name;
    }
    void setName(string name){
        this->name = name;
    }
    void setTime(unsigned time){
        this->time = time;
    }
};

bool fileExists(const string &file_name);
void writeResults(string writeName,const unsigned time);