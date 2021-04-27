#include <iostream>
#include <limits>

using namespace std;

void printMenuBanner();
void wait();
void printRules();
void printDeadRobotCollision();
void printExit();
void printInvalidChar();
void printRobotVictory();
void printHumanVictory();
int draw_menu(bool &rules, bool &play, bool &exits);
void drawMaze(vector<vector<char>> tiles);
void printBeginGame();
