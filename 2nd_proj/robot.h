#include "position.h"
#include "constants.h"
class Robot
{
private:
    static int id;
    struct Position p;
    bool state;
public:
    Robot(unsigned int x,unsigned int y);
    ~Robot();
    int getId();
    void moveRobot(Position);
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