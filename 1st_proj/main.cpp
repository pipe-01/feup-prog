#define FENCE "*"
#define DEADROBOT "r"
#define LIVEROBOT "R"
#define DEADHUMAN "h"
#define LIVEHUMAN "H"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <ios>
#include <algorithm>
#include <limits>
#include <stdio.h>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>
#include <string.h>

using namespace std;



unsigned robotCounterId = 1; //sequential identification number
bool playerIsAlive = true; //Player's values are easily accessible
int playerX = -1, playerY = -1; //(Same as above)

struct Robot
{
    int id = robotCounterId++;
    bool alive = true;
    int getState(){return alive;}
    void killRobot(){alive = false;}
    Robot(){};
};

vector<Robot> robots; //Accessed several times


int draw_menu(bool &rules, bool &play, bool &exits)
{
    int cmenu;

    cout << "-----------------ROBOTS GAME-----------------" << endl;
    cout << "                 1) Rules                 " << endl;
    cout << "                 2) Play                 " << endl;
    cout << "                 0) Exit                 " << endl;

    while (1)
    {
        cin >> cmenu;

        if (cin.fail())
        {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You have entered an invalid input" << endl;

            if (cin.eof())
            {
                exit(0);
            }
        }
        else if (cmenu == 1)
        {
            rules = true;
            break;
        }
        else if (cmenu == 2)
        {
            play = true;
            break;
        }
        else if (cmenu == 0)
        {
            exits = true;
            break;
        }
        else
        {
            cout << "Enter a valid number! (0,1,2)" << endl;
        }
    }
    return 0;
}

//check if a file exists
bool file_exists(const string &file_name)
{
    ifstream file(file_name);

    if (!file)
    {
        return false;
    }
    else
        return true;
}


void read_file(string &file_name, vector<vector<char>> &tiles)
{
    int rows, columns;
    char useless;
    ifstream file(file_name);

    if (!file)
    {
        cout << "Can't open file" << endl;
    }
    else
    {
        string line;
        char now;
        file >> rows >> useless >> columns;
        tiles.resize(rows);
        for (size_t i = 0; i < rows; i++)
        {
            tiles[i].resize(columns);
        }
        
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
            {
                file.get(now);
                if (now == char(LIVEROBOT))
                {
                    playerX = i;
                    playerY = j;
                }
                else if(now == char(LIVEROBOT)){
                    robots.push_back(new Robot());
                }
                tiles[i][j]=now;
            }
        }
    }
    file.close();
}

int read_game(bool &menu, vector<vector<char>> &tiles)
{
    int maze_value;
    string file_name;
    string aux;

    //clear terminal
    cout << "\033[2J\033[1;1H";

    while (1)
    {

        file_name = "MAZE_";

        cout << "Enter the maze size: ";
        cin >> maze_value;

        if (cin.fail())
        {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You have entered wrong input" << endl;

            if (cin.eof())
            {
                exit(0);
            }
        }
        else if (maze_value > 0 && maze_value <= 9)
        {

            aux = to_string(maze_value);
            file_name = file_name + "0" + aux + ".TXT";

            if (file_exists(file_name))
            {
                cout << "File exists" << endl;
                read_file(file_name, tiles);
                file_name.clear();
                menu = false;
                break;
            }
            else
            {
                cout << "File doesn't exist" << endl;
            }
        }
        else if (maze_value >= 10 && maze_value <= 99)
        {

            aux = to_string(maze_value);
            file_name = file_name + aux + ".TXT";

            if (file_exists(file_name))
            {
                cout << "File exists" << endl;
                read_file(file_name, tiles);
                file_name.clear();
                menu = false;
                break;
            }
            else
            {
                cout << "File doesn't exist" << endl;
            }
        }
        else if (maze_value == 0)
        {
            //clear terminal
            cout << "\033[2J\033[1;1H";
            menu = true;
            return 0;
        }
        else
        {
            cout << "Enter a valid number between 0 and 99" << endl;
        }
    }
    return -1;
}


//create file with name file_name
void create_file(string file_name)
{

    ofstream file;
    file.open(file_name, ios::out);
    if (!file)
    {
        cout << "Error to open file!" << endl;
        return;
    }
    file.close();
}

void printBoard(vector<vector<char>> tiles){
    cout << "Current Board Status" << endl;
    for (size_t i = 0; i < tiles.size(); i++)
    {
        for (size_t j = 0; j < tiles[0].size(); j++)
        {
            cout << tiles[i][j];
        }
        cout << endl;
        
    }
}

int main()
{
    bool menu = true, play = false, rules = false, exits = false;
    vector<vector<char>> tiles;

    while (menu)
    {

        draw_menu(rules, play, exits);

        if (play)
        {
            cout << "Playing game" << endl;
            read_game(menu, tiles);
            play = false;
        }

        if (rules)
        { //Por fazer
            cout << "RULES" << endl;
            rules = false;
            sleep(10);
        }

        if (exits)
        {
            cout << "exit" << endl;
            exits = false;
            menu = false;
            cout << "Banner qualquer"; //Por fazer
            exit(0);
        }
    }
    return 0;
}