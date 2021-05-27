//T09_G01
#include <iostream>
#include <limits>
#include <fstream>
#include <vector>
#include "constants.h"

using namespace std;

class Draw
{
public:
    Draw() = default;
    void drawMaze(vector<vector<char>> tiles);
    void printDeadRobotCollision();
    void printInvalidChar();
    bool checkBuffer();
};