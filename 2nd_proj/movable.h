class Movable
{
protected:
    unsigned int x,y;
    bool state;
public:
    Movable(unsigned int i, unsigned int j){
        x = i;
        y = j;
        state = true;
    }
    int getX();
    int getY();
    void setX(unsigned int i);
    void setY(unsigned int j);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    bool getState();
    void killObj();
};

class Robot: public Movable
{
private:
    int id;
public:
    Robot(unsigned int x,unsigned int y,unsigned int id);
    ~Robot();
};

class Player: public Movable
{
private:
    unsigned time;
    bool out;
public:
    Player(unsigned int x, unsigned int y);
    void gotOut();
    bool isOut();
    void setTime(unsigned t);
    unsigned getTime();
    ~Player();
};