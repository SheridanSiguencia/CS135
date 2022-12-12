//unindent.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 7A

Before we make a program that indents source
 code files, let’s make a program that unindents them.

Write a program unindent.cpp that reads input from 
cin and prints out each input line with leading spaces
removed. Start by writing a function

string removeLeadingSpaces(string line);
that takes one line of code as input and
returns its copy without leading spaces and tabs:

removeLeadingSpaces("       int x = 1;  ") == "int x = 1;  "
Make use of the function isspace defined in <cctype> to check 
if a character is a whitespace. Your function should probably 
iterate over the input string, skip all spaces, and after it 
finds the first non-space character, start accumulating the 
characters into a new string, which will be returned.

Write a program unindent.cpp that reads input from cin and 
prints out each input line with leading spaces removed.

*/

#include <iostream> 
#include <cctype>
#include <string>
using namespace std;

string removeLeadingSpaces(string line);

int main()
{
    string line;
    //reads lines of file one by one
    while(getline(cin, line))
    {
        string newline = removeLeadingSpaces(line);
        cout << newline << endl;
    }
    return 0;
}

string removeLeadingSpaces(string line)
{
    int i;
    //read the line inputed
    for (i=0; i < line.size(); i++)
    {
        //if not a space break out of loop and return the rest of the line 
        if (!isspace(line[i]))
            break;
    }
    
    string newL = line.substr(i);

    return newL;  
}
