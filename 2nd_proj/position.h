#ifndef POSITION_H
#define POSITION_H

struct Position
{
    int x;
    int y;

    Position(int i, int j) 
        : x(i), y(j) {}
    Position()
        : x(0), y(0) {}

    bool equals(Position p1){
        return x == p1.x && y == p1.y;
    }    
            
    bool operator == (Position p1) const {
        return x == p1.x && y == p1.y;
    }

    bool operator<(Position o)  const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

#endif