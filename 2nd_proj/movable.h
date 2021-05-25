#include "constants.h"
class Movable
{
protected:
    unsigned int x,y;
    bool state;
public:
    Movable(unsigned int i, unsigned int j){
        x = i;
        y = j;
        state = true;
    }
    int getX();
    int getY();
    void setX(unsigned int i);
    void setY(unsigned int j);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    bool getState();
    void killObj();
    virtual void placeObj(vector<vector<char>> &tiles, const unsigned prevX, const unsigned prevY) = 0;
};

class Robot: public Movable
{
private:
    int id;
public:
    Robot(unsigned int x,unsigned int y,unsigned int id);
    ~Robot();
    void placeObj(vector<vector<char>> &tiles, const unsigned prevX, const unsigned prevY);
};

class Player: public Movable
{
private:
    unsigned time;
    bool out;
public:
    Player(unsigned int x, unsigned int y);
    void gotOut();
    bool isOut();
    void setTime(unsigned t);
    unsigned getTime();
    /**
    * @brief Checks if the player has collided against something
    * @param tiles 
    * @return 0 if Collides and Kills player, 1 if Collides against dead robot (survives), 2 if Valid
    */
    char checkCollision(vector<vector<char>> &tiles);
    /**
    * @brief Places the player in its new position and changes its old position to empty (space).
    * @param tiles 
    * @param prevX 
    * @param prevY 
    */
    void placeObj(vector<vector<char>> &tiles, const unsigned prevX, const unsigned prevY);
    ~Player();
};