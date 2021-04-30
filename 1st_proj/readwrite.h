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



struct Score{
    string name;
    unsigned time;

    Score(string playerName, unsigned t){
        name = playerName;
        time = t;
    };
};

bool fileExists(const string &file_name);
void writeResults(string writeName,const unsigned time);