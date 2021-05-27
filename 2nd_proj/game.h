#include "movable.h"
#include "iostream"
#include "robot.h"
#include "player.h"
#include "maze.h"
#include "readwrite.h"

using namespace std;

class Game
{
private:
    string fileName;
    Player player;
    vector<Robot> robots;
    Maze maze;
public:
    //void showGameDisplay();
    Game(const string & filename);
    bool play();
    void readFile();
    void attackRobot(Robot &r);
    char checkPlayerCollision();
    void movePlayer();
    void placePlayer();
    string read_game(bool &menu, vector<vector<char>> &tiles, Player &player, vector<Robot> &robots);
    bool fileExists(const string &file_name);
};