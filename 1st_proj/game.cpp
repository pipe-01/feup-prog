#include "constants.cpp"
#include "readwrite.cpp"
int read_game(bool &menu){
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
