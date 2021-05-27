#ifndef POSITION_H
#define POSITION_H

struct Position
{
    int x;
    int y;

    Position(int x=0, int y=0) 
        : x(x), y(y) {}

    bool operator == (const Position &o) const {
        return x == o.x && y == o.y;
    }

    bool operator<(const Position &o)  const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

#endif