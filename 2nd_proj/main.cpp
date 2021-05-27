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
    Menu menu(0,0,0,0);
    string writeName, playerName;
    bool win;
    Txtread rulesFile("RULES.TXT");
    while (menu.getState())
    {
        menu.draw_menu();
        if (menu.getPlay())
        {
            menu.setPlay(false);
            menu.printBeginGame();

            if(!menu.readGame()){
                cout << "menu.readGame()False";
                continue;
            }
            
            cout << "gets here\n";
            Game game(menu.getMazeFile());

            game.readFile();

            auto start = chrono::steady_clock::now();
            win = game.play();
            auto end = chrono::steady_clock::now();
            cout << "then here\n" << "Who won? = " << win << endl;

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