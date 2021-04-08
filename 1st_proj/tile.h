#include <iostream>
#include <string>

class Tile
{
private:
	char letter;
	unsigned int line;
	unsigned int column;
	bool state = isupper(letter); //True = live & False = dead
public:
	Tile();
	Tile(char letter, unsigned int line, unsigned int column);
	char getLetter() const;
	unsigned int getLine() const;
	unsigned int getColumn() const;
	bool getState() const {return state;};
	void setDeath(char val);
};

class Robot: public Tile{
protected:
    static unsigned int nextID;
public:
    static unsigned int id_number;
    Robot() = {id_number = ++nextID};
};

int Robot::nextID = 0;