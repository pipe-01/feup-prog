#include "game.h"

Game::Game(const string& filename){
    fileName = fileName;
}
char Game::getObjAt(Position pos) const{
    return tiles[pos.y][pos.x];
}
void Game::attackRobot(Robot &r)
{
    int prevX, prevY;
    if (!r.getState() )
    {
        return false;
    }
    else
    {
        prevX = r.getX(), prevY = r.getY();
        if (r.getPosition() = player.getPosition())
        {
            tiles[prevY][prevX] = LIVEROBOT;
            tiles[r.getY()][r.getX()] = DEADHUMAN;
            player.killObj();
        }
        else if(getObjAt(r.getPosition()) == DEADROBOT){
            r.killObj();;
            return
        }
        moveRobot(r, player);
        if (getObjAt(r.getPosition()) == SPACEBAR)
        {
            tiles[prevY][prevX] = SPACEBAR;
            tiles[r.getY()][r.getX()] = LIVEROBOT;
        }
        else if ( getObjAt(r.getPosition()) == LIVEROBOT || getObjAt(r.getPosition()) == DEADROBOT)
        {
            tiles[r.getY()][r.getX()] = DEADROBOT;
            tiles[prevY][prevX] = ' ';
            r.killObj();
        }
        else if (r.getPosition() == player.getPosition())
        {
            tiles[prevY][prevX] = LIVEROBOT;
            tiles[r.getY()][r.getX()] = DEADHUMAN;
            player.killObj();
            printRobotVictory();
            wait();
        }
        else if (maze.hasPost(r.getPosition()) == '1')
        {
            tiles[prevY][prevX] = ' ';
            tiles[r.getY()][r.getX()] = DEADROBOT;
            r.killObj();
        }
        else if (maze.hasPost(r.getPosition()) == '2'){
            tiles[prevY][prevX] = DEADROBOT;
            r.setX(prevX);
            r.setY(prevY);
            r.killObj();
        }
    }

}

void Game::readFile{
{
    unsigned int rows, columns;
    char useless;
    string line;
    ifstream file(fileName);

    if (!file)
    {
        cout << "Can't open file" << endl;
    }
    else
    {
        file >> rows >> useless >> columns;
        //clear buffer
        file.ignore(256, '\n');

        tiles.resize(rows);
        for (unsigned int i = 0; i < tiles.size(); i++)
        {
            tiles[i].resize(columns);
        }
        bool onePlayer = false;
        for (unsigned int i = 0; i < rows; i++)
        {
            getline(file, line);
            for (unsigned int j = 0; j < columns; j++)
            {
                tiles[i][j] = line[j];
                if (line[j] == LIVEHUMAN && !onePlayer)
                {
                    player = Player(j,i);
                    //cout << "Player position :" << player.getX() << ' ' << player.getY() << endl;
                    onePlayer = true;
                }
                else if (line[j] == LIVEROBOT)
                {
                    Robot r1 = Robot(j,i);
                    robots.push_back(r1);
                }
                else if (line[j] == DEADROBOT)
                {
                    Robot r1 = Robot(j, i);
                    r1.killObj();
                    robots.push_back(r1);
                }
                else if(line[j] == FENCE){
                    maze.put(Position(j,i), Post(true));
                }
                else if(line[j] == NONELECPOST){
                    maze.put(Position(j,i), Post(false));
                }
            }
        }
        //printRobotsPos(robots);
    }
    file.close();
}
}