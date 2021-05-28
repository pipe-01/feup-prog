
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
    /**
     * @brief Main function of the game, loops while player not dead or hasn't escaped
     * 
     * @return true 
     * @return false 
     */
    bool play();
    /**
     * @brief Opens fileName text file and inserts the player/robots/fences into the board (which is inside the maze)
     * 
     */
    void readFile();
    /**
     * @brief Moves robot by robot (in order of there ID) closer to the player and checks for collisions
     * 
     */
    void attackRobot();
    /**
     * @brief checks player collisions
     * 
     * @return char 2: valid move 4: exit door 0: player dies 1: against non-electric post/dead robot
     */
    char checkPlayerCollision();
    /**
     * @brief Moves player according to user's input
     * 
     */
    void movePlayer();
    /**
     * @brief verifies if file_name exists
     * 
     * @param file_name 
     * @return true 
     * @return false 
     */
    bool fileExists(const string &file_name);
    /**
     * @brief Tester function (uncomment to check robot status,id & position)
     * 
     */
    void printRobotsTester(); //tester function
};