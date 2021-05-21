//T09_G01

#include <iostream>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "draw.h"
#include "readwrite.h"
#include "constants.h"
#include "movable.h"
#include "txtread.h"

using namespace std;

/**
 * @brief Stores player information
 * 
 */

/**
 * @brief Stores robots main information which is accessed frequently
 * 
 */
/**
struct Robot
{
    int x, y;
    int id;
    bool alive = true;
    Robot(int i, int j, int n )
    {
        x = i;
        y = j;
        id = n; 
    };
};
**/

/**
 * @brief for debug purposes, can be used to check robots movement
 */
/**
void printRobotsPos(vector<Robot> robots)
{
    for (Robot r : robots)
    {
        cout << "\nRobot position : " << r.getX() << ' ' << r.getY() << " ID: " << r.id << endl;
        string alive = r.alive ? "alive" : "dead";
        cout << "This robot is " << alive << endl;
    }
}
**/
/**
 * @param file_name
 * @param tiles
 * @param player
 * @brief Inserts values of file into a 2-D vector, in case of:
 * Robot - inserts it in robots. Player - changes it's values of x and y
 */
void read_file(string &file_name, vector<vector<char>> &tiles, Player &player,vector<Robot> &robots)
{
    unsigned int rows, columns;
    char useless;
    string line;
    ifstream file(file_name);
    unsigned robotCounterId = ONE;

    if (!file)
    {
        cout << "Can't open file" << endl;
    }
    else
    {
        file >> rows >> useless >> columns;
        //clear buffer
        file.ignore(256, '\n');

        tiles.resize(rows);
        for (unsigned int i = 0; i < tiles.size(); i++)
        {
            tiles[i].resize(columns);
        }
        bool onePlayer = false;
        for (unsigned int i = 0; i < rows; i++)
        {
            getline(file, line);
            for (unsigned int j = 0; j < columns; j++)
            {
                tiles[i][j] = line[j];
                if (line[j] == LIVEHUMAN && !onePlayer)
                {
                    player.setX(j);
                    player.setY(i);
                    //cout << "Player position :" << player.getX() << ' ' << player.getY() << endl;
                    onePlayer = true;
                }
                else if (line[j] == LIVEROBOT)
                {
                    Robot r1 = Robot(j, i, robotCounterId++);
                    robots.push_back(r1);
                }
                else if (line[j] == DEADROBOT)
                {
                    Robot r1 = Robot(j, i, robotCounterId++);
                    r1.killObj();
                    robots.push_back(r1);
                }
            }
        }
        //printRobotsPos(robots);
    }
    file.close();
}


/**
 * @param menu
 * @param tiles
 * @param player
 * @brief Verifies if file exists and calls read_file function
 */
string read_game(bool &menu, vector<vector<char>> &tiles, Player &player, vector<Robot> &robots)
{
    unsigned int maze_value;
    string file_name, write_name;
    string aux;

    //clear terminal
    cout << "\033[2J\033[1;1H";

    while (1)
    {
        cout << "Enter maze number: ";
        cin >> aux;

        maze_value = stoi(aux);
        file_name = "MAZE_";

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
        else if (maze_value > 0 && maze_value <= 99)
        {

            if(maze_value<10)
    	        aux = "0" + aux;
            write_name = file_name + aux + "_WINNERS.TXT";
            file_name = file_name  + aux + ".TXT";

            if (fileExists(file_name))
            {
                cout << "File exists" << endl;
                read_file(file_name, tiles, player,robots);
                file_name.clear();
                menu = false;
                return write_name;
                break;
            }
            else
            {
                cout << "File doesn't exist" << endl;
                continue;
            }
        }
        else if (maze_value == 0)
        {
            player.killObj();
            menu = true;
            break;
        }
        else
        {
            cout << "Enter a valid number between 0 and 99" << endl;
        }
    }
    return " ";
}

/**
 * @brief Places the player in its new position and changes its old position to empty (space).
 * 
 * @param tiles 
 * @param player 
 * @param prevX 
 * @param prevY 
 */
void placePlayer(vector<vector<char>> &tiles, Player player, const unsigned prevX, const unsigned prevY)
{
    tiles[prevY][prevX] = ' ';
    tiles[player.getY()][player.getX()] = LIVEHUMAN;
}

/**
 * @brief Checks if the player has collided against something
 * @param tiles 
 * @param player 
 * @return 0 if Collides and Kills player, 1 if Collides against dead robot (survives), 2 if Valid
 */
char checkCollision(vector<vector<char>> &tiles, Player &player)
{
    if(tiles[player.getY()][player.getX()] == LIVEHUMAN){
        return '2';
    }
    else if (tiles[player.getY()][player.getX()] != ' ')
    {
        if (tiles[player.getY()][player.getX()]==EXITDOOR){
            player.gotOut();
            return '4';
        }
        else if (tiles[player.getY()][player.getX()] == '*' || tiles[player.getY()][player.getX()] == LIVEROBOT)
        {
            player.killObj();
            return '0';
        }
        else
        {
            if (tiles[player.getY()][player.getX()] == DEADROBOT || tiles[player.getY()][player.getX()] == NONELECPOST)
            {
                printDeadRobotCollision();
                return '1';
            }
            else
            {
                player.killObj();
                return '0';
            }
        }
    }
    else
    {
        return '2';
    }
}
/**
 * @brief Moves robots according to the players current position
 * 
 * @param robot 
 * @param player 
 * @return Robot 
 */
Robot moveRobots(Robot r, Player p)
{
    int varX = r.getX() - p.getX(); 
    int varY = r.getY() - p.getY();

    if (varX > ZERO)
    {
        r.moveLeft();
    }
    else if (varX < ZERO)
    {
        r.moveRight();
    }
    if (varY > ZERO)
    {
        r.moveUp();
    }
    else if (varY < ZERO)
    {
        r.moveDown();
    }
    return r;
}
/**
 * @param tiles
 * @param player
 * @brief Moves robots one by one and checks any collisions
 */
void attackRobots(vector<vector<char>> &tiles, struct Player &player,vector<Robot> &robots)
{
    int prevX, prevY;
    for (Robot &r : robots)
    {
        if (!r.getState() )
        {
            continue;
        }
        else
        {
            prevX = r.getX(), prevY = r.getY();
            if (tiles[prevY][prevX] == LIVEHUMAN)
            {
                tiles[prevY][prevX] = LIVEROBOT;
                tiles[r.getY()][r.getX()] = DEADHUMAN;
                player.killObj();;
            }
            else if(tiles[prevY][prevX] == DEADROBOT){
                r.killObj();;
                continue;
            }
            r = moveRobots(r, player);
            if (tiles[r.getY()][r.getX()] == ' ')
            {
                tiles[prevY][prevX] = ' ';
                tiles[r.getY()][r.getX()] = LIVEROBOT;
            }
            else if ( tiles[r.getY()][r.getX()] == LIVEROBOT || tiles[r.getY()][r.getX()] == DEADROBOT)
            {
                tiles[r.getY()][r.getX()] = DEADROBOT;
                tiles[prevY][prevX] = ' ';
                r.killObj();
            }
            else if (tiles[r.getY()][r.getX()] == LIVEHUMAN)
            {
                tiles[prevY][prevX] = LIVEROBOT;
                tiles[r.getY()][r.getX()] = DEADHUMAN;
                printRobotVictory();
                wait();
                player.killObj();
            }
            else if (tiles[r.getY()][r.getX()] == NONELECPOST)
            {
                tiles[prevY][prevX] = ' ';
                tiles[r.getY()][r.getX()] = DEADROBOT;
                r.killObj();
            }
            else if (tiles[r.getY()][r.getX()] == FENCE){
                tiles[prevY][prevX] = DEADROBOT;
                r.setX(prevX);
                r.setY(prevY);
                r.killObj();
            }
        }
    }
}
/**
 *
 * @param tiles
 * @param player
 * @brief Receives a movement, verifies if valid, then alters the players position accordingly. Finally
 * moves the live robots according to the players movement.
 */
void movePlayer(vector<vector<char>> &tiles, struct Player &player,vector<Robot> &robots)
{
    int prevX = player.getX(), prevY = player.getY();
    char move, coll;

    while (1)
    {
        cout << "\nEnter movement player: ";
        cin >> move;
        if(!checkBuffer()){
            continue;
        }
        cout << NEWLINE;

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
        switch (toupper(move))
        {
            case 'A':
                player.moveLeft();
                break;
            case 'D':
                player.moveRight();
                break;
            case 'W':
                player.moveUp();
                break;
            case 'X':
                player.moveDown();
                break;
            case 'Z':
                player.moveLeft();
                player.moveDown();
                break;
            case 'Q':
                player.moveLeft();
                player.moveUp();
                break;
            case 'E':
                player.moveRight();
                player.moveUp();
                break;
            case 'C':
                player.moveDown();
                player.moveRight();
                break;
            case 'S':
                break;
            case '0':
                player.killObj();
                break;
            default:
                cout << "\033[2J\033[1;1H";
                drawMaze(tiles);
                printInvalidChar();
                continue;
        }
        coll = checkCollision(tiles, player);
        if (coll == '2')
        {
            placePlayer(tiles, player, prevX, prevY);
        }
        else if (coll == '1')
        {
            printInvalidChar();
            player.setX(prevX);
            player.setY(prevY);
            break;
        }
        else if (coll == '4')
        {
            placePlayer(tiles, player, prevX, prevY);
            break;
        }
        else
        {
            printRobotVictory();
            wait();
            break;
        }
        attackRobots(tiles, player,robots);
        //printRobotsPos(robots);
        break;
    }
}

/**
 * @brief While players is alive and all robots are alive, loops movePlayer
 * 
 * @param tiles 
 * @param player 
 */
void playGame(vector<vector<char>> &tiles, struct Player &player, vector<Robot> &robots)
{
    while (player.getState())
    {
        cout << "\033[2J\033[1;1H";
        drawMaze(tiles);
        if (player.isOut())
        {
            printHumanVictory();
            break;
        }
        movePlayer(tiles, player, robots);
    }
}

int main()
{
    vector<Robot> robots;
    bool menu = true, play = false, rules = false, exits = false;
    vector<vector<char>> tiles;
    Player player(0,0);
    string writeName, playerName;
    Txtread rulesFile("RULES.TXT");
    while (menu)
    {
        draw_menu(rules, play, exits);
        if (play)
        {
            play = false;

            robots.clear();

            Player player(0,0);

            printBeginGame();

            writeName = read_game(menu, tiles, player,robots);
            if(!player.getState()){
                continue;
            }

            auto start = chrono::steady_clock::now();
            playGame(tiles, player,robots);
            auto end = chrono::steady_clock::now();

            //Passes time from milliseconds to seconds
            player.setTime(chrono::duration_cast<chrono::seconds>(end - start).count());

            if (player.getState())
            {
                writeResults(writeName, player.getTime());
            }
        }

        else if (rules)
        {
            rulesFile.printFile();
            wait();
            rules = false;
        }

        else if (exits)
        {
            break;
        }
        menu = true;
    }
    printExit();
    return 0;
}