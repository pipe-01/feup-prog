#include "post.h"
#include <map>
#include <vector>
#include "position.h"

using namespace std; 

class Maze
{
private:
    int row, col;
    static map<Position,Post> postMap;
    vector<vector<char>> board;
public:
    Maze() = default;
    void setRow(int r);
    void setCol(int c);
    vector<vector<char>> getBoard() const;
    char getObjAt(Position pos) const;
    void setObjAt(Position pos, char obj); 
    void setObjAt(int x, int y, char obj);
    void addPost(Position, Post p);
    char hasPost(Position);
    void resizeBoard();
};