#define FENCE '*'
#define DEADROBOT 'r'
#define LIVEROBOT 'R'
#define DEADHUMAN 'h'
#define LIVEHUMAN 'H'
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

void wait() {
    cout << "\n\tPress ENTER key to continue....";
    getchar();
    getchar();
}

struct Robot
{
    int x, y;
    int id = robotCounterId++;
    bool alive = true;
    int getState(){return alive;}
    void killRobot(){alive = false;}
    Robot(int i, int j){x = i; y = j;};
};

vector<Robot> robots; //Accessed several times


int draw_menu(bool &rules, bool &play, bool &exits)
{
    int cmenu;

    cout << "                   ___       __        __    _____              \n"
            "                  / _ \\___  / /  ___  / /_  / ___/__ ___ _  ___ \n"
            "                 / , _/ _ \\/ _ \\/ _ \\/ __/ / (_ / _ `/  ' \\/ -_)\n"
            "                /_/|_|\\___/_.__/\\___/\\__/  \\___/\\_,_/_/_/_/\\__/ \n"
            "                                                                " << endl;
    cout << " ___    ___      _        \n"
            "/ \\ \\  | _ \\_  _| |___ ___\n"
            "| || | |   / || | / -_|_-<\n"
            "|_|| | |_|_\\\\_,_|_\\___/__/\n"
            "  /_/  " << endl;
    cout << " _____    ___ _           \n"
            "|_  ) \\  | _ \\ |__ _ _  _ \n"
            " / / | | |  _/ / _` | || |\n"
            "/___|| | |_| |_\\__,_|\\_, |\n"
            "    /_/              |__/ " << endl;
    cout << "  ____    ___     _ _   \n"
            " /  \\ \\  | __|_ _(_) |_ \n"
            "| () | | | _|\\ \\ / |  _|\n"
            " \\__/| | |___/_\\_\\_|\\__|\n"
            "    /_/ " << endl;

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
        char now = '\0';
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
                if (LIVEHUMAN == now)
                {
                    playerX = i;
                    playerY = j;
                }
                else if(LIVEHUMAN == now){
                    Robot r1 = Robot(i,j);
                    robots.push_back(r1);
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

void printRules(){
    char any;
    cout << "                                ___       __      \n"
            "                               / _ \\__ __/ /__ ___\n"
            "                              / , _/ // / / -_|_-<\n"
            "                             /_/|_|\\_,_/_/\\__/___/\n"
            "                                                  " << endl;
    cout << "H = human, R = Robot, * = Fence/Post\n"
            "1) Main Goal of the Game: Survive the Robots & Electrical Posts/Fences\n"
            "2) Win is achieved if no robots are alive\n"
            "3) Dead robots remain in their last position (thus can not move through them)\n"
            "4) For every move, robots move one tile closer to your character (H)\n"
            "5) Death can be by collision with robots or fences/posts\n"
            "6) Robots also die from collisions between each other (only one robot is placed in the place of death)\n"
            "7) Times are recorded and stored in a text file\n"
            "Controls are as follows: \n"
            "\tA/a = Left\n"
            "\tW/w = Up\n"
            "\tD/d = Right\n"
            "\tX/x = Down\n"
            "\tS/s = No movement\n"
            "\t0 = Exit Game\n";
    wait();
}

void printExit(){
    cout << " ____                                  _       _            _ \n"
            "/ ___|  ___  ___   _   _  ___  _   _  | | __ _| |_ ___ _ __| |\n"
            "\\___ \\ / _ \\/ _ \\ | | | |/ _ \\| | | | | |/ _` | __/ _ \\ '__| |\n"
            " ___) |  __/  __/ | |_| | (_) | |_| | | | (_| | ||  __/ |  |_|\n"
            "|____/ \\___|\\___|  \\__, |\\___/ \\__,_| |_|\\__,_|\\__\\___|_|  (_)\n"
            "                   |___/                                      " << endl;
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
            printRules();
            rules = false;
        }

        if (exits)
        {
            exits = false;
            menu = false;
            exit(0);
        }
    }
    return 0;
}