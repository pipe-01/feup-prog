//T09_G01

#include "draw.h"

Menu::checkBuffer(){
    bool clean = true;
    char c;
    while (std::cin.get(c) && '\n' != c) {
        if (!std::isspace(c)) {
            clean = false;
        }
    }
    return clean;
}

Menu::printMenuBanner()
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

Menu::wait()
{
    do 
    {
        cout << "\t\nPress enter to continue...";
    } while (cin.get() != '\n');
    
}

Menu::printDeadRobotCollision()
{
    cout << GREEN;
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
    cout << NO_COLOR;     
}

Menu::printExit()
{

    //clear terminal
    cout << "\033[2J\033[1;1H";
    cout << ORANGE;
    cout << " ____                                  _       _            _ \n"
            "/ ___|  ___  ___   _   _  ___  _   _  | | __ _| |_ ___ _ __| |\n"
            "\\___ \\ / _ \\/ _ \\ | | | |/ _ \\| | | | | |/ _` | __/ _ \\ '__| |\n"
            " ___) |  __/  __/ | |_| | (_) | |_| | | | (_| | ||  __/ |  |_|\n"
            "|____/ \\___|\\___|  \\__, |\\___/ \\__,_| |_|\\__,_|\\__\\___|_|  (_)\n"
            "                   |___/                                      "
         << endl;
}

Menu::printInvalidChar()
{
    cout << " ___     _                             _ _    _   _                _   _ \n"
            "| __|_ _| |_ ___ _ _   __ _  __ ____ _| (_)__| | (_)_ _  _ __ _  _| |_| |\n"
            "| _|| ' \\  _/ -_) '_| / _` | \\ V / _` | | / _` | | | ' \\| '_ \\ || |  _|_|\n"
            "|___|_||_\\__\\___|_|   \\__,_|  \\_/\\__,_|_|_\\__,_| |_|_||_| .__/\\_,_|\\__(_)\n"
            "                                                        |_|              "
         << endl;
}

Menu::printRobotVictory()
{
    cout << WARNING;
    cout << " ___     _         _        _                  __      __        \n"
            "| _ \\___| |__  ___| |_ ___ | |_  __ ___ _____  \\ \\    / /__ _ _  \n"
            "|   / _ \\ '_ \\/ _ \\  _(_-< | ' \\/ _` \\ V / -_)  \\ \\/\\/ / _ \\ ' \\ \n"
            "|_|_\\___/_.__/\\___/\\__/__/ |_||_\\__,_|\\_/\\___|   \\_/\\_/\\___/_||_|\n"
            "                                                                 ";
    cout << NO_COLOR;        
}

Menu::printHumanVictory()
{
    cout << GREEN;
    cout << "__   __          _                  __      __        \n"
            "\\ \\ / /__ _  _  | |_  __ ___ _____  \\ \\    / /__ _ _  \n"
            " \\ V / _ \\ || | | ' \\/ _` \\ V / -_)  \\ \\/\\/ / _ \\ ' \\ \n"
            "  |_|\\___/\\_,_| |_||_\\__,_|\\_/\\___|   \\_/\\_/\\___/_||_|\n"
            "                                                      "<< endl;
    cout << NO_COLOR;        
}
int draw_menu()
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
                this->exits = true;
                break;
            }
        }
        cerr << "\nEnter a valid input! (0,1,2): " ;
    }
    return 0;
    cout << NO_COLOR;
}

Menu::drawMaze(std::vector<std::vector<char>> tiles)
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

Menu::printBeginGame()
{
    cout << "\033[2J\033[1;1H";
    cout << "      __       __    __  __         _____                 __            _    \n"
            "     / /  ___ / /_  / /_/ /  ___   / ___/__ ___ _  ___   / /  ___ ___ _(_)__ \n"
            "    / /__/ -_) __/ / __/ _ \\/ -_) / (_ / _ `/  ' \\/ -_) / _ \\/ -_) _ `/ / _ \\\n"
            "   /____/\\__/\\__/  \\__/_//_/\\__/  \\___/\\_,_/_/_/_/\\__/ /_.__/\\__/\\_, /_/_//_/\n"
            "                                                                /___/        "
         << endl;
}

Menu::setFalse(bool sentence){
    sentence = false;
}

Menu::getState(){
    return this->menu;
}

Menu::getRules(){
    return this->rules;
}
Menu::getPlay(){
    return this->play;
}
Menu::getWinners(){
    return this->winners;
}
Menu::getExit(){
    return this->exit;
}