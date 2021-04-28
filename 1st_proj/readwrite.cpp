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
 * @brief Sorts Players by their time ( if time equal, then by name)
 * 
 * @param Score a 
 * @param Score b 
 * @return true 
 * @return false 
 */
bool compareTime(const Score &a, const Score &b)
{
    if (a.time == b.time)
    {
        return a.name < b.name;
    }
    return a.time < b.time;
}

void vectorSort(vector<Score> &scores)
{
    sort(scores.begin(), scores.end(), compareTime);
}

/**
 * @brief Stores values of players in player vector
 * 
 * @param scores 
 * @param line 
 */
void addScore(vector<Score> &scores, string line)
{
    string name;
    int time;
    int start = 0;
    int end = line.find(DASHLINE);
    name = line.substr(start, end - start);
    start = end + 1;
    end = line.find(DASHLINE, start);
    time = stoi(line.substr(start, end - start));
    for (Score s_aux : scores)
    {
        if(s_aux.name != name){
            Score s = Score(name, time);
            scores.push_back(s);
        }
        else{
            if(s_aux.time > time){
                scores.pop_back();
                Score s = Score(name, time);
                scores.push_back(s);
            }
        }
    }
}

/**
 * @brief writes all saved stores previously collected from the file + current winner player on the same file
 * 
 * @param scores 
 * @param write 
 */
void writeScore(vector<Score> &scores, ofstream &write)
{
    for (Score s : scores)
    {
        int aux = LIMIT - s.name.size() - 2; //formatar output

        write << s.name;
        for (int i = 0; i < aux; i++){
            write << SPACEBAR;
        }
        write << DASHLINE << s.time << endl;
    }
}

/**
 * @brief writes header of Winner file
 * 
 * @param write 
 */
void writeHeader(ofstream &write)
{
    write << "Player\t\t" << DASHLINE << "Time(s)" << endl;
    for (int i = 0; i < LIMIT; i++)
    {
        write << DASHLINE;
    }
    write << endl;
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
    do
    {
        cout << "Enter player name (Max size 15): ";
        //clear buffer
        cin.ignore();
        getline(cin, playerName);
    } while (playerName.size() > 15);

    playerName.resize(NAMESIZE, SPACEBAR);

    Score p1 = Score(playerName, time);
    scores.push_back(p1);
    vectorSort(scores);

    if (!fileExists(writeName))
    {
        ofstream write(writeName);
        writeHeader(write);
        writeScore(scores, write);
        write.close();
    }
    else
    {
        ifstream read;
        read.open(writeName); //Opens to read
        getline(read, line); // Line with Player - Time
        getline(read, line); // Line with "-----"
        while (getline(read, line))
        {
            addScore(scores, line);
        }
        vectorSort(scores);
        read.close();

        ofstream write(writeName); //Opens to write
        writeHeader(write);
        writeScore(scores, write);
        write.close();
    }
}