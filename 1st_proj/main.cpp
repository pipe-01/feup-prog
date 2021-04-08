#include "game.cpp"
#include "menu.cpp"
#include "constants.cpp"
#include "tile.h"

using namespace std;

int main(){

    bool menu = true, play = false, rules = false, exits = false;


    while(menu){

        draw_menu(rules, play, exits);

        if(play){
            cout << "Playing game" << endl;
            read_game(menu);
            play = false;
        }
        
        if(rules){ //Por fazer
            cout << "RULES" << endl;
            rules = false;
            sleep(10);
        }

        if(exits){
            cout << "exit" << endl;
            exits = false;
            menu = false;
            cout << "Banner qualquer"; //Por fazer
            exit(0);
        }

    }
    return 0;
}