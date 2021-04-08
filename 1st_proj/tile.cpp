#include "tile.h"

Tile::Tile() {
	letter = '\0';
	line = 0;
	column = 0;
}

Tile::Tile(char letter, unsigned int line, unsigned int column) {
	letter = letter;
	line = line;
	column = column;
}


char Tile::getLetter() const {
	return (letter);
}

unsigned int Tile::getLine() const {
	return (line);
} 

unsigned int Tile::getColumn() const {
	return (column);
}

void Tile::setDeath(char val) {
    letter = val;
}