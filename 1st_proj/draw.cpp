//T09_G01

#include <vector>
#include "draw.h"

bool checkBuffer(){
    bool clean = true;
    char c;
    while (std::cin.get(c) && '\n' != c) {
        if (!std::isspace(c)) {
            clean = false;
        }
    }
    return clean;
}

void printMenuBanner()
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

void wait()
{
    do 
    {
        cout << "\t\nPress enter to continue...";
    } while (cin.get() != '\n');
    
}

void printRules()
{

    //clear terminal
    cout << "\033[2J\033[1;1H";

    cout << "                                ___       __      \n"
            "                               / _ \\__ __/ /__ ___\n"
            "                              / , _/ // / / -_|_-<\n"
            "                             /_/|_|\\_,_/_/\\__/___/\n"
            "                                                  "
         << endl;
    cout << "H = human, R = Robot, * = Fence/Post\n"
            "1) Main Goal of the Game: Survive the Robots & Electrical Posts/Fences\n"
            "2) Win is achieved if no robots are alive\n"
            "3) Dead robots remain in their last position (thus can not move through them)\n"
            "4) For every move, robots move one tile closer to your character (H)\n"
            "5) Death can be by collision with robots or fences/posts\n"
            "6) Robots also die from collisions between each other (only one robot is placed in the place of death)\n"
            "7) Times are recorded and stored in a text file\n"
            "Controls are as follows: \n"
            "\tA/a = Left\n"
            "\tW/w = Up\n"
            "\tD/d = Right\n"
            "\tX/x = Down\n"
            "\tS/s = No movement\n"
            "\tQ/q = Up-left\n"
            "\tE/e = Up-right\n"
            "\tZ/z = Down-left\n"
            "\tC/c = Down-right\n"
            "\t0 = Exit Game\n";
    wait();
    cout << "\033[2J\033[1;1H";
}

void printDeadRobotCollision()
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

void printExit()
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

void printInvalidChar()
{
    cout << " ___     _                             _ _    _   _                _   _ \n"
            "| __|_ _| |_ ___ _ _   __ _  __ ____ _| (_)__| | (_)_ _  _ __ _  _| |_| |\n"
            "| _|| ' \\  _/ -_) '_| / _` | \\ V / _` | | / _` | | | ' \\| '_ \\ || |  _|_|\n"
            "|___|_||_\\__\\___|_|   \\__,_|  \\_/\\__,_|_|_\\__,_| |_|_||_| .__/\\_,_|\\__(_)\n"
            "                                                        |_|              "
         << endl;
}

void printRobotVictory()
{
    cout << " ___     _         _        _                  __      __        \n"
            "| _ \\___| |__  ___| |_ ___ | |_  __ ___ _____  \\ \\    / /__ _ _  \n"
            "|   / _ \\ '_ \\/ _ \\  _(_-< | ' \\/ _` \\ V / -_)  \\ \\/\\/ / _ \\ ' \\ \n"
            "|_|_\\___/_.__/\\___/\\__/__/ |_||_\\__,_|\\_/\\___|   \\_/\\_/\\___/_||_|\n"
            "                                                                 ";
}

void printHumanVictory()
{
    cout << "__   __          _                  __      __        \n"
            "\\ \\ / /__ _  _  | |_  __ ___ _____  \\ \\    / /__ _ _  \n"
            " \\ V / _ \\ || | | ' \\/ _` \\ V / -_)  \\ \\/\\/ / _ \\ ' \\ \n"
            "  |_|\\___/\\_,_| |_||_\\__,_|\\_/\\___|   \\_/\\_/\\___/_||_|\n"
            "                                                      "<< endl;
}
int draw_menu(bool &rules, bool &play, bool &exits)
{
    cout << "\033[2J\033[1;1H";
    unsigned int cmenu;
    bool clean;

    printMenuBanner();
    while (1)
    {
        cin >> cmenu;
        clean = checkBuffer();

        if(clean){
            if (cmenu == ONE)
            {
                rules = true;
                break;
            }
            else if (cmenu == TWO)
            {
                play = true;
                break;
            }
            else if (cmenu == ZERO)
            {
                exits = true;
                break;
            }
        }
        cerr << "\nEnter a valid input! (0,1,2): " ;
    }
    return 0;
}

void drawMaze(std::vector<std::vector<char>> tiles)
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

void printBeginGame()
{
    cout << "\033[2J\033[1;1H";
    cout << "      __       __    __  __         _____                 __            _    \n"
            "     / /  ___ / /_  / /_/ /  ___   / ___/__ ___ _  ___   / /  ___ ___ _(_)__ \n"
            "    / /__/ -_) __/ / __/ _ \\/ -_) / (_ / _ `/  ' \\/ -_) / _ \\/ -_) _ `/ / _ \\\n"
            "   /____/\\__/\\__/  \\__/_//_/\\__/  \\___/\\_,_/_/_/_/\\__/ /_.__/\\__/\\_, /_/_//_/\n"
            "                                                                /___/        "
         << endl;
}