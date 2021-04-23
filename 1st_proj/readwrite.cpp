#include <fstream>
#include <chrono>
#include <sys/stat.h>
#include <cstring>
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
    char playerName[15];
    cout << "\nWhat is your name?" << endl;
    cin >> playerName;
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
        for (int i = 0; i < 15 - strlen(playerName); i++)
        {
            write << ' ';
        }
        write << " - " << time << endl;
    }
    else
    {
        write.open(writeName, fstream::app);
        write << playerName;
        for (int i = 0; i < 15 - strlen(playerName); i++)
        {
            write << ' ';
        }
        write << " - " << time << endl;
    }
    write.close();
}