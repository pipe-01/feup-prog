#include "position.h"

class Player
{
private:
    bool out;
    struct Position p;
    bool state;
public:
    Player(unsigned int x, unsigned int y);
    void gotOut();
    bool isOut();
    int getX() const;
    int getY() const;
    Position getPosition() const;
    void setX(unsigned int i);
    void setY(unsigned int j);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    bool getState();
    void killObj();
};