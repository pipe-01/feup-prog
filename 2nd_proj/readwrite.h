//T09_G01

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <sys/stat.h>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include "constants.h"

using namespace std;

class Score{
private:    
    string name;
    unsigned time;
public:
    /**
     * @brief Construct a new Score object
     * 
     * @param name 
     * @param time 
     */
    Score(string name, unsigned time){
        this->name = name;
        this->time = time;
    };
    /**
     * @brief Get the Time object
     * 
     * @return unsigned 
     */
    unsigned getTime(){
        return this->time;
    }
    /**
     * @brief Get the Name object
     * 
     * @return string 
     */
    string getName(){
        return name;
    }
    /**
     * @brief Set the Name object
     * 
     * @param name 
     */
    void setName(string name){
        this->name = name;
    }
    /**
     * @brief Set the Time object
     * 
     * @param time 
     */
    void setTime(unsigned time){
        this->time = time;
    }
};

bool fileExists(const string &file_name);
void writeResults(string writeName,const unsigned time);