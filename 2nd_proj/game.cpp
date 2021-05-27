#include "game.h"

Game::Game(const string& filename){
    fileName = fileName;
}

void Game::attackRobot(Robot &r)
{
    int prevX, prevY;
    char newPos;
    if (!r.getState() )
    {
        return false;
    }
    else
    {
        prevX = r.getX(), prevY = r.getY();
        if (r.getPosition() = player.getPosition())
        {
            maze.setObjAt(prevY,prevX,LIVEROBOT);
            maze.setObjAt(r.getPosition(),DEADHUMAN);
            player.killObj();
        }
        else if(maze.getObjAt(r.getPosition()) == DEADROBOT){
            r.killObj();;
            return
        }
        r.moveRobot(player.getPosition());
        newPos = maze.getObjAt(r.getPosition());

        if (newPos == SPACEBAR)
        {
            maze.setObjAt(prevY,prevX,SPACEBAR);
            maze.setObjAt(r.getPosition(),LIVEROBOT);
        }
        else if (newPos == LIVEROBOT || newPos == DEADROBOT)
        {
            maze.setObjAt(r.getPosition(),DEADROBOT);
            maze.setObjAt(prevY,prevX,SPACEBAR);
            r.killObj();
        }
        else if (r.getPosition() == player.getPosition())
        {
            maze.setObjAt(prevY,prevX,LIVEROBOT);
            maze.setObjAt(r.getPosition(),DEADHUMAN);
            player.killObj();
            printRobotVictory();
            wait();
        }
        else if (maze.hasPost(r.getPosition()) == '1')
        {
            maze.setObjAt(prevY,prevX,SPACEBAR);
            maze.setObjAt(r.getPosition(),DEADROBOT);
            r.killObj();
        }
        else if (maze.hasPost(r.getPosition()) == '2'){
            maze.setObjAt(prevY,prevX,DEADROBOT);
            r.setX(prevX);
            r.setY(prevY);
            r.killObj();
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
                    maze.addPost(Position(j,i), Post(true));
                }
                else if(line[j] == NONELECPOST){
                    maze.addPost(Position(j,i), Post(false));
                }
            }
        }
        //printRobotsPos(robots);
    }
    file.close();
}

void Game::movePlayer()
{
    int prevX = player.getX(), prevY = player.getY();
    char move, coll;

    while (1)
    {
        cout << "\nEnter movement player: ";
        cin >> move;
        if(!checkBuffer()){
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
                drawMaze(tiles);
                printInvalidChar();
                continue;
        }
        coll = checkCollision();
        if (coll == '2')
        {
            player.placeObj(tiles, prevX, prevY);
            player.gotOut();
        }
        else if (coll == '1')
        {
            printInvalidChar();
            player.setX(prevX);
            player.setY(prevY);
            break;
        }
        else if (coll == '4')
        {
            player.placeObj(tiles, prevX, prevY);
            break;
        }
        else
        {
            printRobotVictory();
            wait();
            break;
        }
        attackRobots(tiles, player,robots);
        //printRobotsPos(robots);
        break;
    }
}

char Game::checkPlayerCollision()
{
    if (tiles[getY()][getX()] == LIVEHUMAN)
    {
        return '2';
    }
    else if (tiles[getY()][getX()] != ' ')
    {
        if (tiles[getY()][getX()] == EXITDOOR)
        {
            gotOut();
            return '4';
        }
        else if (tiles[getY()][getX()] == '*' || tiles[getY()][getX()] == LIVEROBOT)
        {
            killObj();
            return '0';
        }
        else
        {
            if (tiles[getY()][getX()] == DEADROBOT || tiles[getY()][getX()] == NONELECPOST)
            {
                printDeadRobotCollision();
                return '1';
            }
            else
            {
                killObj();
                return '0';
            }
        }
    }
    else
    {
        return '2';
    }
}

void Game::placePlayer(int prevX, int prevY){

}

bool Game::fileExists(const string &file_name){
    fstream file(name);
    if (!file)
    {
        return false;
    }
    return true;
}

string Game::read_game(bool &menu, vector<vector<char>> &tiles, Player &player, vector<Robot> &robots){
    unsigned int maze_value;
    string file_name, write_name;
    string aux;

    //clear terminal
    cout << "\033[2J\033[1;1H";

    while (1)
    {
        cout << "Enter maze number: ";
        cin >> aux;

        maze_value = stoi(aux);
        file_name = "MAZE_";

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
        else if (maze_value > 0 && maze_value <= 99)
        {

            if(maze_value<10)
    	        aux = "0" + aux;
            write_name = file_name + aux + "_WINNERS.TXT";
            file_name = file_name  + aux + ".TXT";

            if (fileExists(file_name))
            {
                cout << "File exists" << endl;
                readFile();
                file_name.clear();
                menu = false;
                return write_name;
                break;
            }
            else
            {
                cout << "File doesn't exist" << endl;
                continue;
            }
        }
        else if (maze_value == 0)
        {
            player.killObj();
            menu = true;
            break;
        }
        else
        {
            cout << "Enter a valid number between 0 and 99" << endl;
        }
    }
    return " ";
}


