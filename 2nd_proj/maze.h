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
    /**
     * @brief Set the Row object
     * 
     * @param r 
     */
    void setRow(int r);
    /**
     * @brief Set the Col object
     * 
     * @param c 
     */
    void setCol(int c);
    /**
     * @brief Get the Board object
     * 
     * @return vector<vector<char>> 
     */
    vector<vector<char>> getBoard();
    /**
     * @brief Get the obj at
     * 
     * @param pos 
     * @return char 
     */
    char getObjAt(Position pos);
    /**
     * @brief Set the Obj at pos
     * 
     * @param pos 
     * @param obj 
     */
    void setObjAt(Position pos, char obj); 
    /**
     * @brief Set the Obj At pos(x,y)
     * 
     * @param x 
     * @param y 
     * @param obj 
     */
    void setObjAt(int x, int y, char obj);
    /**
     * @brief add post to map
     * 
     * @param p 
     */
    void addPost(Position, Post p);
    /**
     * @brief checks if there is a post at a certain position
     * 
     * @return char 
     */
    char hasPost(Position);
    /**
     * @brief Resizes board
     * 
     */
    void resizeBoard();
};