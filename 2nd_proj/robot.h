class Robot: public Movable
{
private:
    static int id;
public:
    Robot(unsigned int x,unsigned int y);
    ~Robot();
    int getId();
    void moveRobot(Position pos);
};