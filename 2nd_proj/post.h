
class Post
{
private:
    bool electric;
public:
    Post(bool e);
    bool isElectric();
    void notElectric();
};

Post::Post(bool e)
{
    electric = e;
}