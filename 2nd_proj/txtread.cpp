#include "txtread.h"

void Txtread::printFile(){
    string line;
    ifstream file(fileName);
    cout << WARNING;
    while(getline(file,line)){
        cout << line << "\n";
    }
    cout << NO_COLOR;
}

void Txtread::clearScreen(){
    cout << "\033[2J\033[1;1H";
}