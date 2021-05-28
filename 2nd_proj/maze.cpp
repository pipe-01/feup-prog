#include "maze.h"
#include <iostream>

void Maze::addPost(Position pos, Post p){
    postMap.insert(pair<Position,Post>(pos,p));
}

char Maze::hasPost(Position pos){
    for(auto x: postMap){
        if(x.first == pos){
            return x.second.isElectric()?'2':'1';
        }
    }
    return '0';
}

vector<vector<char>> Maze::getBoard()
{
    return board;
}

char Maze::getObjAt(Position pos){
    //cout << "\n\nInside GOA: " <<pos.x << " " << pos.y << endl;
    return board[pos.y][pos.x];
}

void Maze::setCol(int c){
    col = c;
}

void Maze::setRow(int r){
    row = r;
}

void Maze::setObjAt(Position pos, char obj){
    //cout << "Should be empt"<< board[pos.y][pos.x] << "y\n";
    board[pos.y][pos.x] = obj;
    //cout << board[pos.y][pos.x] << " Object at (pos) " << pos.y << " " << pos.x<< "\n";
}

void Maze::setObjAt(int x, int y, char obj){
    //cout << "Previous on board (should be R)" << board[x][y];
    board[x][y] = obj;
    //cout << obj << "Object at (x, y) " << x << "  "<< y << "\n";
}

void Maze::resizeBoard()
{
    board.resize(row);
    for (size_t i = 0; i < board.size(); i++)
    {
        board[i].resize(col);
    }
}

map<Position, Post> Maze::postMap;