#include <iostream>
#include <string>
using namespace std;

struct Person{
    string name;
    string state = "H";
    unsigned age;
};

struct Robot{
    string state = "R";
};

bool alive(Person p){
    if(p.state == "H")
        return true;
    else
        return false;
}