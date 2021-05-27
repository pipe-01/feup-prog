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
#include "game.h"
#include "txtread.h"
#include "draw.h"

using namespace std;



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
/**
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
**/

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
/**
 * @brief Moves robots according to the players current position
 * 
 * @param robot 
 * @param player 
 * @return Robot
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
**/

/**
 *
 * @param tiles
 * @param player
 * @brief Receives a movement, verifies if valid, then alters the players position accordingly. Finally
 * moves the live robots according to the players movement.
 */
void movePlayer()
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
        coll = player.checkCollision(tiles);
        if (coll == '2')
        {
            player.placeObj(tiles, prevX, prevY);
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
            player.placeObj(tiles, prevX, prevY);
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
void playGame(vector<vector<char>> &tiles, Player &player, vector<Robot> &robots)
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
    Menu menu = Menu(false, false, false, false);
    string writeName, playerName;
    Txtread rulesFile("RULES.TXT");
    while (menu.getState())
    {
        menu.draw_menu(rules, play, exits);
        if (menu.getPlay())
        {
            menu.printBeginGame();

            writeName = read_game(menu, tiles, player,robots);

            Game game(writeName);
            
            if(!player.getState()){
                continue;
            }

            auto start = chrono::steady_clock::now();
            // playGame(tiles, player,robots);
            auto end = chrono::steady_clock::now();

            //Passes time from milliseconds to seconds
            player.setTime(chrono::duration_cast<chrono::seconds>(end - start).count());

            if (player.getState())
            {
                writeResults(writeName, player.getTime());
            }
        }

        else if (menu.getRules())
        {
            rulesFile.printFile();
            menu.wait();
            menu.setRules(false);
        }

        else if(menu.getWinners){
            printf("Mostrar winners\n");
        }

        else if (menu.getExit)
        {
            break;
        }
        menu.setState(true);
    }
    menu.printExit();
    return 0;
}