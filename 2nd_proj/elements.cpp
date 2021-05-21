struct Movement
{
 int dRow, dCol; // displacement, taking into account the chosen movement
};
///////////////////////////////////////////////////////////////////////////////

struct Position
{
 int row, col;
};
///////////////////////////////////////////////////////////////////////////////

class Player {
public:
 Player(int row, int col, char symbol);
 int getRow() const;
 int getCol() const;
 char getSymbol() const;
 bool isAlive() const;
 void setAsDead();
 bool move(Movement delta);
private:
 int row, col;
 bool alive;
 char symbol;
};

///////////////////////////////////////////////////////////////////////////////

class Robot {
public:
 enum State { ALIVE, STUCK, DEAD };
 Robot(int row, int col);
 int getID() const;
 char getSymbol() const; // get char representation of robot (R if alive, r if dead)
 int getRow() const;
 int getCol() const;
 Position getPosition() const;
 bool isAlive() const;
 void setRow(int x);
 void setCol(int y);
 void setPosition(const Position &pos);
 void setAsDead();
 //other methods
private:
 static int robotCounter; //used to attribute automatically the id to the robots
 int id;
 int row, col;
 bool alive;
 // other attributes (?)
};

///////////////////////////////////////////////////////////////////////////////

class Post {
public:
 Post(int row, int col, char type);
 int getRow() const;
 int getCol() const;
 char getSymbol() const; // get char representation of Post
 bool isElectrified() const;
 //other methods
private:
 int row, col;
 char type; // '*' - electrified; '+'- non-electrified
 // other attributes (?)
 // 