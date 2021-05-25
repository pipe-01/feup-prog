#include "movable.h"
using namespace std;

class Game
{
private:
    void showGameDisplay();
    Player player;
    vector<Robot> robots;
    vector<vector<char> tiles;
public:
    Game(const string & filename);
    bool play();
    void readFile();

};