//T09_G01

#include "draw.h"

bool Menu::checkBuffer(){
    bool clean = true;
    char c;
    while (std::cin.get(c) && '\n' != c) {
        if (!std::isspace(c)) {
            clean = false;
        }
    }
    return clean;
}

void Menu::printMenuBanner()
{
    cout << "                   ___       __        __    _____              \n"
            "                  / _ \\___  / /  ___  / /_  / ___/__ ___ _  ___ \n"
            "                 / , _/ _ \\/ _ \\/ _ \\/ __/ / (_ / _ `/  ' \\/ -_)\n"
            "                /_/|_|\\___/_.__/\\___/\\__/  \\___/\\_,_/_/_/_/\\__/ \n"
            "                                                                "
         << endl;
    cout << " ___    ___      _        \n"
            "/ \\ \\  | _ \\_  _| |___ ___\n"
            "| || | |   / || | / -_|_-<\n"
            "|_|| | |_|_\\\\_,_|_\\___/__/\n"
            "  /_/  "
         << endl;
    cout << " _____    ___ _           \n"
            "|_  ) \\  | _ \\ |__ _ _  _ \n"
            " / / | | |  _/ / _` | || |\n"
            "/___|| | |_| |_\\__,_|\\_, |\n"
            "    /_/              |__/ "
         << endl;
    cout << "  ____    ___     _ _   \n"
            " /  \\ \\  | __|_ _(_) |_ \n"
            "| () | | | _|\\ \\ / |  _|\n"
            " \\__/| | |___/_\\_\\_|\\__|\n"
            "    /_/ "
         << endl;
}

void Menu::wait()
{
    do 
    {
        cout << "\t\nPress enter to continue...";
    } while (cin.get() != '\n');
    
}

void Draw::printDeadRobotCollision()
{
    cout << "  ___     _ _ _    _                           _         _   \n"
            " / __|___| | (_)__(_)___ _ _    __ _ __ _ __ _(_)_ _  __| |_ \n"
            "| (__/ _ \\ | | (_-< / _ \\ ' \\  / _` / _` / _` | | ' \\(_-<  _|\n"
            " \\___\\___/_|_|_/__/_\\___/_||_| \\__,_\\__, \\__,_|_|_||_/__/\\__|\n"
            "                                    |___/                    \n"
            "    _             _           _         _       _            \n"
            " __| |___ __ _ __| |  _ _ ___| |__  ___| |_    | |_ _ _ _  _ \n"
            "/ _` / -_) _` / _` | | '_/ _ \\ '_ \\/ _ \\  _|_  |  _| '_| || |\n"
            "\\__,_\\___\\__,_\\__,_| |_| \\___/_.__/\\___/\\__( )  \\__|_|  \\_, |\n"
            "                                           |/           |__/ \n"
            "                _      \n"
            " __ _ __ _ __ _(_)_ _  \n"
            "/ _` / _` / _` | | ' \\ \n"
            "\\__,_\\__, \\__,_|_|_||_|\n"
            "     |___/            "
         << endl;  
}

void Menu::printExit()
{

    //clear terminal
    cout << "\033[2J\033[1;1H";
    cout << " ____                                  _       _            _ \n"
            "/ ___|  ___  ___   _   _  ___  _   _  | | __ _| |_ ___ _ __| |\n"
            "\\___ \\ / _ \\/ _ \\ | | | |/ _ \\| | | | | |/ _` | __/ _ \\ '__| |\n"
            " ___) |  __/  __/ | |_| | (_) | |_| | | | (_| | ||  __/ |  |_|\n"
            "|____/ \\___|\\___|  \\__, |\\___/ \\__,_| |_|\\__,_|\\__\\___|_|  (_)\n"
            "                   |___/                                      "
         << endl;
}

void Menu::printInvalidChar()
{
    cout << " ___     _                             _ _    _   _                _   _ \n"
            "| __|_ _| |_ ___ _ _   __ _  __ ____ _| (_)__| | (_)_ _  _ __ _  _| |_| |\n"
            "| _|| ' \\  _/ -_) '_| / _` | \\ V / _` | | / _` | | | ' \\| '_ \\ || |  _|_|\n"
            "|___|_||_\\__\\___|_|   \\__,_|  \\_/\\__,_|_|_\\__,_| |_|_||_| .__/\\_,_|\\__(_)\n"
            "                                                        |_|              "
         << endl;
}

void Draw::printInvalidChar()
{
    cout << " ___     _                             _ _    _   _                _   _ \n"
            "| __|_ _| |_ ___ _ _   __ _  __ ____ _| (_)__| | (_)_ _  _ __ _  _| |_| |\n"
            "| _|| ' \\  _/ -_) '_| / _` | \\ V / _` | | / _` | | | ' \\| '_ \\ || |  _|_|\n"
            "|___|_||_\\__\\___|_|   \\__,_|  \\_/\\__,_|_|_\\__,_| |_|_||_| .__/\\_,_|\\__(_)\n"
            "                                                        |_|              "
         << endl;
}

void Menu::printRobotVictory()
{
    cout << " ___     _         _        _                  __      __        \n"
            "| _ \\___| |__  ___| |_ ___ | |_  __ ___ _____  \\ \\    / /__ _ _  \n"
            "|   / _ \\ '_ \\/ _ \\  _(_-< | ' \\/ _` \\ V / -_)  \\ \\/\\/ / _ \\ ' \\ \n"
            "|_|_\\___/_.__/\\___/\\__/__/ |_||_\\__,_|\\_/\\___|   \\_/\\_/\\___/_||_|\n"
            "                                                                 ";     
}

void Menu::printHumanVictory()
{
    cout << "__   __          _                  __      __        \n"
            "\\ \\ / /__ _  _  | |_  __ ___ _____  \\ \\    / /__ _ _  \n"
            " \\ V / _ \\ || | | ' \\/ _` \\ V / -_)  \\ \\/\\/ / _ \\ ' \\ \n"
            "  |_|\\___/\\_,_| |_||_\\__,_|\\_/\\___|   \\_/\\_/\\___/_||_|\n"
            "                                                      "<< endl;     
}
void Menu::draw_menu()
{
    cout << "\033[2J\033[1;1H";
    unsigned int cmenu;
    bool clean;

    this->printMenuBanner();
    while (1)
    {
        cin >> cmenu;
        clean = this->checkBuffer();

        if(clean){
            if (cmenu == ONE)
            {
                this->rules = true;
                break;
            }
            else if (cmenu == TWO)
            {
                this->play = true;
                break;
            }
            else if (cmenu == ZERO)
            {
                this->leave = true;
                break;
            }
        }
        cerr << "\nEnter a valid input! (0,1,2): " ;
    }
}

void Draw::drawMaze(std::vector<std::vector<char>> tiles)
{
    for (size_t i = 0; i < tiles.size(); i++)
    {
        for (size_t j = 0; j < tiles[i].size(); j++)
        {
            cout << tiles[i][j];
        }
        cout << endl;
    }
}

void Menu::printBeginGame()
{
    cout << "\033[2J\033[1;1H";
    cout << "      __       __    __  __         _____                 __            _    \n"
            "     / /  ___ / /_  / /_/ /  ___   / ___/__ ___ _  ___   / /  ___ ___ _(_)__ \n"
            "    / /__/ -_) __/ / __/ _ \\/ -_) / (_ / _ `/  ' \\/ -_) / _ \\/ -_) _ `/ / _ \\\n"
            "   /____/\\__/\\__/  \\__/_//_/\\__/  \\___/\\_,_/_/_/_/\\__/ /_.__/\\__/\\_, /_/_//_/\n"
            "                                                                /___/        "
         << endl;
}

void Menu::setRules(bool state){
    this->rules = false;
}

void Menu::setPlay(bool state){
    this->play = false;
}
void Menu::setExit(bool state){
    this->leave = false;
}
void Menu::setWinners(bool state){
    this->winners = false;
}

void Menu::setState(bool state){
    this->menu = state;
}

bool Menu::getState(){
    return this->menu;
}

bool Menu::getRules(){
    return this->rules;
}
bool Menu::getPlay(){
    return this->play;
}
bool Menu::getWinners(){
    return this->winners;
}
bool Menu::getExit(){
    return this->leave;
}
string Menu::getMazeFile(){
    return mazeFile;
}
string Menu::getWinnersFile(){
    return winnersFile;
}

bool Menu::readGame()
{
    unsigned int mazeNum;
    string mazeNumString, auxFileName;

    //clear terminal
    cout << "\033[2J\033[1;1H";

    while (1)
    {
        cout << "Enter maze number: ";
        cin >> mazeNumString;

        mazeNum = stoi(mazeNumString);
        auxFileName = "MAZE_";

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
        else if (mazeNum > 0 && mazeNum <= 99)
        {

            if(mazeNum<10)
    	        mazeNumString = "0" + mazeNumString;
            winnersFile = auxFileName + mazeNumString + "_WINNERS.TXT";
            mazeFile = auxFileName  + mazeNumString + ".TXT";

            if (fileExists(mazeFile))
            {
                cout << "File exists" << endl;
                menu = false;
                return true;
            }
            else
            {
                cout << "File doesn't exist" << endl;
                continue;
            }
        }
        else if (mazeNum == 0)
        {
            menu = true;
            return false;
        }
        else
        {
            cout << "Enter a valid number between 0 and 99" << endl;
        }
    }
}