#include <fstream>
#include <chrono>
#include <sys/stat.h>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include "readwrite.h"
/**
 * @brief Checks if file exists
 * 
 * @param name 
 * @return true - exists
 * @return false - does not exit
 */
bool fileExists(const string &name)
{
    fstream file(name);
    if (!file)
    {
        return 0;
    }
    return 1;
}

bool compareTime(const Score &a, const Score &b){
    return a.time < b.time;
}

void vectorSort(vector<Score> &scores){

    sort(scores.begin(), scores.end(), compareTime);
}

/**
 * @brief 
 * 
 * @param writeName 
 * @param time 
 * @return true 
 * @return false 
 */
void writeResults(string writeName, int time, vector<Score> &scores)
{
    string playerName;
    cout << "Enter player name (Max size 15): " << endl;
    //clear buffer
    cin.ignore();
    getline(cin,playerName);
    playerName.resize(15,' ');

    Score p1 = Score(playerName, time);
    scores.push_back(p1);
    vectorSort(scores);

    ofstream write;
    if (!fileExists(writeName))
    {
        write.open(writeName, fstream::app);
        write << "Player\t\t "
              << "- Time" << endl;
        for (int i = 0; i < LIMIT; i++)
        {
            write << "-";
        }
        write << endl;
        write << playerName;
        
        write << " - " << time << endl;
    }
    else
    {
        write.open(writeName, fstream::app);
        write << playerName;
        write << " - " << time << endl;
    }
    write.close();

    for (int i = 0; i < scores.size(); i++){
        cout << "Name :" << scores[i].name << " Time " << scores[i].time << endl; 
    }
}