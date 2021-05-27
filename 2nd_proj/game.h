
#include "iostream"
#include "robot.h"
#include "player.h"
#include "maze.h"
#include "draw.h"
#include "position.h"

using namespace std;

class Game
{
private:
    string fileName;
    Player player;
    vector<Robot> robots;
    Maze maze;
    Draw draw;
public:
    //void showGameDisplay();
    Game(string fileName);
    bool play();
    void readFile();
    void attackRobot();
    char checkPlayerCollision();
    void movePlayer();
    bool fileExists(const string &file_name);
    void printRobotsTester(); //tester function
};