#include "draw.h"


void printMenuBanner(){
    cout << "                   ___       __        __    _____              \n"
            "                  / _ \\___  / /  ___  / /_  / ___/__ ___ _  ___ \n"
            "                 / , _/ _ \\/ _ \\/ _ \\/ __/ / (_ / _ `/  ' \\/ -_)\n"
            "                /_/|_|\\___/_.__/\\___/\\__/  \\___/\\_,_/_/_/_/\\__/ \n"
            "                                                                " << endl;
    cout << " ___    ___      _        \n"
            "/ \\ \\  | _ \\_  _| |___ ___\n"
            "| || | |   / || | / -_|_-<\n"
            "|_|| | |_|_\\\\_,_|_\\___/__/\n"
            "  /_/  " << endl;
    cout << " _____    ___ _           \n"
            "|_  ) \\  | _ \\ |__ _ _  _ \n"
            " / / | | |  _/ / _` | || |\n"
            "/___|| | |_| |_\\__,_|\\_, |\n"
            "    /_/              |__/ " << endl;
    cout << "  ____    ___     _ _   \n"
            " /  \\ \\  | __|_ _(_) |_ \n"
            "| () | | | _|\\ \\ / |  _|\n"
            " \\__/| | |___/_\\_\\_|\\__|\n"
            "    /_/ " << endl;
}

void wait() {
    cout << "\n\tPress ENTER key to continue....";
    getchar();
    getchar();
}


void printRules(){

    //clear terminal
    cout << "\033[2J\033[1;1H";

    char any;
    cout << "                                ___       __      \n"
            "                               / _ \\__ __/ /__ ___\n"
            "                              / , _/ // / / -_|_-<\n"
            "                             /_/|_|\\_,_/_/\\__/___/\n"
            "                                                  " << endl;
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

    //clear terminal
    cout << "\033[2J\033[1;1H";
}

void printDeadRobotCollision(){
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
            "     |___/            " << endl;
}

void printExit(){

    //clear terminal
    cout << "\033[2J\033[1;1H";

    cout << " ____                                  _       _            _ \n"
            "/ ___|  ___  ___   _   _  ___  _   _  | | __ _| |_ ___ _ __| |\n"
            "\\___ \\ / _ \\/ _ \\ | | | |/ _ \\| | | | | |/ _` | __/ _ \\ '__| |\n"
            " ___) |  __/  __/ | |_| | (_) | |_| | | | (_| | ||  __/ |  |_|\n"
            "|____/ \\___|\\___|  \\__, |\\___/ \\__,_| |_|\\__,_|\\__\\___|_|  (_)\n"
            "                   |___/                                      " << endl;
}

void printInvalidChar(){
    cout << " ___     _                             _ _    _   _                _   _ \n"
            "| __|_ _| |_ ___ _ _   __ _  __ ____ _| (_)__| | (_)_ _  _ __ _  _| |_| |\n"
            "| _|| ' \\  _/ -_) '_| / _` | \\ V / _` | | / _` | | | ' \\| '_ \\ || |  _|_|\n"
            "|___|_||_\\__\\___|_|   \\__,_|  \\_/\\__,_|_|_\\__,_| |_|_||_| .__/\\_,_|\\__(_)\n"
            "                                                        |_|              " << endl;
}
