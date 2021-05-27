#include "position.h"
#include "constants.h"
class Robot
{
private:
    struct Position p;
    bool state;
    const int id;
    static int staticId;
public:
    Robot(unsigned int x,unsigned int y);
    ~Robot();
    int getId();
    void moveRobot(Position);
    int getX() const;
    int getY() const;
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