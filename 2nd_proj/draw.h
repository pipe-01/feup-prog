//T09_G01

#include <iostream>
#include <limits>
#include <vector>
#include "constants.h"

using namespace std;
class Menu{
private:
    bool menu;
    bool rules;
    bool play;
    bool winners;
    bool leave;
    string mazeFile;
    string winnersFile;
public:
    Menu(bool rule, bool playgame, bool win, bool exits)
    {
        menu = true;
        rules = rule;
        play = playgame;
        winners = win;
        leave = exits;
    }
    void printMenuBanner();
    void wait();
    void printExit();
    void printInvalidChar();
    void printRobotVictory();
    void printHumanVictory();
    void draw_menu();
    void printBeginGame();
    bool checkBuffer();
    void setRules(bool sentence);
    void setPlay(bool sentence);
    void setExit(bool sentence);
    void setWinners(bool sentence);
    bool getState();
    bool getRules();
    bool getPlay();
    bool getWinners();
    bool getExit();
    void setState(bool sentence);
    bool readGame();
    string getMazeFile();
    string getWinnersFile();

};

class Draw
{
public:
    Draw() = default;
    void drawMaze(vector<vector<char>> tiles);
    void printDeadRobotCollision();
    void printInvalidChar();
};