#include "post.h"
#include <unordered_map>
#include <vector>

using namespace std; 

class Maze
{
private:
    int row, col;
    unordered_map<Position,Post> postMap;
    vector<vector<char>> board;
public:
    Maze() = default;
    void setRow(int r);
    void setCol(int c);
    vector<vector<char>> getBoard() const;
    char getObjAt(Position pos) const;
    void setObjAt(Position pos, char obj); 
    void setObjAt(int x, int y, char obj);
    void addPost(Position pos, Post p);
    char hasPost(Position pos);
    void resizeBoard();
};