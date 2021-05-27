#include "game.h"


Game::Game(string fileName){
    this->fileName = fileName;
}

void Game::attackRobot()
{
    for(Robot &r : robots){
        int prevX, prevY;
        char newPos;
        if (!r.getState())
        {
            cout << "\nRobot is dead\n" << endl;
            continue;
        }
        else
        {
            prevX = r.getX(), prevY = r.getY();
            printRobotsTester();
            //cout << "\nRobot: " << robots[i].getState() << " X: " << robots[i].getX() << " Y: "<<robots[i].getY() << endl;
            //cout << "\nPlayer: " << player.getState() << " X: " << player.getX() << " Y: "<<player.getY() << endl;
            cout << "\nObject in current position: "<< maze.getObjAt(r.getPosition()) << endl;
            //draw.drawMaze(maze.getBoard());

            if (r.getX() == player.getX() && r.getY() == player.getY())
            {
                cout << "got here3\n";
                maze.setObjAt(prevY,prevX,LIVEROBOT);
                maze.setObjAt(r.getPosition(),DEADHUMAN);
                player.killObj();
                cout << "got here2\n";
            }
            else if(maze.getObjAt(r.getPosition()) == DEADROBOT){
                cout << "got here1\n";
                r.killObj();
                continue;
            }

            cout << "\nbefore move\n";

            r.moveRobot(player.getPosition());
            newPos = maze.getObjAt(r.getPosition());
            printRobotsTester();

            cout << "\nObject in position after moveRobot: "<< maze.getObjAt(r.getPosition()) << endl;
            cout << "\nafter mov" << newPos <<"e\n";
            
            if (newPos == SPACEBAR)
            {
                cout << "got here4\n";
                maze.setObjAt(prevY,prevX, ' ');
                cout << "got here4.1\n";
                maze.setObjAt(r.getPosition(), LIVEROBOT);
                cout << "got here4.2\n";
            }
            else if (newPos == LIVEROBOT || newPos == DEADROBOT)
            {
                cout << "got here5\n";
                maze.setObjAt(r.getPosition(),DEADROBOT);
                maze.setObjAt(prevY,prevX,SPACEBAR);
                r.killObj();
            }
            else if (r.getPosition() == player.getPosition())
            {
                cout << "got here6\n";
                maze.setObjAt(prevY,prevX,LIVEROBOT);
                maze.setObjAt(r.getPosition(),DEADHUMAN);
                player.killObj();
            }
            else if (maze.hasPost(r.getPosition()) == '1')
            {
                cout << "got here7\n";
                maze.setObjAt(prevY,prevX,SPACEBAR);
                maze.setObjAt(r.getPosition(),DEADROBOT);
                r.killObj();
            }
            else if (maze.hasPost(r.getPosition()) == '2'){
                cout << "got here8\n";
                maze.setObjAt(prevY,prevX,DEADROBOT);
                r.setX(prevX);
                r.setY(prevY);
                r.killObj();
            }
            //draw.drawMaze(maze.getBoard());
            //cout << robots[i].getState() << " X: " << robots[i].getX() << " Y: "<<robots[i].getY() << endl;
            //cout << "\nObject in final position: "<< maze.getObjAt(robots[i].getPosition()) << endl;
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
                    Robot r1 = Robot(j,i);
                    robots.push_back(r1);
                }
                else if (line[j] == DEADROBOT)
                {
                    Robot r1 = Robot(j,i);
                    r1.killObj();
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
            break;
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
        cout << "\nFinished moving player\n";
        attackRobot();
        break;
    }
}

char Game::checkPlayerCollision()
{
    
    if (maze.getObjAt(player.getPosition()) == LIVEHUMAN)
    {
        cout << "\nShould print this\n";
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
        cout << "\nShould print this\n";
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
    for(unsigned int i = 0; i < robots.size(); i++){
        cout << "\nId: " << robots[i].getId() << " State: " << robots[i].getState() << " X:"<< robots[i].getX() << " Y: " <<robots[i].getY();
        cout << "\n";
    }
}