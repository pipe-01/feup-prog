#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include<ios> 
#include <algorithm>
#include <limits>
#include <curses.h>
#include <stdio.h>
#include <fstream>
#include <string>


using namespace std;


void draw_menu(){
    cout << "-----------------ROBOTS GAME-----------------" << endl;
    cout << "                 1) Rules                 " << endl;
    cout << "                 2) Play                 " << endl;
    cout << "                 0) Exit                 " << endl;
}

bool file_exists(string file_name){
    ifstream file;
    file.open(file_name);

    if(file){
        return true;
    }
    return false;
}

void create_file(string file_name){

    ofstream file;
    file.open(file_name, ios::out);
    if(!file){
        cout << "Error to open file!" << endl;
        return ;
    }
    file.close();
}

int play_game(){
    int maze_value;
    string file_name;
    string aux;

    //clear terminal
    cout << "\033[2J\033[1;1H";

    while(1){

        file_name = "MAZE_";

        cout << "Enter the maze size: ";
        cin >> maze_value;
        
        if(cin.fail()){

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You have entered wrong input" << endl;

            if(cin.eof()){
                exit(0);
            }

        } else if(maze_value > 0 && maze_value <= 9){

            aux = to_string(maze_value);
            file_name = file_name + "0" + aux + ".TXT";

            if(!file_exists(file_name)){
                create_file(file_name);
                file_name.clear();
            } else {

                cout << "Maze already exists" << endl;
                break;
            }

        } else if(maze_value >= 10 && maze_value <= 99){

            aux = to_string(maze_value);
            file_name = file_name + aux + ".TXT";

            if(!file_exists(file_name)){
                create_file(file_name);
                file_name.clear();
            } else {

                cout << "Maze already exists" << endl;
                break;
            }

        } else if(maze_value == 0){
            //clear terminal
            cout << "\033[2J\033[1;1H";
            return 0;

        }
    }
    return 1;
}

int main(){
    int cmenu;

    draw_menu();


    while(1){
        cin >> cmenu;

        if(cin.fail()){

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You have entered wrong input" << endl;

            if(cin.eof()){
                exit(0);
            }

        } else if( cmenu == 1){
            cout << "RULES" << endl;
            break;

        } else if(cmenu == 2){

            int aux = play_game();

            if(aux == 0){
                draw_menu();
                cout << "TEST";
            } else if(aux == 1){
                cout << " MAZE FILE FOUND!" << endl;
                break;
            }

        } else if( cmenu == 0){
            cout << "Exit" << endl;
            exit(0);
        }
    }
        
    return 0;
}