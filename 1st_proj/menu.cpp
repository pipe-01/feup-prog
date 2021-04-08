#include "constants.cpp"

int draw_menu(bool &rules, bool &play, bool &exits){
    int cmenu;


    cout << "-----------------ROBOTS GAME-----------------" << endl;
    cout << "                 1) Rules                 " << endl;
    cout << "                 2) Play                 " << endl;
    cout << "                 0) Exit                 " << endl;


     while(1){
        cin >> cmenu;

        if(cin.fail()){

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You have entered an invalid input" << endl;

            if(cin.eof()){
                exit(0);
            }

        } else if( cmenu == 1){
            rules = true;
            break;

        } else if(cmenu == 2){
            play = true;
            break;

        } else if( cmenu == 0){
            exits = true;
            break;
        }
        else{
            cout << "Enter a valid number! (0,1,2)" << endl;
        }
    }
    return 0;
}