#include <vector>
#include <string>
#include <iostream>
#include "constants.h"

using namespace std;



struct Score{
    string name;
    int time;

    Score(string playerName, int t){
        name = playerName;
        time = t;
    };
};

bool fileExists(const string &file_name);
void writeResults(string writeName,const int time, vector<Score> &scores);