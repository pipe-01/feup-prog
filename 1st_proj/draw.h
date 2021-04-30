//T09_G01

#include <iostream>
#include <limits>
#include <vector>
#include "constants.h"

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
void drawMaze(const vector<vector<char>> tiles);
void printBeginGame();
bool checkBuffer();