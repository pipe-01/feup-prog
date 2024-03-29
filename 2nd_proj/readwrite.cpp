//T09_G01
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
        return false;
    }
    return true;
}
/**
 * @brief Sorts Players by their time ( if time equal, then by name)
 * 
 * @param Score a 
 * @param Score b 
 * @return true 
 * @return false 
 */
bool compareTime(Score a, Score b)
{
    if (a.getTime() == b.getTime())
    {
        return a.getName() < b.getName();
    }
    return a.getTime() < b.getTime();
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
    unsigned start = 0;
    unsigned end = line.find(DASHLINE);
    name = line.substr(start, end - start);
    start = end + 1;
    end = line.find(DASHLINE, start);
    time = stoi(line.substr(start, end - start));
    cout << "Name in AddScore: "<< name << endl;
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
    string aux;
    for (Score s : scores)
    {
        aux = s.getName();
        aux.resize(NAMESIZE, SPACEBAR);
        s.setName(aux);
        //cout << "Name in writeScore:" << s.name << endl;
        write << s.getName() << DASHLINE << SPACEBAR << s.getTime() << endl;
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
void writeResults(string writeName, const unsigned time)
{
    vector<Score> scores;
    string playerName, line;
    bool exists = false;
    do
    {
        cout << "\033[2J\033[1;1H";
        cout << "Enter player name (Max size 15): ";
        getline(cin, playerName);
    } while (playerName.size() > 15);

    Score p1 = Score(playerName, time);
    //cout << "name in p1: "<< p1.getName() << endl;

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
        getline(read, line);  // Line with Player - Time
        getline(read, line);  // Line with "-----"
        while (getline(read, line))
        {
            addScore(scores, line);
        }
        for (Score &s : scores)
        {
            string tempName = s.getName();
            for (int i = s.getName().length() - 1; i != 0; i--)
            {
                if (s.getName()[i] != SPACEBAR)
                {
                    break;
                }
                
                tempName.erase(tempName.begin() + i);
            }
            s.setName(tempName);
            cout << s.getName() << DASHLINE << p1.getName();
            if (s.getName() == p1.getName())
            {
                exists = true;
                if (s.getTime() > p1.getTime())
                    s = p1;
                break;
            }
        }
        if (!exists)
        {
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
