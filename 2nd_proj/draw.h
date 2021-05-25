//T09_G01

#include <iostream>
#include <limits>
#include <vector>
#include "constants.h"

using namespace std;
class Menu{
    private:
        bool menu;
        bool rules;
        bool play;
        bool winners;
        bool exit;

    public:
        Menu(bool rule, bool playgame, bool win, bool exits){
            menu = true;
            rules = rule;
            play = playgame;
            winners = win;
            exit = exits;
        }
        void printMenuBanner();
        void wait();
        void printRules();
        void printDeadRobotCollision();
        void printExit();
        void printInvalidChar();
        void printRobotVictory();
        void printHumanVictory();
        int draw_menu();
        void drawMaze(vector<vector<char>> tiles);
        void printBeginGame();
        bool checkBuffer();
        void setRules(bool sentence);
        void setPlay(bool sentence);
        void setExit(bool sentence);
        void setWinners(bool sentence);
        bool getState();
        bool getRules();
        bool getPlay();
        bool getWinners();
        bool getExit();
        void setState(bool sentence);

};