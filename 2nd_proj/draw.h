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
    /**
     * @brief displays board
     * 
     * @param tiles 
     */
    void drawMaze(vector<vector<char>> tiles);
    /**
     * @brief prints whenever the player collides against a deadrobot
     */
    void printDeadRobotCollision();
    /**
     * @brief print when invalid input
     * 
     */
    void printInvalidChar();
    /**
     * @brief check if buufer is empty
     * 
     * @return true if empty
     * @return false if not empty
     */
    bool checkBuffer();
};