#include "maze.h"

void Maze::addPost(Position pos, Post p){
    postMap.insert({pos,p});
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