#ifndef POSITION_H
#define POSITION_H
struct Position
{
    int x;
    int y;
    bool operator==(const Position &o) const {
        return x == o.x && y == o.y;
    }

    bool operator<(const Position &o)  const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

#endif