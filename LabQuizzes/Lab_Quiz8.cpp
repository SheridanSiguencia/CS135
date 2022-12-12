//Lab_Quiz7.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab Quiz 8

Lab Quiz 08 - define the function 
`void remove_e(string & sentence)` 
Removes all `e` characters from the 
original string
*/

#include <iostream>
#include <string>

using namespace std;

void remove_e (string& s)
{   
    string temp;
    for (int i =0; i < s.size(); i++)
    {
        if(s[i] != 'e')
        {
            temp += s[i];
        } 
    }
    s= temp;
}
int main ()
{
    string str;

    cout << "Enter string: ";
    getline(cin, str);
    cout <<"Original was " << str<< endl;

    remove_e(str);

    cout <<"Remove E sentence is " << str;


}