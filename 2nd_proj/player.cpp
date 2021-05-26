#include "player.h"

void Player::setTime(unsigned i)
{
    time = i;
}

unsigned Player::getTime()
{
    return time;
}

Player::Player(unsigned int x, unsigned int y)
    : Movable(x, y), out(false) {}

Player::~Player()
{
    state = false;
    x = 0;
    y = 0;
}

bool Player::isOut()
{
    return out;
}

void Player::gotOut()
{
    out = true;
}

char Player::checkCollision(vector<vector<char>> &tiles)
{
    if (tiles[getY()][getX()] == LIVEHUMAN)
    {
        return '2';
    }
    else if (tiles[getY()][getX()] != ' ')
    {
        if (tiles[getY()][getX()] == EXITDOOR)
        {
            gotOut();
            return '4';
        }
        else if (tiles[getY()][getX()] == '*' || tiles[getY()][getX()] == LIVEROBOT)
        {
            killObj();
            return '0';
        }
        else
        {
            if (tiles[getY()][getX()] == DEADROBOT || tiles[getY()][getX()] == NONELECPOST)
            {
                printDeadRobotCollision();
                return '1';
            }
            else
            {
                killObj();
                return '0';
            }
        }
    }
    else
    {
        return '2';
    }
}
