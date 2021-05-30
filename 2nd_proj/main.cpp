//T09_G01

#include <iostream>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "readwrite.h"
#include "constants.h"
#include "game.h"
#include "menu.h"

using namespace std;


int main()
{
    Menu menu(0,0,0,0);
    string writeName, playerName;
    bool win;
    while (menu.getState())
    {
        menu.draw_menu();
        if (menu.getPlay())
        {
            menu.setPlay(false);
            menu.printBeginGame();

            if(!menu.readGame()){
                continue;
            }
            //Create game and open file
            Game game(menu.getMazeFile());
            game.readFile();
            //Play game
            auto start = chrono::steady_clock::now();
            win = game.play();
            auto end = chrono::steady_clock::now();

            if (win){
                menu.printHumanVictory();
                menu.wait();
                writeResults(menu.getWinnersFile(), chrono::duration_cast<chrono::seconds>(end - start).count());
            }
            else{
                menu.printRobotVictory();
                menu.wait();
            }

        }

        else if (menu.getRules())
        {
            cout << "\033[2J\033[1;1H";
            menu.printFile(RULES);
            menu.wait();
            menu.setRules(false);
        }

        else if(menu.getWinners()){
            cout << "\033[2J\033[1;1H";
            menu.printWinnersBanner();
            menu.printFile(menu.getWinnersFile());
            menu.wait();
            menu.setWinners(false);
        }

        else if (menu.getExit())
        {
            break;
        }
        menu.setState(true);
    }
    menu.printExit();
    return 0;
}