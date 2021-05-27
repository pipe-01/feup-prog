#include "maze.h"

void Maze::addPost(Position pos, Post p){
    postMap.insert(pos,p);
}

char Maze::hasPost(Position pos){
    if(postMap.find(pos) != postMap.end()){
        if(postMap.at(Pos).isElectric()){
            return '2';
        }
        else{
            return '1';
        }
    }
    return '0';
}

vector<vector<char>> Maze::getBoard()
{
    return board;
}

char Maze::getObjAt(Position pos){
    return board[pos.x][pos.y];
}

void Maze::setCol(int c){
    col = c;
}

void Maze::setRow(int r){
    row = r;
}

void Maze::setObjAt(Position pos, char obj){
    board[pos.x][pos.y] = obj;
}

void Maze::setObjAt(int x, int y, char obj){
    board[x][y] = obj;
}

void Maze::resizeBoard()
{
    board.resize(row);
    for (unsigned int i = 0; i < row; i++)
    {
        board[i].resize(col);
    }
}