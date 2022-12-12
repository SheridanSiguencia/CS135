//Lab_Quiz10.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab Quiz 10


Lab Quiz 10 - Brackets 
define int unbalanced_brackets(string input), 
return the difference between open curly 
brackets and closed curly brackets. 
For example, given "{}}}", return -2.
*/

#include <iostream>

using namespace std;

int unbalanced_brackets(string input);

int main ()
{
    string str;
    cout << "Enter string with brackets ";
    cin >> str;

    int dif = unbalanced_brackets(str);

    cout << "Difference of brackets is " << dif;

    return 0;
}

int unbalanced_brackets(string input)
{
    int count=0;
    for (int i= 0; i < input.size(); i++)
    {
        if (input[i] == '{')
            count ++;
        else if (input[i] == '}')
            count --;
    }
    return count;
}