#include "maze.h"

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

vector<vector<char>> Maze::getBoard() const
{
    return board;
}

char Maze::getObjAt(Position pos) const{
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
    for (size_t i = 0; i < board.size(); i++)
    {
        board[i].resize(col);
    }
}

map<Position, Post> Maze::postMap;