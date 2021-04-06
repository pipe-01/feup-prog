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



// void setcolor(unsigned int color){
//     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
// }

void draw_menu(){
    /*setcolor(9);*/ cout << "                 ROBOTS GAME                 ";/* setcolor(7); */cout << endl;
    cout << "                 1) Rules                 " << endl;
    cout << "                 2) Play                 " << endl;
    cout << "                 0) Exit                 " << endl;
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
        
        if(maze_value > 0 && maze_value <= 9){
            aux = to_string(maze_value);
            file_name = file_name + "0" + aux + ".TXT";
        }
        else if(maze_value >= 10 && maze_value <= 99){
            aux = to_string(maze_value);
            file_name = file_name + aux + ".TXT";
        }
        else if(maze_value == 0){
            //clear terminal
            cout << "\033[2J\033[1;1H";
            return 0;
        }
        else{
            cout << "Enter a valid value (between 1 and 99)" << endl;
        }

        ofstream file;
        file.open(file_name, ios::out);
        if(!file){
            cout << "Error to open file!" << endl;
            return -1;
        }
        file.close();
        file_name.clear();
    }
    return 1;
}

int main(){
    char cmenu;

    draw_menu();

    while(1){
        cin >> cmenu;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(cmenu == '1'){
            cout << "RULES" << endl;
            break;
        }else if(cmenu == '2'){
            cout << "PLAY" << endl;
            if(play_game() == 0){
                draw_menu();
            }
            break;
        }else if(cmenu == '0'){
            cout << "EXIT" << endl;
            return 0;
        }
        else{
            cout << "Enter a valid character please!" << endl;
        }
    }
        
    return 0;
}