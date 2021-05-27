#include "constants.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

class Menu
{
private:
    bool menu;
    bool rules;
    bool play;
    bool winners;
    bool leave;
    std::string mazeFile;
    std::string winnersFile;
public:
    Menu(bool rule, bool playgame, bool win, bool exits)
    {
        menu = true;
        rules = rule;
        play = playgame;
        winners = win;
        leave = exits;
    }
    void printMenuBanner();
    void wait();
    void printExit();
    void printInvalidChar();
    void printRobotVictory();
    void printHumanVictory();
    void draw_menu();
    void printBeginGame();
    void printFile(string fileName);
    bool checkBuffer();
    void setRules(bool sentence);
    void setPlay(bool sentence);
    void setExit(bool sentence);
    void setWinners(bool sentence);
    bool getState();
    bool getRules();
    bool getPlay();
    bool getWinners();
    bool fileExists(const std::string &f);
    bool getExit();
    void setState(bool sentence);
    bool readGame();
    void printWinnersBanner();
    std::string getMazeFile();
    std::string getWinnersFile();

};