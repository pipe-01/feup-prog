#include <fstream>
#include <chrono>
#include <sys/stat.h>
#include <cstring>
#include <stdio.h>
#include <string.h>
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
 * @brief 
 * 
 * @param writeName 
 * @param time 
 * @return true 
 * @return false 
 */
void writeResults(string writeName, int time)
{
    string playerName;
    cout << "Enter player name: " << endl;
    cin.ignore();
    getline(cin,playerName);
    playerName.resize(15,' ');
    ofstream write;
    if (!fileExists(writeName))
    {
        write.open(writeName, fstream::app);
        write << "Player\t\t "
              << "- Time" << endl;
        for (int i = 0; i < 19; i++)
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
}