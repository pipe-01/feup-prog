#include "movable.h"
#include "iostream"
#include "robot.h"
#include "player.h"
#include "maze.h"

using namespace std;

class Game
{
private:
    void showGameDisplay();
    string fileName;
    Player player;
    vector<Robot> robots;
    vector<vector<char> tiles;
    Maze maze;
public:
    Game(const string & filename);
    bool play();
    void readFile();
    void attackRobots();
    char getObjAt(Position pos) const;
};