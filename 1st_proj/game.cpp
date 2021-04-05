#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include<ios> 
#include <algorithm>
#include <curses.h>
#include <windows.h>


using namespace std;



void setcolor(unsigned int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void draw_menu(){
    setcolor(9); cout << "                 ROBOTS GAME                 "; setcolor(7); cout << endl;
}

int main(){
    draw_menu();
    return 0;
}