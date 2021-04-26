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
/**
 * @brief Sorts Players by their time
 * 
 * @param Score a 
 * @param Score b 
 * @return true 
 * @return false 
 */
bool compareTime(const Score &a, const Score &b){
    return a.time < b.time;
}

void vectorSort(vector<Score> &scores){

    sort(scores.begin(), scores.end(), compareTime);
}
/**
 * @brief Stores values of players in player vector
 * 
 * @param scores 
 * @param line 
 */
void addScore(vector<Score> &scores, string line){
    string name, del = "-"; int time;
    int start = 0;
    int end = line.find(del);
    name = line.substr(start, end - start);
    start = end + del.size();
    end = line.find(del, start);
    time = stoi(line.substr(start, end - start));
    Score s = Score(name, time);
    scores.push_back(s);
}
/**
 * @brief writes all saved stores previously collected from the file + current winner player on the same file
 * 
 * @param scores 
 * @param write 
 */
void writeScore(vector<Score> &scores, ofstream &write){
    for(Score s: scores){
        write << s.name << "-" << s.time << endl;
    }
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
    string playerName, line;
    cout << "Enter player name (Max size 15): " << endl;
    //clear buffer
    cin.ignore();
    getline(cin,playerName);
    playerName.resize(NAMESIZE,' ');

    Score p1 = Score(playerName, time);
    scores.push_back(p1);
    vectorSort(scores);

    if (!fileExists(writeName))
    {
        ofstream write(writeName);
        write << "Player\t\t "
              << "- Time" << endl;
        for (int i = 0; i < LIMIT; i++)
        {
            write << "-";
        }
        write << endl;
        write << playerName;
        
        write << " - " << time << endl;
        write.close();
    }
    else
    {
        ifstream read; 
        read.open(writeName);
        getline(read,line);// Line with Player - Time
        getline(read,line);// Line with "-----"
        while (getline(read,line))
        {
            addScore(scores,line);
        }
        vectorSort(scores);
        read.close();
        ofstream write(writeName);
        write << "Player\t\t "
              << "- Time" << endl;
        for (int i = 0; i < LIMIT; i++)
        {
            write << "-";
        }
        write << endl;
        writeScore(scores, write);
        write.close();
    }
    /**
    for (int i = 0; i < scores.size(); i++){
        cout << "Name :" << scores[i].name << " Time " << scores[i].time << endl; 
    }
    **/
}