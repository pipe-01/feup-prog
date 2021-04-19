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
#include "draw.h"

using namespace std;

unsigned robotCounterId = 1; //sequential identification number

struct Player{
    int x, y;
    bool isAlive;
};

struct Robot
{
    int x, y;
    int id = robotCounterId++;
    bool alive = true;
    void killRobot(){alive = false;}
    Robot(int i, int j){x = i; y = j;};
};

vector<Robot> robots; //Accessed several times



int draw_menu(bool &rules, bool &play, bool &exits)
{
    int cmenu;

    printMenuBanner();
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


void drawMaze(vector<vector<char>> tiles){

    //clear terminal
    cout << "\033[2J\033[1;1H";

    for (size_t i = 0; i < tiles.size(); i++)
    {
        for (size_t j = 0; j < tiles[i].size(); j++)
        {
            cout << tiles[i][j];
        }
        cout << endl;
    }
}

void read_file(string &file_name, vector<vector<char>> &tiles, struct Player &player)
{
    int rows, columns;
    char useless;
    string line;
    ifstream file(file_name);

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
        for (int i = 0; i < tiles.size(); i++){
            tiles[i].resize(columns);
        }

        for (int i = 0; i < rows; i++){
            getline(file, line);
            for (int j = 0; j < columns; j++){
                tiles[i][j] = line[j];
                if(line[j] == LIVEHUMAN){
                    player.x = j;
                    player.y = i;
                    cout << "Player position :" << player.x << ' ' << player.y << endl;
                } else if(line[j] == LIVEROBOT){
                    Robot r1 = Robot(j, i);
                    robots.push_back(r1);
                    cout << "Robot position :" << j << ' ' << i << endl;
                }
            }
        }
    }
    file.close();
}

int read_game(bool &menu, vector<vector<char>> &tiles, struct Player &player)
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
                read_file(file_name, tiles, player);
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
                read_file(file_name, tiles,player);
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

void placePlayer(vector<vector<char>> &tiles, struct Player player, int prevX, int prevY){
    tiles[player.y][player.x] = LIVEHUMAN;
    tiles[prevY][prevX] = ' ';
}

//0 -> Collides and Kills player
//1 -> Collides against dead robot (survives)
//2 -> Valid
char checkCollision(vector<vector<char>> &tiles, struct Player &player){
    if(tiles[player.y][player.x] != ' '){
        if(tiles[player.y][player.x] == '*'){
            player.isAlive = false;
            return '0';
        }
        else{
            if(tiles[player.y][player.x] == DEADROBOT){
                printDeadRobotCollision();
                return '1';
            }
            else{
                player.isAlive = false;
                return '0';
            }
        }
    }
    else{
        return '2';
    }
}

void movePlayer(vector<vector<char>> &tiles, struct Player &player){
    int prevX = player.x, prevY = player.y;
    char move, coll;

    while(1){
        cout << "Enter movement player: ";
        cin >> move;


        if (cin.fail()){

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You have entered wrong input" << endl;

            if (cin.eof()){
                exit(0);
            }
        }
        else if(move == 'A' || move == 'a'){
            player.x--;
        }
        else if(move == 'D' || move == 'd'){
            player.x++;

        }
        else if(move == 'W' || move == 'w'){
            player.y--;

        }
        else if(move == 'X' || move == 'x'){
            player.y++;
        }
        else if(move == 'Z' || move == 'z'){
            player.x--;
            player.y++;
        }
        else if(move == 'Q' || move == 'q'){
            player.x--;
            player.y--;

        }
        else if(move == 'E' || move == 'e'){
            player.x++;
            player.y--;
        }
        else if(move == 'C' || move == 'c'){
            player.x++;
            player.y++;

        }
        else if(move == 'S' || move == 's'){
            break;
        }
        else if(move == '0'){
            player.isAlive = false;
        }
        else{
            printInvalidChar();
            continue;
        }
        //Basicamente esta parte aqui primeiro verifica se ha algum tipo de colisão e se sim, qual. Depois
        //Posiciona o jogador na posição nova caso não exista nenhum tipo de colisão
        coll = checkCollision(tiles,player);
        if(coll == '2'){
            placePlayer(tiles,player,prevX, prevY);
        }
        else if(coll == '1'){
            player.x = prevX;
            player.y = prevY;
        }
        break;
    }
}


void playGame(vector<vector<char>> &tiles, struct Player &player){
    while(player.isAlive){
        drawMaze(tiles);
        movePlayer(tiles, player);
    }
}

int main()
{
    bool menu = true, play = false, rules = false, exits = false;
    vector<vector<char>> tiles;
    struct Player player;
    player.isAlive = true;

    while (menu)
    {

        draw_menu(rules, play, exits);

        if (play)
        {
            cout << "Playing game" << endl;
            read_game(menu, tiles, player);
            //Depois desta função o valor de player.x e player.y não é alterado
            play = false;
            playGame(tiles, player);
        }

        if (rules)
        {
            printRules();
            rules = false;
        }

        if (exits)
        {
            exits = false;
            menu = false;
            printExit();
            exit(0);
        }
    }
    return 0;
}