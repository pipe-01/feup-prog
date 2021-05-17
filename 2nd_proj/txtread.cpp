#include "txtread.h"

void Txtread::printFile(){
    string line;
    ifstream file(fileName);
    while(getline(file,line)){
        cout << line << "\n";
    }
}