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