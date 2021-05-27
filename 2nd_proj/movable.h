#include "constants.h"
#include "position.h"

class Movable
{
protected:
    struct Position p;
    bool state;
public:
    Movable(unsigned int i, unsigned int j){
        p.x = i;
        p.y = j;
        state = true;
    }
    int getX() const;
    int getY() const;
    int getPosition();
    void setX(unsigned int i);
    void setY(unsigned int j);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    bool getState();
    void killObj();
};