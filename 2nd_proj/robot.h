#include "position.h"
#include "constants.h"
class Robot
{
private:
    struct Position p;
    bool state;
    const int id;
    static int staticId;
public:
    /**
     * @brief Construct a new Robot object
     * 
     * @param x 
     * @param y 
     */
    Robot(unsigned int x,unsigned int y);
    /**
     * @brief Destroy the Robot object
     * 
     */
    ~Robot();
    /**
     * @brief Get the Id object
     * 
     * @return int 
     */
    int getId();
    /**
     * @brief moves Robot
     * 
     */
    void moveRobot(Position);
    /**
     * @brief returns p.x
     * 
     * @return int 
     */
    int getX() const;
    /**
     * @brief returns p.y
     * 
     * @return int 
     */
    int getY() const;
    /**
     * @brief Get the Position object
     * 
     * @return Position 
     */
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
     * @param i 
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