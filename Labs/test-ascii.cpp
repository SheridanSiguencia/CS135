//test-ascii.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 6A


Write a program test-ascii.cpp that asks the
user to input a line of text (which may possibly
include spaces). The program should report all
characters from the input line together with
their ASCII codes.

Make sure to print exactly one space between the
character and it’s code.
*/

#include <iostream>
#include <cctype>
using namespace std;

int main ()
{
    string str;
    cout << "Enter message to encode: ";
    getline(cin, str);

    char c;
    
    for (int i=0; i < str.length(); i++)
    {
        c= str[i];

        cout << c << " " <<int(c) << endl;
    }
    
    return 0;

}