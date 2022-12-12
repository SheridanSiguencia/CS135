//Lab_Quiz2.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab Quiz 2

write a function Lab quiz 02 - Substring Pyramid

enter a string (may contain spaces), print one letter
in the first line, then add one more letter until all
letters are displayed. Then decrease one letter one
line a time until no more letter displayed.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;

    cout << "Enter a string: ";
    getline (cin, word);

    cout << "Pyramid: " << endl;

    for (int i = 1; i <= word.size(); i++)
        cout << word.substr(0, i) << endl;

    for (int i = word.size() - 1; i> 0; i--)
        cout << word.substr(0, i) << endl;
    
    return 0;
}