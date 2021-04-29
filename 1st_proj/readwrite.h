#include <vector>
#include <string>
#include <iostream>
#include "constants.h"

using namespace std;



struct Score{
    string name;
    float time;

    Score(string playerName, float t){
        name = playerName;
        time = t;
    };
};

bool fileExists(const string &file_name);
void writeResults(string writeName,const float time);