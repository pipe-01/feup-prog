#include "robot.h"

Robot::Robot(unsigned int x, unsigned int y){
    Movable(x,y);
    ++id;
}

Robot::~Robot()
{
    state = false;
}

int Robot::id = 0;

int Robot::getId(){
    return id;
}

void Robot::moveRobot(Position pos){
    int varX = p.x - pos.x; 
    int varY = p.y - pos.y;

    if (varX > ZERO)
    {
        moveLeft();
    }
    else if (varX < ZERO)
    {
        moveRight();
    }
    if (varY > ZERO)
    {
        moveUp();
    }
    else if (varY < ZERO)
    {
        moveDown();
    }
}