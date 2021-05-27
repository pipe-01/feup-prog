class Player: public Movable
{
private:
    unsigned time;
    bool out;
public:
    Player(unsigned int x, unsigned int y);
    void gotOut();
    bool isOut();
    void setTime(unsigned t);
    unsigned getTime();
    /**
    * @brief Checks if the player has collided against something
    * @param tiles 
    * @return 0 if Collides and Kills player, 1 if Collides against dead robot (survives), 2 if Valid
    */
    ~Player();
};