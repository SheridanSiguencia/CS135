//File name: /Users/laptopuser/Documents/cs135_codes/projects/game1024/TestBoard.cpp
#include <iostream>
#include "Board.hpp"
using namespace std;



int main()
{
    int a = 3;
    int b= 4;
    cout << endl << "Board: \n";
    Board game(3, 4);
       //create a Board object with three rows
       //and four columns
    game.print(); //test print methd of game3

    cout << endl << "Board after randomized: \n";
    game.printR();
    return 0;
}





/*
int main()
{
    Board game(3, 3);
    //game.print();

    //coloring output in console output in c++ in linux
    //https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
    //cout << "\x1B[31mTexting\033[0m\t\t\n";
    //print out red text "Texting"

    //game.start();
    return 0;
}
*/