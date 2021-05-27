#include "position.h"
class Player
{
private:
    bool out = false;
    struct Position p;
    bool state = true;
public:
    Player(unsigned int x, unsigned int y);
    Player(): p(Position(0,0)) {}
    void gotOut();
    bool isOut();
    int getX();
    int getY();
    Position getPosition();
    void setX(unsigned int i);
    void setY(unsigned int j);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    bool getState();
    void killObj();
};