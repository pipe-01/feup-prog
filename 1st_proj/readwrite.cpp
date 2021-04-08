#include "constants.cpp"
#include "tile.h"
#include <vector>
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
    int rows, columns;
    char useless;
    ifstream file(file_name);

    if(!file){
        cout << "Can't open file" << endl;
    } else{
        vector<Tile> robots
        vector<vector<Tile>> tiles;
        string line;
        file >> rows >> useless >> columns;
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
            {
                char now;
                file.get(now);
                tiles[i][j] = Tile(now,i,j);
                if(now == LIVEROBOT){

                }
            }
            
        }
        
           
    }
    file.close();

}
