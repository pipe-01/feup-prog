#include "post.h"
#include <unordered_map>

using namespace std; 

class Maze
{
private:
    unordered_map<Position,Post> postMap;
public:
    maze();
    void addPost(Position pos, Post p);
    char hasPost(Position pos);
};

maze::maze()
{
}

maze::~maze()
{
}