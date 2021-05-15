#include "Txtread.h"

void Txtread::printFile(){
    string line;
    ifstream file(fileName);
    while(!file.eof() && !file.fail()){
        file >> line;
        cout << line;
    }
}