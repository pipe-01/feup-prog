//T09_G01

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
    unsigned time;
    int start = 0;
    int end = line.find(DASHLINE);
    name = line.substr(start, end - start);
    start = end + 1;
    end = line.find(DASHLINE, start);
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
void writeScore(vector<Score> &scores, ofstream &write)
{
    for (Score s : scores)
    {
        s.name.resize(NAMESIZE,SPACEBAR);
        write << s.name << DASHLINE << s.time << endl;
    }
}

/**
 * @brief writes header of Winner file
 * 
 * @param write 
 */
void writeHeader(ofstream &write)
{
    write << "Player\t\t" << DASHLINE << "Time(ms)" << endl;
    for (unsigned int i = 0; i < LIMIT; i++)
    {
        write << DASHLINE;
    }
    write << endl;
}

/**
 * @brief After getting name, checks if the file for that maze already exits, if it does not
 *it creates one and adds that player, else opens the already existing file, reads it and adds
 *the players into a vector, then compares them to the new player, if they match in name,
 *the leaderboard keeps the one with the highest score
 * @param writeName 
 * @param time 
 * @return true 
 * @return false 
 */
void writeResults(string writeName,const unsigned time)
{
    vector<Score> scores;
    string playerName, line;
    bool exists = false;
    do
    {
        cout << "Enter player name (Max size 15): ";
        cin.ignore();
        getline(cin, playerName);
    } while (playerName.size() > 15);

    Score p1 = Score(playerName, time);

    if (!fileExists(writeName))
    {
        ofstream write(writeName);
        writeHeader(write);
        scores.push_back(p1);
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
        for(Score &s:scores){
            for(int i = s.name.length()-1; i != 0; i--){
                if(s.name[i]!= SPACEBAR){
                    break;
                }
                s.name.erase(s.name.begin()+i);
            }
            cout << s.name << DASHLINE << p1.name;
            if(s.name == p1.name){
                exists = true;
                if(s.time>p1.time)
                    s=p1;
                break;    
            }
        }
        if(!exists){
            scores.push_back(p1);
        }
        vectorSort(scores);
        read.close();

        ofstream write(writeName); //Opens to write
        writeHeader(write);
        writeScore(scores, write);
        write.close();
    }
}
