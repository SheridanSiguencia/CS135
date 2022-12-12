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
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

string removeLeadingSpaces(string line);

int main()
{
    fstream inFile;
    // open the file stream
    inFile.open("bad_code.cpp");
    // check if opening a file failed
    if (inFile.fail()) 
    {
        cerr << "Error opeing a file" << endl;
        inFile.close();
        exit(1);
    }
    
    string newL;

    string line;

    while (getline(inFile, line))
    {
        newL = removeLeadingSpaces(line);
    }
    // close the file stream
    inFile.close();


    return 0;
}

string removeLeadingSpaces(string line)
{
    string newline;
    
    for (int i= 0; i< line.size(); i++)
    {   
        char c = line[i];

        int count=0;
        //meaning do this if it is a space
        if(isspace(c)==0)
        {   
            count = 1;
        }

        if (count >0)
            newline += c;

    }
    
    return newline;

}
