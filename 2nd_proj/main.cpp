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
#include "txtread.h"
#include "menu.h"

using namespace std;


int main()
{
    Menu menu = Menu(false, false, false, false);
    string writeName, playerName;
    bool win;
    Txtread rulesFile("RULES.TXT");
    while (menu.getState())
    {
        menu.draw_menu();
        if (menu.getPlay())
        {
            menu.printBeginGame();

            if(!menu.readGame()){
                continue;
            }

            Game game(menu.getMazeFile());

            auto start = chrono::steady_clock::now();
            win = game.play();
            auto end = chrono::steady_clock::now();
            

            if (win){
                writeResults(writeName, chrono::duration_cast<chrono::seconds>(end - start).count());
            }
        }

        else if (menu.getRules())
        {
            rulesFile.printFile();
            menu.wait();
            menu.setRules(false);
        }

        else if(menu.getWinners()){
            printf("Mostrar winners\n");
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