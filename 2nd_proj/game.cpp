#include "game.h"


Game::Game(string fileName){
    this->fileName = fileName;
}

void Game::attackRobot()
{
    for(size_t i = 0; i < robots.size(); i++){
        int prevX, prevY;
        char newPos;
        if (!robots[i]->getState() )
        {
            cout << "Robot is dead" << endl;
            return;
        }
        else
        {
            prevX = robots[i]->getX(), prevY = robots[i]->getY();

            cout << "\nRobot: " << robots[i]->getState() << " X: " << robots[i]->getX() << " Y: "<<robots[i]->getY() << endl;
            cout << "\nPlayer: " << player.getState() << " X: " << player.getX() << " Y: "<<player.getY() << endl;
            cout << "\nObject in current position: "<< maze.getObjAt(robots[i]->getPosition()) << endl;

            if (robots[i]->getX() == player.getX() && robots[i]->getY() == player.getY())
            {
                cout << "got here3\n";
                maze.setObjAt(prevY,prevX,LIVEROBOT);
                maze.setObjAt(robots[i]->getPosition(),DEADHUMAN);
                player.killObj();
                cout << "got here2\n";
            }
            else if(maze.getObjAt(robots[i]->getPosition()) == DEADROBOT){
                cout << "got here1\n";
                robots[i]->killObj();
                return;
            }
            cout << "\nbefore move\n";
            robots[i]->moveRobot(player.getPosition());
            newPos = maze.getObjAt(robots[i]->getPosition());
            cout << "\nafter move\n";
            if (newPos == SPACEBAR)
            {
                maze.setObjAt(prevY,prevX,SPACEBAR);
                maze.setObjAt(robots[i]->getPosition(),LIVEROBOT);
            }
            else if (newPos == LIVEROBOT || newPos == DEADROBOT)
            {
                maze.setObjAt(robots[i]->getPosition(),DEADROBOT);
                maze.setObjAt(prevY,prevX,SPACEBAR);
                robots[i]->killObj();
            }
            else if (robots[i]->getPosition() == player.getPosition())
            {
                maze.setObjAt(prevY,prevX,LIVEROBOT);
                maze.setObjAt(robots[i]->getPosition(),DEADHUMAN);
                player.killObj();
            }
            else if (maze.hasPost(robots[i]->getPosition()) == '1')
            {
                maze.setObjAt(prevY,prevX,SPACEBAR);
                maze.setObjAt(robots[i]->getPosition(),DEADROBOT);
                robots[i]->killObj();
            }
            else if (maze.hasPost(robots[i]->getPosition()) == '2'){
                maze.setObjAt(prevY,prevX,DEADROBOT);
                robots[i]->setX(prevX);
                robots[i]->setY(prevY);
                robots[i]->killObj();
            }
            cout << robots[i]->getState() << " X: " << robots[i]->getX() << " Y: "<<robots[i]->getY() << endl;
            cout << "\nObject in final position: "<< maze.getObjAt(robots[i]->getPosition()) << endl;
            cout << "\nendfunction\n";
        }
    }    

}

void Game::readFile()
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

        maze.setCol(columns);
        maze.setRow(rows);
        maze.resizeBoard();
        
        bool onePlayer = false;
        for (unsigned int i = 0; i < rows; i++)
        {
            getline(file, line);
            for (unsigned int j = 0; j < columns; j++)
            {
                maze.setObjAt(i,j, line[j]);
                if (line[j] == LIVEHUMAN && !onePlayer)
                {
                    player.setX(j);
                    player.setY(i);
                    cout << "Player position :" << player.getX() << ' ' << player.getY() << endl;
                    onePlayer = true;
                }
                else if (line[j] == LIVEROBOT)
                {
                    Robot* r1 = new Robot(j,i);
                    robots.push_back(r1);
                }
                else if (line[j] == DEADROBOT)
                {
                    Robot* r1 = new Robot(j, i);
                    r1->killObj();
                    robots.push_back(r1);
                }
                else if(line[j] == FENCE){
                    maze.addPost(Position(j,i), Post(true));
                }
                else if(line[j] == NONELECPOST){
                    maze.addPost(Position(j,i), Post(false));
                }
            }
        }
        printRobotsTester();
    }
    file.close();
}

void Game::movePlayer()
{
    Position prevPos = player.getPosition();
    char move, coll;

    while (1)
    {
        cout << "\nEnter movement player: ";
        cin >> move;
        if(!draw.checkBuffer()){
            continue;
        }
        cout << NEWLINE;

        if (cin.fail())
        {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You have entered wrong input" << endl;

            if (cin.eof())
            {
                exit(0);
            }
        }
        switch (toupper(move))
        {
            case 'A':
                player.moveLeft();
                break;
            case 'D':
                player.moveRight();
                break;
            case 'W':
                player.moveUp();
                break;
            case 'X':
                player.moveDown();
                break;
            case 'Z':
                player.moveLeft();
                player.moveDown();
                break;
            case 'Q':
                player.moveLeft();
                player.moveUp();
                break;
            case 'E':
                player.moveRight();
                player.moveUp();
                break;
            case 'C':
                player.moveDown();
                player.moveRight();
                break;
            case 'S':
                break;
            case '0':
                player.killObj();
                break;
            default:
                cout << "\033[2J\033[1;1H";
                draw.drawMaze(maze.getBoard());
                draw.printInvalidChar();
                continue;
        }
        coll = checkPlayerCollision();
        if (coll == '2')
        {
            maze.setObjAt(prevPos,' ');
            maze.setObjAt(player.getPosition(), LIVEHUMAN);
        }
        else if (coll == '1')
        {
            draw.printInvalidChar();
            player.setX(prevPos.x);
            player.setY(prevPos.y);
        }
        else if (coll == '4')
        {
            maze.setObjAt(player.getPosition(),LIVEHUMAN);
            break;
        }
        else
        {
            break;
        }
        attackRobot();
        break;
    }
}

char Game::checkPlayerCollision()
{
    
    if (maze.getObjAt(player.getPosition()) == LIVEHUMAN)
    {
        return '2';
    }
    else if (maze.getObjAt(player.getPosition()) != ' ')
    {
        if (maze.getObjAt(player.getPosition()) == EXITDOOR)
        {
            player.gotOut();
            return '4';
        }
        else if (maze.getObjAt(player.getPosition()) == '*' || maze.getObjAt(player.getPosition()) == LIVEROBOT)
        {
            player.killObj();
            return '0';
        }
        else
        {
            if (maze.getObjAt(player.getPosition()) == DEADROBOT || maze.getObjAt(player.getPosition()) == NONELECPOST)
            {
                draw.printDeadRobotCollision();
                return '1';
            }
            else
            {
                player.killObj();
                return '0';
            }
        }
    }
    else
    {
        return '2';
    }
}

bool Game::play(){

    while (player.getState())
    {
        cout << "\033[2J\033[1;1H";
        draw.drawMaze(maze.getBoard());
        if (player.isOut())
        {
            return true;
        }
        movePlayer();
    }
    return false;
}


void Game::printRobotsTester(){
    for(int i = 0; i < robots.size(); i++){
        cout << "\nId: " << robots[i]->getId() << " State: " << robots[i]->getState() << " X:"<< robots[i]->getX() << " Y: " <<robots[i]->getY();
        cout << "\n";
    }
}