
class Post
{
private:
    bool electric;
public:
    /**
     * @brief Construct a new Post object
     * 
     * @param e 
     */
    Post(bool e){electric = e;}
    /**
     * @brief returns electric
     * 
     * @return true 
     * @return false 
     */
    bool isElectric();
    /**
     * @brief sets electric to false
     * 
     */
    void notElectric();
};