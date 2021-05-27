#include "txtread.h"

void Txtread::printFile(){
    string line;
    ifstream file(fileName);
    while(getline(file,line)){
        cout << line << "\n";
    }
}

void Txtread::clearScreen(){
    cout << "\033[2J\033[1;1H";
}