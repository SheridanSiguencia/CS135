//indent.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 7B

    
Write a new program indent.cpp that enhances
the program from the previous task. As it reads
the input line by line, it should also count the
number of open and closed { } in it, and keep track
of how many blocks is currently open at the beginning
of each line.

*/

#include <iostream> 
#include <cctype>
#include <string>
using namespace std;

string removeLeadingSpaces(string line);
int countChar(string line, char c);


int main()
{
    string line;
    int countTab = 0;
    //reads lines of file one by one
    while(getline(cin, line))
    {   
        string tab = "";
        string newline = removeLeadingSpaces(line);
        
        int start=0; //counts '}' starts

        if (newline[0] == '}')
        {
            start += 1;
        } else {
            start =0;
        }
        for (int i = 0; i < (countTab - start); i++)
        {
            tab += "\t";

        }

         
        
        
        cout <<  tab << newline << endl;

        countTab += countChar(newline, '{') - countChar(newline, '}');
    }

    return 0;
}


int countChar(string line, char c)
{   
    int counter =0;

    for (int i = 0; i < line.size(); i++)
    {
        if (line[i]== c)
            counter ++;
    }

    return counter;
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
