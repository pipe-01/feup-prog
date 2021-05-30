#include "position.h"
class Player
{
private:
    bool out = false;
    struct Position p;
    bool state = true;
public:
    /**
     * @brief Construct a new Player object
     * 
     * @param x 
     * @param y 
     */
    Player(unsigned int x, unsigned int y);
    /**
     * @brief Construct a new Player object and set to (0,0)
     * 
     */
    Player(): p(Position(0,0)) {}
    /**
     * @brief sets out to true
     * 
     */
    void gotOut();
    /**
     * @brief returns out
     * 
     * @return true 
     * @return false 
     */
    bool isOut();
    /**
     * @brief return p.x
     * 
     * @return int 
     */
    int getX();
    /**
     * @brief return p.y
     * 
     * @return int 
     */
    int getY();
    Position getPosition();
    /**
     * @brief sets p.x
     * 
     * @param i 
     */
    void setX(unsigned int i);
    /**
     * @brief sets p.y
     * 
     * @param j 
     */
    void setY(unsigned int j);
    /**
     * @brief moves player up
     * 
     */
    void moveUp();
    /**
     * @brief moves player down
     * 
     */
    void moveDown();
    /**
     * @brief moves player left
     * 
     */
    void moveLeft();
    /**
     * @brief moves player right
     * 
     */
    void moveRight();
    /**
     * @brief Get the State object
     * 
     * @return true 
     * @return false 
     */
    bool getState();
    /**
     * @brief sets state to false
     * 
     */
    void killObj();
};