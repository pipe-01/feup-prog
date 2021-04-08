#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include<ios> 
#include <algorithm>
#include <limits>
#include <stdio.h>
#include <fstream>
#include <string>


using namespace std;



int draw_menu(bool &rules, bool &play, bool &exits){
    int cmenu;


    cout << "-----------------ROBOTS GAME-----------------" << endl;
    cout << "                 1) Rules                 " << endl;
    cout << "                 2) Play                 " << endl;
    cout << "                 0) Exit                 " << endl;


     while(1){
        cin >> cmenu;

        if(cin.fail()){

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You have entered an invalid input" << endl;

            if(cin.eof()){
                exit(0);
            }

        } else if( cmenu == 1){
            rules = true;
            break;

        } else if(cmenu == 2){
            play = true;
            break;

        } else if( cmenu == 0){
            exits = true;
            break;
        }
        else{
            cout << "Enter a valid number! (0,1,2)" << endl;
        }
    }
    return 0;
}

//verifies if a file exists
bool file_exists(const string &file_name){
    ifstream file (file_name);

    if(!file){
        return false;
    } else return true;

}

//create file with name file_name
void create_file(string file_name){

    ofstream file;
    file.open(file_name, ios::out);
    if(!file){
        cout << "Error to open file!" << endl;
        return ;
    }
    file.close();
}



void read_file(string &file_name){
    int lines, columns;
    fstream file;
    file.open(file_name, ios::in);

    if(!file){
        cout << "Can't open file" << endl;
    } else{
        string line;
        getline(file, line);
        for (size_t i = 0; i < line.size(); i++){
            cout << line[i] << " - " << (int)line[i] << endl;
        }        
    }
    file.close();
}


int play_game(bool &menu){
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

            if(file_exists(file_name)){
                cout << "File exists" << endl;
                read_file(file_name);
                file_name.clear();
                menu = false;
                break;
            } else {
                cout << "File doesn't exist" << endl;
            }

        } else if(maze_value >= 10 && maze_value <= 99){

            aux = to_string(maze_value);
            file_name = file_name + aux + ".TXT";

            if(file_exists(file_name)){
                cout << "File exists" << endl;
                read_file(file_name);
                file_name.clear();
                menu = false;
                break;
            } else {
                cout << "File doesn't exist" << endl;
            }

        } else if(maze_value == 0){
            //clear terminal
            cout << "\033[2J\033[1;1H";
            menu = true;
            return 0;

        } else{
            cout << "Enter a valid number between 0 and 99" << endl;
        }
    }
    return -1;
}

int main(){

    bool menu = true, play = false, rules = false, exits = false;


    while(menu){

        draw_menu(rules, play, exits);

        if(play){
            cout << "Playing game" << endl;
            play_game(menu);
            play = false;
        }
        
        if(rules){
            cout << "RULES" << endl;
            rules = false;
            menu = false;
        }

        if(exits){
            cout << "exit" << endl;
            exits = false;
            menu = false;
            exit(0);
        }

    }
    return 0;
}